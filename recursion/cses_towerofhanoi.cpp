#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(int disk,int left,int right,int middle){
   if(disk == 0)return;
   solve(disk-1,left,middle,right);
   cout<<left<<" "<<right<<"\n";
   solve(disk-1,middle,right,left);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        int disk;
        cin>>disk;
        // (2^n)-1
        cout<<((1<<disk)-1)<<"\n";
        int left=1,middle=2,right=3;
        solve(disk,left,right,middle);
    }
    return 0;
}