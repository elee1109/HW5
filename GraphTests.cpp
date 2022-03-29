

#include "Graph.h"
#include <iostream>
#include <cassert>
#include <iostream>

using namespace std;



void TestAddNode(){
	cout << "Testing AddNode..." << endl;
	Graph g = Graph();
	g.AddNode('a', 15);
	
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << g.ToString() << endl;
	
	assert(g.NodesToString() == "[(a:15)]");
	assert(g.ToString() == "a | \n");
	
	g.AddNode('b', 12);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;

	assert(g.NodesToString() == "[(a:15), (b:12)]");
	assert(g.ToString() == "a | \nb | \n");
	
	g.AddNode('c', 9);
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	assert(g.ToString() == "a | \nb | \nc | \n");



	
	try{
		g.AddNode('c', 12);
		assert(false);
	}
	catch( const invalid_argument& e ) {
	}
	

	
	cout << "PASSED!" << endl << endl;
}


void TestAddEdge(){
	cout << "Testing AddEdge..." << endl;
	Graph g = Graph();
	GraphNode *gn1 = g.AddNode('a', 15);
	
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << g.ToString() << endl;
	
	assert(g.NodesToString() == "[(a:15)]");
	assert(g.ToString() == "a | \n");
	
	GraphNode *gn2 = g.AddNode('b', 12);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;

	assert(g.NodesToString() == "[(a:15), (b:12)]");
	assert(g.ToString() == "a | \nb | \n");
	
	GraphNode *gn3 = g.AddNode('c', 9);
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	assert(g.ToString() == "a | \nb | \nc | \n");
	
	g.AddEdge(gn1, gn3, 2);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	assert(g.ToString() == "a | [(a:15)->(c:9) w:2]\nb | \nc | \n");
	
	g.AddEdge(gn3, gn2);
	g.AddEdge(gn1, gn2, 8);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;
	
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	assert(g.ToString() == "a | [(a:15)->(c:9) w:2], [(a:15)->(b:12) w:8]\nb | \nc | [(c:9)->(b:12) w:0]\n");
	
	cout << "PASSED!" << endl << endl;
}


void TestDestructor(){
	cout << "Testing Destructor..." << endl;
	Graph *g = new Graph();
	
	GraphNode *a = g->AddNode('a', 3);
	GraphNode *b = g->AddNode('b', 5);
	g->AddEdge(b, a, 15);
	
	delete g;
	
	
	Graph g2 = Graph();
	GraphNode *c = g2.AddNode('c', 12);
	g2.AddNode('d', 11);
	assert(c->key == 'c' && c->data == 12);
	
	
	
	cout << "NO ERRORS.  Use valgrind to check!" << endl << endl;
}


void TestGetEdges(){
	cout << "Testing GetEdges..." << endl;
	Graph g = Graph();
	GraphNode *gn1 = g.AddNode('a', 15);
	GraphNode *gn2 = g.AddNode('b', 12);
	GraphNode *gn3 = g.AddNode('c', 9);

	GraphEdge *e1 = g.AddEdge(gn1, gn3, 2);
	g.AddEdge(gn3, gn2);
	GraphEdge *e3 = g.AddEdge(gn1, gn2, 8);
	
	
	vector<GraphEdge*> edges = g.GetEdges(gn1);
	// cout << "Edges: " << vec_to_string(edges) << endl;
	vector<GraphEdge*> soln = {e1, e3};
	assert(edges == soln);
	
	cout << "PASSED!" << endl << endl;
}


void TestGetNodes(){
	cout << "Testing GetNodes..." << endl;
		
	Graph g = Graph();
	GraphNode *gn1 = g.AddNode('a', 15);
	GraphNode *gn2 = g.AddNode('b', 12);
	GraphNode *gn3 = g.AddNode('c', 9);

	
	
	vector<GraphNode*> nodes = g.GetNodes();
	// cout << "Edges: " << vec_to_string(edges) << endl;
	vector<GraphNode*> soln = {gn1, gn2, gn3};
	assert(nodes == soln);
	
	
	cout << "PASSED!" << endl << endl;
}


void TestNodeAt(){
	cout << "Testing NodeAt..." << endl;
	
	
	Graph g = Graph();
	g.AddNode('a', 15);
	GraphNode *gn2 = g.AddNode('b', 12);
	g.AddNode('c', 9);

	
	
	const GraphNode *ans = g.NodeAt(1);
	assert(ans == gn2);
	
	
	cout << "PASSED!" << endl << endl;
}


void TestSize(){
	cout << "Testing Size..." << endl;
	
	
	Graph g = Graph();
	assert(g.Size() == 0);
	assert(g.Order() == 0);
	
	GraphNode *n1 = g.AddNode('a', 15);
	GraphNode *n2 = g.AddNode('b', 12);
	g.AddNode('c', 9);

	
	assert(g.Order() == 3);
	assert(g.Size()  == 0);


	g.AddEdge(n1, n2);
	assert(g.Order() == 3);
	assert(g.Size()  == 1);


	
	
	cout << "PASSED!" << endl << endl;
}


int main(){
	
	TestAddNode();
	TestAddEdge();
	TestDestructor();
	TestGetEdges();
	TestGetNodes();
	TestNodeAt();
	TestSize();

	
	cout << "ALL TESTS PASSED!" << endl;
	return 0;
}
