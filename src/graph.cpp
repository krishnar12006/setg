#include "graph.h"

map<string, vector<string>> graph;

void initializeGraph() {
    graph["C1"] = {"C2", "C3"};
    graph["C2"] = {"C1", "C4"};
    graph["C3"] = {"C1"};
    graph["C4"] = {"C2"};
}
