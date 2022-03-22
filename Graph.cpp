#include "Graph.h"
#include <iostream>
#include <vector>


using namespace std;

GraphNode Graph::*AddNode(char key, int data=0){

}
GraphEdge Graph:: *AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight = 0){
    
}
string Graph::NodesToString() const{

}
string Graph::ToString() const{
    
}
string Graph::GraphNodeToString(const GraphNode *gn){

}
string Graph::GraphEdgeToString(const GraphEdge *ge){

}
const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn) const{

}
const vector<GraphNode*>& Graph::GetNodes() const{

}

const GraphNode* Graph::NodeAt(unsigned int idx) const{

}
		
size_t Graph::Size() const{

} // the number of edges
size_t Graph::Order() const{
    
} // the number of nodes
