#ifndef BETTERPRIORITYQUEUE_H
#define BETTERPRIORITYQUEUE_H
#include <string>
#include <queue>
#include <vector>
#include "Graph.h"

struct DNode {
	int pri = INT_MAX;
	bool visited = false;
	const GraphNode *node = nullptr;
	
	bool operator<(const DNode &other) const {
		return pri < other.pri;
	}

	bool operator>(const DNode &other) const {
		return pri > other.pri;
	}
	
	bool operator==(const DNode &other) const {
		return node == other.node;
	}
};

class BetterPriorityQueue: public std::priority_queue<DNode, std::vector<DNode>,
std::greater<DNode>>::priority_queue {
    public:
        bool Contains(DNode dn);
        bool Update(DNode dn);
        std::string ToString();
        std::string DNodeToString(DNode dn);
        
    private:
        std::vector<DNode> c;
        std::priority_queue<DNode, std::vector<DNode>, std::greater<DNode>> pq;
        


};
#endif