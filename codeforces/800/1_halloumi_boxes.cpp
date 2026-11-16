// Question: Can you sort the array by reversing any subarrays of length at most k?
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
   int n,k;
   cin>>n>>k;
   vi a(n);
   vin(a);

   vi a_copy = a;
   sort(a_copy.begin(),a_copy.end());

   if(a==a_copy || k>1){
     cout<<"YES"<<endl;
   }else{
    cout<<"NO"<<endl;
   }
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

// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Pattern: Greedy - Sort or swap
// explanation:
/*
a_copy is a full copy of a, then it is sorted.
If a already matches that sorted copy, the boxes are in order and the answer is YES.
If k is greater than 1, adjacent swaps are available and the answer is also YES.
k equal to 1 on an unsorted array leaves no legal move, so the answer is NO.
*/
