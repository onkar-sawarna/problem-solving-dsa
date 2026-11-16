// Question: How can the letters of s be rearranged so that neither FFT nor NTT appears as a substring?
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

void solve(){
   string s;
   cin>>s;
   int cnt[26] = {0};
    for (char c : s) cnt[c - 'A']++;
    string ans;
    ans.append(cnt['T'-'A'], 'T');
    ans.append(cnt['F'-'A'], 'F');
    ans.append(cnt['N'-'A'], 'N');
    for (int i = 0; i < 26; ++i) {
        if (i != 'T'-'A' && i != 'F'-'A' && i != 'N'-'A') {
            ans.append(cnt[i], static_cast<char>(i + 'A'));
        }
    }
    cout<<ans<<endl;
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

// Time Complexity: O(T * |S|)
// Space Complexity: O(|S|)
// Pattern: Constructive - Letter reorder
// explanation:
/*
A length-26 array counts the letters in s.
The answer is rebuilt by writing every T, then every F, then every N.
A pass over the other 23 letters appends whatever count remains for each of them.
Letters already placed are skipped in that pass.
The new string has the same length as s.
*/
