#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> graph;
map<string, int> color;

bool isSafe(string node, int c) {
    for (auto &neigh : graph[node]) {
        if (color[neigh] == c)
            return false;
    }
    return true;
}

bool solve(vector<string> nodes, int m, int idx) {
    if (idx == nodes.size())
        return true;

    string node = nodes[idx];

    for (int c = 0; c < m; c++) {
        if (isSafe(node, c)) {
            color[node] = c;

            if (solve(nodes, m, idx + 1))
                return true;

            color[node] = -1;
        }
    }
    return false;
}

int main() {
    graph["C1"] = {"C2", "C3"};
    graph["C2"] = {"C1", "C4"};
    graph["C3"] = {"C1"};
    graph["C4"] = {"C2"};

    vector<string> nodes;
    for (auto &x : graph)
        nodes.push_back(x.first);

    int m = 3;

    for (auto &x : nodes)
        color[x] = -1;

    if (solve(nodes, m, 0)) {
        cout << "\n===== BACKTRACKING TIMETABLE =====\n\n";
        cout << "Course   ->   Time Slot\n";
        cout << "------------------------\n";

        for (auto &x : color) {
            cout << setw(8) << x.first << " ->   Slot " << x.second << endl;
        }
    } else {
        cout << "No solution\n";
    }
}
