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
bool BetterPriorityQueue::Contains(DNode dn){
//cout<<"hello world" << endl;
bool inBPQ= false;
/**
for(unsigned int i=0; i<c.size(); i++){ //fixme
    cout<<"hello world" << endl;
    if(c.at(i).node==dn.node) {
        inBPQ= true;
        break;
    }
    
}
*/

priority_queue<DNode, vector<DNode>, greater<DNode>> temp= pq;
while(temp.size() >0){
    cout<< "hello" << endl;
    if(temp.top() == dn){
        inBPQ=true;
        break;
    }
    temp.pop();
}
return inBPQ;
    
}
bool BetterPriorityQueue::Update(DNode dn){
    bool inBPQ=false;
    int nodeIdx=0;
    for(unsigned int i=0; i < c.size(); i++){
        if(c.at(i).node==dn.node) {
            inBPQ= true;
            nodeIdx=i;
            break;
        }
    }
    



}
string BetterPriorityQueue::ToString(){

}
string BetterPriorityQueue::DNodeToString(DNode dn){

}