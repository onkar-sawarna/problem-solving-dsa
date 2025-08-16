#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl  "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "
using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;


int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead_set(deadends.begin(), deadends.end());

    if (dead_set.count("0000")) {
        return -1;
    }

    queue<pair<string, int>> q;
    q.push({"0000", 0});

    unordered_set<string> visited;
    visited.insert("0000");

    while (!q.empty()) {
        string current_code = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current_code == target) {
            return steps;
        }

        for (int i = 0; i < 4; ++i) {
            char original_digit = current_code[i];

            current_code[i] = (original_digit - '0' + 1) % 10 + '0';
            if (dead_set.find(current_code) == dead_set.end() && visited.find(current_code) == visited.end()) {
                q.push({current_code, steps + 1});
                visited.insert(current_code);
            }

            current_code[i] = (original_digit - '0' - 1 + 10) % 10 + '0';
            if (dead_set.find(current_code) == dead_set.end() && visited.find(current_code) == visited.end()) {
                q.push({current_code, steps + 1});
                visited.insert(current_code);
            }

            current_code[i] = original_digit;
        }
    }

    return -1;
}
void solve(){
    vector<string> dead = {"0202","0101"};
    string target = "0501";
    cout<<openLock(dead,target)<<endl;
}

signed main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
     solve();
    }
    return 0;
}