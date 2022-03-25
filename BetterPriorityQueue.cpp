#include "BetterPriorityQueue.h"
#include "Graph.h"
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>


using namespace std;
// This is a "Dijkstra Node" it is used for the Dijkstra algorithm
// and it is used as the items in the BetterPriorityQueue
//BetterPriorityQueue <DNode, vector<DNode>, greater<DNode>>;
Graph g= Graph();
bool BetterPriorityQueue::Contains(DNode dn){
//cout<<"hello world" << endl;
bool inBPQ= false;

for(unsigned int i=0; i<c.size(); i++){ //fixme
    cout<<"hello world" << endl;
    if(c.at(i).node==dn.node) {
        inBPQ= true;
        break;
    }
    
}

return inBPQ;

    
}
bool BetterPriorityQueue::Update(DNode dn){
    unsigned int nodeIdx=0;
    bool needToUpdate= true;
    
    for(unsigned int i=0; i < c.size(); i++){
        if(c.at(i)==dn) {
            nodeIdx=i;
            cout<< "should only print once"<< endl;
            if(c.at(i).pri==dn.pri) {
                
                cout<< "SHOULD NOT PRINT" << endl;
                cout<< "in list: " <<c.at(i).pri<< " new dn: " << dn.pri << endl;
                needToUpdate= false;
            }
            else {
                c.erase(c.begin()+nodeIdx, c.begin()+nodeIdx+1);
            }
            break;
            
        }
    }
    this->push(dn);

    
    //if(inBPQ) c.erase(c.begin()+nodeIdx, c.begin()+nodeIdx+1);
    //for(unsigned int i=0; i< c.size() ; i++) cout<< g.GraphNodeToString(c.at(i).node) <<" priority: "<< c.at(i).pri<< endl;
    
    

    return needToUpdate;
}
string BetterPriorityQueue::ToString(){
    string bpqString="[";
    int comma=c.size();
    for (auto& dnode: c){
        bpqString+=DNodeToString(dnode);
        if(comma>1) bpqString+=", ";
        comma--;

    }
    bpqString+="]";
    return bpqString;

}
string BetterPriorityQueue::DNodeToString(DNode dn){
    string dnodeString="";
    dnodeString+="(";
    dnodeString+=dn.node->key;
    dnodeString+=": ";
    dnodeString+=dn.pri;
    dnodeString+=")";
    return dnodeString;
}