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


vector<vector<int>> output;
    vector<int> temp;
    vector<bool> used;

    void backtrack(vector<int>& nums) {
        if (temp.size() == nums.size()) {
            output.push_back(temp);
            return;
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums);
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        output.clear();
        temp.clear();
        used.assign(nums.size(), false);
        backtrack(nums);
        return output;
    }
        void solve(){
          vi nums= {1,3,4,2};
          int cnt=0;
          vvi output = permute(nums);
          for(auto v:output){
            for(auto x:v){
                cout<<x<<" ";
            }
            cnt++;
            cout<<endl;
          }
          cout<<"count:"<<cnt<<endl;
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

// Time Complexity: O(n * n!)
// Space Complexity: O(n * n!)
// Pattern: Backtracking - Index Permutations
// explanation:
/*
The path takes one unused index at a time and marks it in the used array.
The first position has n choices, the next has n-1, and so on, so the tree has n! leaves.
Each leaf copies a length-n permutation into output.
The used flags, the current path, and the call stack are linear, on top of the stored permutations.
*/
