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


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        int x = target - nums[i];
        if (mp.find(x) != mp.end()) {
            res.push_back(mp[x]);
            res.push_back(i);
            return res;
        }
        mp[nums[i]] = i;
    }
    return res;
}
void solve(){
  vi input = {2,7,11,15};
  vi output = twoSum(input,9);
  vout(output);
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