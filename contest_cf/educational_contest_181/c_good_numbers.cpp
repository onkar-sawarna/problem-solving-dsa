// Question: How many integers from l to r have only prime factors with at least two digits?
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


int func(int x){
    int cnt[4]={};
    cnt[0]=x/2;
    cnt[1]=x/3-x/6;
    cnt[2]=x/5-x/10-x/15+x/30;
    cnt[3]=x/7-x/14-x/21-x/35+x/42+x/105+x/70-x/210;
    for(int i=0;i<4;i++) x-=cnt[i];
    return x;
}
void solve(){
    int l,r; cin>>l>>r;
    l--;
    cout<<func(r)-func(l)<<'\n';
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

// Time Complexity: O(T)
// Space Complexity: O(1)
// Pattern: Math - Inclusion exclusion
// explanation:
/*
func(x) counts integers up to x that are not divisible by 2, 3, 5, or 7.
Four buckets subtract multiples of those primes, with the mixed products put back or removed by inclusion-exclusion.
The leftover value of x is the count that avoids every one of those factors.
The printed range count is func(r) - func(l - 1).
Each call is a fixed set of divisions plus a loop of length 4.
*/
