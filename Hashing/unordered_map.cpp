#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> m;
    m["gfg"] = 20;
    m["ide"] = 30;
    m.insert({"course", 15});

    if(m.find("gfg") != m.end()) {
        auto it = m.find("gfg");
        cout << it->second;
    }
    else
    cout << "Not Found\n";

    for(auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

    if(m.count("ide") > 0)
    cout << "Found" << endl;
    else
    cout << "Not Found" << endl;
    return 0;
}