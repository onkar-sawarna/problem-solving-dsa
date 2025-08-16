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

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;

    for (const string& s : strs) {
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        anagramGroups[sorted_s].push_back(s);
    }

    vector<vector<string>> result;
    result.reserve(anagramGroups.size());

    for (auto it = anagramGroups.begin(); it != anagramGroups.end(); ++it) {
        result.push_back(it->second);
    }

    return result;
}

void solve(){
vector<string> input_strs = {"eat","tea","tan","ate","nat","bat"};
 vector<vector<string>> output = groupAnagrams(input_strs);
 for(auto v:output){
   for(auto str:v){
    cout<<str<<" ";
   }
   cout<<endl;
 }
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