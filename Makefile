all:
	g++ -Wall Graph.cpp GraphTests.cpp -o graph-tests
	g++ -Wall Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests
	g++ -Wall Graph.cpp BetterPriorityQueue.cpp Dijkstra.cpp -o da-tests