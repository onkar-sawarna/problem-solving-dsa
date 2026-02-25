// Problem Statement: Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile.
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.
// Problem Source: LeetCode #875 (https://leetcode.com/problems/koko-eating-bananas/)
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
int n,h;
int piles[100100];  
bool canEatAll(int speed){
    int hours_needed = 0;
    for(int i=0;i<n;i++){
        hours_needed += (piles[i] + speed - 1)/speed; //ceil division
        if(hours_needed > h){
            return false;
        }
    }
    return hours_needed <= h;
}   
void solve(){
   cin>>n>>h;
   for(int i=0;i<n;i++){
    cin>>piles[i];
   }
   int left = 1;
   int right = 1e9;
   int ans = right;
   while(left <= right){
    int mid = left + (right - left)/2;
    if(canEatAll(mid)){
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