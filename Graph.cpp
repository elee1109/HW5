#include "Graph.h"
#include <iostream>
#include <vector>
#include <map>



using namespace std;
//FOR PRIORITY QUEUE FORMULA: NODE i: left child = 2i+1, right child = 2i+2;
//priority queue 

Graph::~Graph(){
    currGraph.erase(currGraph.begin(), currGraph.end());
    for(auto& eraseN_E: currGraph){
        
        for(auto& eraseEdge: eraseN_E.second){
            delete eraseEdge->from;
            delete eraseEdge->to;
            delete eraseEdge;
        }
        delete eraseN_E.first;
    }


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
        stringNode+=GraphNodeToString(n.first);
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
        size_t comma= n.second.size();
        
        
        graphString+=(n.first->key);
        graphString.append(" | ");
        cout<< "test print in first loop: " << graphString<< endl;
        if (n.second.at(0) != nullEdge) {
            
            for(auto& edge: n.second){
                graphString+="[";
                graphString+=GraphEdgeToString(edge);
                graphString+="]";
                if(comma>1) graphString+=", ";
                comma--;

            }
            
        }
        graphString.append("\n");

    }
    //cout<<"graph String: " << graphString << endl;
    return graphString; 
}
string Graph::GraphNodeToString(const GraphNode *gn){
    string gnString="";
    gnString+= "(";
    gnString+=(gn->key);
    gnString+=":";
    gnString+=(to_string(gn->data));
    gnString+=")";
    return gnString;
}
string Graph::GraphEdgeToString(const GraphEdge *ge){
    string geString="(";
    geString+=(ge->from->key);
    geString+=":" + to_string(ge->from->data) + ")"+"->(";
    geString+= (ge->to->key);
    geString+=":" + to_string(ge->to->data) + ") "+"w:"+to_string(ge->weight);
    return geString;
    
}
/**
 * @brief gets all edges that branch out from a given node in parameter
 * 
 * @param gn --> node in graph
 * @return const vector<GraphEdge*>& 
 */

const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn) const{
    vector<GraphEdge*> edgesFromNode;
    map<const GraphNode*, vector<GraphEdge*>> copyMap;
    for (auto& n_e: currGraph){
        copyMap.insert({n_e.first, n_e.second});
    }
    for(auto& edges: copyMap.at(gn)) edgesFromNode.push_back(edges);
    return edgesFromNode;
}


const vector<GraphNode*>& Graph::GetNodes() const{
    vector<GraphNode*> nodesinGraph;
    for(auto& n: currGraph) nodesinGraph.push_back(n.first);

    return nodesinGraph;


}
//
const GraphNode* Graph::NodeAt(unsigned int idx) const{
    const GraphNode* cNode =new GraphNode();
    vector<const GraphNode*> tempVec;
    for(auto& node: currGraph) tempVec.push_back(node.first);
    for(unsigned int i=0; i<tempVec.size(); i++){
        if(idx==i) cNode=tempVec.at(i);
    }
    return cNode;
}
		
size_t Graph::Size() const{
    vector<GraphEdge*> allEdges;
    for(auto& edges: currGraph){
        for(auto& edge: edges.second) allEdges.push_back(edge);
        
    }
    return allEdges.size();

} // the number of edges
size_t Graph::Order() const{
    return currGraph.size();

} // the number of nodes
