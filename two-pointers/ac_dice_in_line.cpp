// Question: What is the maximum expected sum from rolling k consecutive dice once each?
#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int double
#define endl  "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "
using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;    

 

void solve(){
  int n,k;
  cin>>n>>k;
   vector<double> expected_values(n); 
    for (int i = 0; i < n; ++i) {
        int p_i;
        cin >> p_i;
        // Calculate the expected value for the i-th die
        // E[X] = (1 + 2 + ... + p_i) / p_i = (p_i * (p_i + 1) / 2) / p_i = (p_i + 1) / 2
        expected_values[i] = (p_i + 1.0) / 2.0; // Use 1.0 and 2.0 for float division
    }
   
  //maximum sum subaary of size k
  //head and tail
  int head=-1,tail=0;
  //ans ans sum of current window
  int ans=-1e9;
  int sum = 0;

  while(tail < n){
    while(head+1<n and  (head - tail + 1) < k){
        head++;
        sum+=expected_values[head];
    }
    if(head-tail+1 == k){
       ans = max(ans,sum);
    }
    if(tail > head){
        tail++;
        head = tail-1;
    }else{
        sum-=expected_values[tail];
        tail++;
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

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: Sliding window - Fixed length
// explanation:
/*
expected_values[i] stores (p_i + 1) / 2 for each die.
head moves forward while the window is shorter than k, adding the new expected value into sum.
When head - tail + 1 equals k, ans keeps the larger sum.
tail then subtracts its value and steps forward, so the window slides one die at a time.
*/
