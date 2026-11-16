// Question: Can every task be finished by its deadline if the tasks are done one after another?
#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 

   void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].second>>p[i].first;
    }
    sort(p.begin(),p.end());
    int start=0;
    for(auto it:p){
        if(it.first < it.second+start){
            cout<<"No";
            return;
        }
        else start+=it.second;
    }
    cout<<"Yes";
   }

    signed main()
    {
        IOS;
        solve();
        return 0;
    }

// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Pattern: Greedy - Deadline order
// explanation:
/*
Each task is stored as a pair of deadline and duration, then p is sorted by deadline.
start is the moment the next task would begin.
If a deadline is smaller than start plus that task's duration, the scan prints No and returns.
Otherwise the duration is added to start, and the next task is checked in the same deadline order.
*/
