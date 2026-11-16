// Question: What are the minimum and maximum numbers of friendships when n students are divided into m non-empty teams?
#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
   int n,m;
   cin>>n>>m;
   int k_min,k_max;
   int r=n%m;
   int q=n/m;
   int mod = 1e9+7;
   k_min = (r*(q*(q+1)/2)+(m-r)*(q*(q-1)/2));
   k_max = ((n-m+1)*(n-m)/2);
   cout<<k_min<<" "<<k_max<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
// Pattern: Math - Team pair extremes
// explanation:
/*
n students are placed in m teams, and each team of size s contributes s*(s-1)/2 pairs.
The minimum uses q = n/m and r = n%m, so r teams have size q+1 and the rest have size q.
The maximum puts n-m+1 students in one team and one student in every other team.
Both answers are direct arithmetic. No team list is built.
*/
