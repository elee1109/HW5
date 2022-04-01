

#include "Graph.h"
#include "BetterPriorityQueue.h"
#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

/**
 * @brief implements Dijkstra's algorithm using a for loop (to initialize the BetterPriorityQueue)
 * and a while loop (to find the shortest path to the end node)
 * program uses the Graph class and BetterPriorityQueue class, an extension of priority queue.
 * 
 * BIG O TIME COMPLEXITY: O(n) (first for loop) + O((n-1) * e) 
 * where (n-1) is the queue size since the queue size is decreasing by 1 every iteration,
 * and e is the # of edges in a given node (n). 
 * But a simplified version notation would be:
 * 			O(n) + O(n^2) 
 * 
 * @param start (type: GraphNode)
 * @param end  "
 * @param g (graph pointer object)
 * @return int (optimal cost of travesring graph to endpoint)
 */
int dijkstra(const GraphNode *start, const GraphNode *end, Graph *g){
	int optimalCost=0;
	DNode startNode;
	BetterPriorityQueue nodeQueue;
	cout << g->ToString() << endl;
	if(start == end) return 0; //edge case where start and end nodes are the same, then cost is zero (assuming that no graph is used where node edges are directed to themselves because that is dumb)
	else{
		
		startNode.pri=0;
		startNode.node=start;
		nodeQueue.push(startNode); //sets the start node with priority of 0 and pushes it to queue

		cout << nodeQueue.DNodeToString(nodeQueue.top()) << endl; //prints the start DNode

		//this for loop intializes the rest of the queue with the nodes in the current graph
		for(unsigned int i= 1; i<g->Order(); i++ ){
			DNode currNode;
			currNode.node= g->NodeAt(i);
			currNode.pri= INT_MAX; //priorities set to infinity
			nodeQueue.push(currNode);
		}

		//this while loop is where the algo does the majority of the work in regards to finding the shortest path 
		while(!nodeQueue.empty()){
			DNode currNode= nodeQueue.top();
			nodeQueue.pop();
			
			if(currNode.visited == false){
				currNode.visited= true; //sets the current node to visited so it is not checked multiple times
				
				vector<GraphEdge*> edgeList=g->GetEdges(currNode.node);
				//iterates through the list of edges if the current node has multiple edges
				for (auto& edge: edgeList){
					//accumulates new weight for given path
					int new_Weight= (edge->weight)+ currNode.pri;
					DNode next;
					//assign new weight to the node the current edge arrives at 
					next.node= edge->to;
					next.pri= new_Weight;
					nodeQueue.Update(next);
					
				} 
				//sets optimal weight to node with the lowest weight
				optimalCost=nodeQueue.top().pri;

				cout<< nodeQueue.DNodeToString(nodeQueue.top()) << endl;

				//returns the weight of the node if its the end node
				if (nodeQueue.top().node == end) return optimalCost;
				
			}
			
		}
	}
	
	return optimalCost;
}


//IMPORTANT NOTE: sorted hashmap sorts the order of the hashmpa based off the values, so when the 
//edges and their weights change in the graph hashmap, their index will also change, meaning that 
//using NodeAt during testing will lead to assertion failures becuase you believe you are indexing a certain
//node when in reality you are indexing another node. I can bring this up later during office hours or after class to clarify.
//look at "test g2" for an example of the index within the hashmap
//Please refrain from using NodeAt when testing.
int DijkstraTest(){
	cout << "Testing Dijkstra Algorithm..." << endl;
	
	// Test 1: graph from assignment
	Graph *g = new Graph();
	
	GraphNode *a = g->AddNode('1');
	GraphNode *c = g->AddNode('3');
	GraphNode *b = g->AddNode('2');

	GraphNode *d = g->AddNode('4');
	GraphNode *e = g->AddNode('5');
	GraphNode *f = g->AddNode('6');

	g->AddEdge(a, b, 7);
	g->AddEdge(b, a, 7);
	g->AddEdge(a, c, 9);
	g->AddEdge(c, a, 9);
	g->AddEdge(a, f, 14);
	g->AddEdge(f, a, 14);
	
	g->AddEdge(b, c, 10);
	g->AddEdge(c, b, 10);
	g->AddEdge(b, d, 15);
	g->AddEdge(d, b, 15);
	
	g->AddEdge(c, f, 2);
	g->AddEdge(f, c, 2);
	g->AddEdge(c, d, 11);
	g->AddEdge(d, c, 11);
	
	g->AddEdge(f, e, 9);
	g->AddEdge(e, f, 9);
	
	g->AddEdge(d, e, 6);
	g->AddEdge(e, d, 6);
	
	
	//cout << g->ToString() << endl;
	//cout<< g->GraphNodeToString(g->NodeAt(1)) << endl;
	int ans = dijkstra(g->NodeAt(0), g->NodeAt(g->Order()-2), g);
	assert(ans == 20);
	


	
	int ans2 = dijkstra(g->NodeAt(0), g->NodeAt(g->Order()-1), g);
	assert(ans2 == 11);
	int ans3 = dijkstra(g->NodeAt(0), g->NodeAt(g->Order()-4), g);
	assert(ans3== 9);

	delete g;
	//test g2
	Graph *g2= new Graph();
	a=g2->AddNode('a'); //index: 0
	b=g2->AddNode('b'); //index: 4
	c=g2->AddNode('c');//index: 2
	d=g2->AddNode('d'); //index: 1
	e=g2->AddNode('e');//index 3
	g->AddEdge(a, b, 1);
	g->AddEdge(b, a, 1);
	g->AddEdge(a, e, 15);
	g->AddEdge(e, a, 15);
	g->AddEdge(a, c, 6);
	g->AddEdge(c, a, 6);
	g->AddEdge(b, c, 7);
	g->AddEdge(c, b, 7);
	g->AddEdge(c, d, 2);
	g->AddEdge(d, c, 2);
	g->AddEdge(d, e, 2);
	g->AddEdge(e, d, 2);
	g->AddEdge(b, e, 10);
	g->AddEdge(e, b, 10);
	int ans4 = dijkstra(a, e, g2);
	assert(ans4 == 10);
	int ans5 = dijkstra(a, d, g2);
	assert(ans5 == 8);


	
	
	
	cout << "passed!" << endl;
	
	return ans;
}


int main(){
	
	int ans = DijkstraTest();
	Graph *simpleGraph = new Graph();
	GraphNode *a=simpleGraph->AddNode('a', 0);
	GraphNode *b=simpleGraph->AddNode('b',0);
	GraphNode *c=simpleGraph->AddNode('c',0);
	GraphNode *d=simpleGraph->AddNode('d',0);
	simpleGraph->AddEdge(a, b, 6);
	simpleGraph->AddEdge(b, a, 6);
	simpleGraph->AddEdge(b, c, 9);
	simpleGraph->AddEdge(c, b, 9);
	simpleGraph->AddEdge(c, d, 3);
	simpleGraph->AddEdge(d, c, 3);
	simpleGraph->AddEdge(b, d, 10);
	simpleGraph->AddEdge(d, b, 10);
	//int ans = dijkstra(a, d, simpleGraph);
	cout << "ans: "  << ans << endl;
	
	return 0;
}
