#include<bits/stdc++.h>
using namespace std;

#define IOS \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

struct StringNode {
    int parent_id;
    string appended_str;
};

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<StringNode> stringNodes; 
    vector<int> currentPcObjectIds(N + 1, 0); 
    int currentServerObjectId = 0;     

    stringNodes.push_back({-1, ""}); 

    for (int q = 0; q < Q; ++q) {
        int type;
        cin >> type;

        if (type == 1) {
            int p;
            cin >> p;
            currentPcObjectIds[p] = currentServerObjectId;
        } else if (type == 2) {
            int p;
            string s;
            cin >> p >> s;
            
            stringNodes.push_back({currentPcObjectIds[p], s});
            currentPcObjectIds[p] = stringNodes.size() - 1; 
        } else {
            int p;
            cin >> p;
            currentServerObjectId = currentPcObjectIds[p];
        }
    }

    vector<string> parts;
    int currentNodeId = currentServerObjectId;

    while (currentNodeId != -1) {
        parts.push_back(stringNodes[currentNodeId].appended_str);
        currentNodeId = stringNodes[currentNodeId].parent_id;
    }

    reverse(parts.begin(), parts.end());

    string finalServerString = "";
    for (const string& part : parts) {
        finalServerString += part;
    }

    cout << finalServerString << "\n";
}

signed main() {
    IOS;

    int t = 1; 
    // cin >> t; 

    while(t--){
        solve();
    }
    
    return 0;
}