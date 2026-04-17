#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> graph;

map<string, int> greedyColoring() {
    map<string, int> result;

    for (auto &node : graph) {
        set<int> used;

        for (auto &neigh : node.second) {
            if (result.find(neigh) != result.end())
                used.insert(result[neigh]);
        }

        int color = 0;
        while (used.count(color)) color++;

        result[node.first] = color;
    }

    return result;
}

int main() {
    graph["C1"] = {"C2", "C3"};
    graph["C2"] = {"C1", "C4"};
    graph["C3"] = {"C1"};
    graph["C4"] = {"C2"};

    auto result = greedyColoring();

    for (auto &x : result) {
        cout << x.first << " -> Slot " << x.second << endl;
    }
}
