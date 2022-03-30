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
//check to see if dnode exists in queue
bool BetterPriorityQueue::Contains(DNode dn){
//cout<<"hello world" << endl;
    bool inBPQ= false;

    for(unsigned int i=0; i<c.size(); i++){ //fixme
        
        if(c.at(i).node==dn.node) {
            inBPQ= true;
            break;
        }
    }

return inBPQ;

    
}
//updates the pqueue if DNODe already exists in the queue, returns true if this is the case. returns false if no chnages are needed

bool BetterPriorityQueue::Update(DNode dn){
    bool needToUpdate= true;
    
    vector<DNode> temp;
    DNode emptynode;
    if(dn == emptynode){
        return false;
    }
    else{
        for(unsigned int i=0; i < c.size(); i++){
            if(c.at(i)==dn) {
                
                
                if(c.at(i).pri==dn.pri || c.at(i).pri < dn.pri) {
                    
                    
                    needToUpdate= false;
                }
                else {
                    c.at(i).pri=dn.pri;
                    
                }
                break;
                
            }
            
        }
        temp=c;
        c.erase(c.begin(), c.end());
    
    
        while(temp.size()>0){
            this->push(temp.front());
            temp.erase(temp.begin(), temp.begin()+1);
        }
    }
    return needToUpdate;
}
//returuns string rep.
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
//returns string rep
string BetterPriorityQueue::DNodeToString(DNode dn){
    string dnodeString="";
    dnodeString+="(";
    dnodeString+=dn.node->key;
    dnodeString+=": ";
    dnodeString+=to_string(dn.pri);
    dnodeString+=")";
    return dnodeString;
}