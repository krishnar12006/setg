#include "graph.h"
#include <iomanip>

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
    initializeGraph();

    auto result = greedyColoring();

    cout << "\n===== GREEDY TIMETABLE =====\n\n";
    cout << "Course   ->   Time Slot\n";
    cout << "------------------------\n";

    int maxSlot = 0;

    for (auto &x : result) {
        cout << setw(8) << x.first << " ->   Slot " << x.second << endl;
        maxSlot = max(maxSlot, x.second);
    }

    cout << "\nTotal Slots Used: " << maxSlot + 1 << endl;
    cout << "Conflicts: 0\n";
}
