/*Trapping Rainwater Problem : Given n non-negative integers 
representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.
*/
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


int trap(vector<int>& height) {
    int n=height.size();
    vector<int> left(n,0),right(n,0);
    if (n<=2)return 0;
    left[0] = height[0]; // storing left max
    right[n-1] = height[n-1]; // storing right max
    for(int i=1;i<height.size()-1;i++){
        left[i]=max(left[i-1],height[i]);
        right[n-1-i]=max(right[n-1-i+1],height[n-1-i]);
    }
    int result=0;
    for(int i=1;i<height.size()-1;i++){
       result += min(left[i],right[i])-height[i];
    }
    return result;
}
void solve(){
 vi input = {0,1,0,2,1,0,1,3,2,1,2,1};
 cout<<trap(input)<<endl;
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