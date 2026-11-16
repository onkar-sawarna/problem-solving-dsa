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


int lengthOfLongestSubstring(string s) {
    int left = 0;
    int ans = 0;
    int n = s.size();
    unordered_map<char,int>freq;
    for(int i=0;i<n;i++){
        freq[s[i]]++;
        while(freq[s[i]]>1){
            freq[s[left]]--;
            left++;
        }
        ans = max(ans,i-left+1);
    }
    return ans;
        
  }

void solve(){
  cout<<lengthOfLongestSubstring("onkarsawarna")<<endl;
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

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Sliding Window - No Repeated Character
// explanation:
/*
The right edge takes the next character into the window.
The left edge advances while that character occurs more than once inside the window.
Each index enters once and leaves at most once, and the best length is updated on every valid window.
The frequency map has one slot per character code, so it stays within the alphabet size.
*/
