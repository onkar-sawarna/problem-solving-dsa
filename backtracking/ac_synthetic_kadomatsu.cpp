// Question: Find the minimum cost to make bamboos of lengths A, B, and C from the given pieces, where joining two pieces costs 10 and changing a length by one costs 1.
#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 

   void solve(int level,int n,int a,int b,int c,vector<int>& arr,int mpcost,int suma,int sumb, int sumc,int& ans){
     if(level==n){
        if(suma == 0 || sumb == 0 || sumc == 0)return;
        ans=min(ans,mpcost+abs(a-suma)+abs(b-sumb)+abs(c-sumc));
        return;
     }
     solve(level+1,n,a,b,c,arr,mpcost,suma,sumb,sumc,ans);
     solve(level+1,n,a,b,c,arr,mpcost+((suma>0)?10:0),suma+arr[level],sumb,sumc,ans);
     solve(level+1,n,a,b,c,arr,mpcost+((sumb>0)?10:0),suma,sumb+arr[level],sumc,ans);
     solve(level+1,n,a,b,c,arr,mpcost+((sumc>0)?10:0),suma,sumb,sumc+arr[level],ans);
   }

    signed main()
    {
        IOS;
        int n;
        cin>>n;
        vector<int> arr(n);
        int a,b,c;
        int ans=INT_MAX,mpcost=0;
        int suma=0,sumb=0,sumc=0;
        cin>>a>>b>>c;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        solve(0,n,a,b,c,arr,mpcost,suma,sumb,sumc,ans);
        cout<<ans<<"\n";
        return 0;
    }

// Time Complexity: O(4^n)
// Space Complexity: O(n)
// Pattern: Backtracking - Three Bamboo Groups
// explanation:
/*
Each bamboo is skipped or assigned to A, B, or C, so every index has four branches.
Adding a bamboo to a group that already holds one costs 10.
A leaf is ignored if any group is empty, otherwise the absolute gaps from a, b, and c are added.
The call stack is n frames and no board is stored.
*/
