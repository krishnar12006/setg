#include "graph.h"
#include <iomanip>

map<string, int> color;

string getMaxSaturation(set<string> &uncolored) {
    int maxSat = -1;
    string selected;

    for (auto &node : uncolored) {
        set<int> usedColors;

        for (auto &neigh : graph[node]) {
            if (color[neigh] != -1)
                usedColors.insert(color[neigh]);
        }

        if (usedColors.size() > maxSat) {
            maxSat = usedColors.size();
            selected = node;
        }
    }

    return selected;
}

void dsatur() {
    set<string> uncolored;

    for (auto &x : graph) {
        color[x.first] = -1;
        uncolored.insert(x.first);
    }

    while (!uncolored.empty()) {
        string node = getMaxSaturation(uncolored);

        set<int> used;

        for (auto &neigh : graph[node]) {
            if (color[neigh] != -1)
                used.insert(color[neigh]);
        }

        int c = 0;
        while (used.count(c))
            c++;

        color[node] = c;
        uncolored.erase(node);
    }

    cout << "\n===== DSATUR TIMETABLE =====\n\n";
    cout << "Course   ->   Time Slot\n";
    cout << "------------------------\n";

    int maxSlot = 0;

    for (auto &x : color) {
        cout << setw(8) << x.first << " ->   Slot " << x.second << endl;
        maxSlot = max(maxSlot, x.second);
    }

    cout << "\nTotal Slots Used: " << maxSlot + 1 << endl;
    cout << "Conflicts: 0\n";
}

int main() {
    initializeGraph();
    dsatur();
}
