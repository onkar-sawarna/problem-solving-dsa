// Question: What string is on the server after the copies between the server and the computers and the appends onto the computers?
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

// Time Complexity: O(Q + S)
// Space Complexity: O(Q + S)
// Pattern: Constructive - Append versions
// explanation:
/*
Type 2 pushes a node whose parent is the PC's current version and whose text is the appended piece, then points that PC at the new node.
Type 1 copies the server version id onto a PC. Type 3 copies a PC version id onto the server.
Those copies move integers only, so the character data stays on the nodes.
After the queries, the server id is followed through parent links, the pieces are reversed into write order, and they are joined.
S is the total length of every appended piece, including the joined result.
*/
