// Problem Statement : There are n painters available to paint walls of different lengths.
// Each painter takes 1 unit time to paint 1 unit length of wall.
// You are given an array arr[] of size n where arr[i] represents the length of the wall that the ith painter has to paint.
// You have to partition the walls among painters such that the maximum time taken by any painter to paint their assigned walls is minimized.
// Return the minimum possible value of the maximum time taken by any painter.

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
int n,m;
int arr[100100];
    bool canPaint(int max_time){
        int painters_used = 1;
        int current_time = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > max_time){
                return false;
            }
            if(current_time + arr[i] <= max_time){
                current_time += arr[i];
            }else{
                painters_used++;
                current_time = arr[i];
                if(painters_used > m){
                    return false;
                }
            }
        }
        return true;
    }
    void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];    
        }   
        int left = 0;   
        int right = 1e14;
        int ans = right;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(canPaint(mid)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        cout<<ans<<endl;
    }
    signed main()
    {
        IOS;
        int t;
        t=1;
        while(t--){
        solve();
        }
        return 0;
    }