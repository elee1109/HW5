

#include "Graph.h"
#include "BetterPriorityQueue.h"
#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

// This file is not used for part 1


int dijkstra(const GraphNode *start, const GraphNode *end, Graph *g){
	vector<int> opitmal_ws;
	int optimalCost=0;
	DNode startNode;
	DNode next;
	next.pri= INT_MAX;
	DNode prev;
	next.pri=INT_MAX;
	BetterPriorityQueue nodeQueue;
	if(start == end) return 0;

	else{
		
		startNode.pri=0;
		startNode.node=start;
		nodeQueue.push(startNode);
		for(unsigned int i=1; i<g->Size(); i++ ){
			DNode currNode;
			currNode.node=g->NodeAt(i);
			currNode.pri=INT_MAX;
		}
		while(!nodeQueue.empty()){
			DNode currNode=nodeQueue.top();
			currNode.visited=true;
			vector<GraphEdge*> edgeList=g->GetEdges(currNode.node);
			unsigned int optimal= INT_MAX;
			for (auto& edge: edgeList){
				if(optimal>edge->weight){
					optimal=edge->weight;
				
					next.node= edge->to;
					next.pri= edge->weight;
					nodeQueue.Update(next);
				}	
			}
			nodeQueue.pop();
			optimalCost+=optimal;
			
		}
	}
	return optimalCost;
}


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
	
	
	cout << g->ToString() << endl;
	cout<< g->GraphNodeToString(g->NodeAt(1)) << endl;
	int ans = dijkstra(g->NodeAt(0), g->NodeAt(g->Order()-2), g);
	//assert(ans == 20);

	delete g;
	
	
	cout << "passed!" << endl;
	
	return ans;
}


int main(){
	
	int ans = DijkstraTest();
	Graph *g = new Graph();
	GraphNode *a=g->AddNode('a', 0);
	GraphNode *b=g->AddNode('b',0);
	//g->AddEdge(a, b, 69);
	
	//g->AddEdge(b, a, 69);
	//int ans = dijkstra(a, b, g);
	cout << "ans: "  << ans << endl;
	
	return 0;
}
