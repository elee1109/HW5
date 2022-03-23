#include "Graph.h"
#include <iostream>
#include <vector>
#include <map>



using namespace std;

map<GraphNode*, vector<GraphEdge*>> currGraph;
GraphEdge *nullEdge= new GraphEdge(); //place holder
//map<GraphNode, vector<GraphEdge>> currGraph;
//GraphEdge nullEdge= GraphEdge(); 

Graph::~Graph(){
    currGraph.erase(currGraph.begin(), currGraph.end());


}
GraphNode* Graph::AddNode(char key, int data){
    GraphNode *currNode= new GraphNode();
    
    currNode->key= key;
    currNode->data= data;
    if(currGraph.find(currNode)==currGraph.end()) currGraph.insert({currNode, {nullEdge}}); //Does not add if Node already exists in graph
    return currNode;
    delete currNode;
    delete nullEdge;
}
GraphEdge* Graph::AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight){
    GraphEdge *currEdge= new GraphEdge();
    if(currGraph.find(gn1)!=currGraph.end() && currGraph.find(gn2)!=currGraph.end()){ //checks to see if nodes in hashmap, if they are continue
        
        currEdge->from= gn1;
        currEdge->to=gn2;
        currEdge->weight= weight;

        if (currGraph.at(currEdge->from).at(0)== nullEdge) currGraph.at(currEdge->from).at(0)= currEdge; //if no edges have been assigned yet add this edge to index 0
        else currGraph.at(currEdge->from).push_back(currEdge);// if edges have already been assigned add the edge to the list of edges. 
        return currEdge;
        delete currEdge;
    }
    else{
        delete currEdge;
        throw exception();
    }
    

}
string Graph::NodesToString() const{
    string stringNode="[";
    size_t punc= currGraph.size();
    for(auto& n: currGraph){
        stringNode.append("(");
        stringNode+=(n.first->key);
        stringNode.append(":");
        stringNode.append(to_string(n.first->data));
        stringNode.append(")");
        if(punc>1) {
            stringNode.append(", ");
            punc--;
        }
        
    }
    stringNode.append("]");
    return stringNode;
}
string Graph::ToString() const{
    string graphString;
    for(auto& n: currGraph){
        
        graphString+=(n.first->key);
        graphString.append(" | \n");
    }
    return graphString; 
}
string Graph::GraphNodeToString(const GraphNode *gn){

}
string Graph::GraphEdgeToString(const GraphEdge *ge){

}
/**
 * @brief gets all edges that branch out from a given node in parameter
 * 
 * @param gn --> node in graph
 * @return const vector<GraphEdge*>& 
 */
const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn) const{
    vector<GraphEdge*> edgesFromNode;
    if(currGraph.find(gn)!= currGraph.end(){
        edgesFromNode=currGraph.at(gn)
    }
    return edgesFromNode;


}
const vector<GraphNode*>& Graph::GetNodes() const{
    vector<GraphNode*> nodesinGraph;
    for(auto& n: currGraph) nodesinGraph.push_back(n.first);


}

const GraphNode* Graph::NodeAt(unsigned int idx) const{

}
		
size_t Graph::Size() const{
    vector<GraphEdge*> allEdges;


} // the number of edges
size_t Graph::Order() const{
    return currGraph.size();

} // the number of nodes
