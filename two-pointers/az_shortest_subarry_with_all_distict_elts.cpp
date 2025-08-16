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
   int n;
   cin>>n;
   vi a(n);
   vin(a);

   unordered_set<int> all_distinct_elements_set;
   for (int x : a) {
       all_distinct_elements_set.insert(x);
   }
   int total_distinct_elements_count = all_distinct_elements_set.size();

   int tail = 0;
   int head = -1; 
   
   int min_len = n + 1; 
   
   unordered_map<int, int> current_window_freq;
   int distinct_elements_in_window = 0; 

   while(tail < n){
     while(head + 1 < n && distinct_elements_in_window < total_distinct_elements_count){
        head++;
        if (current_window_freq[a[head]] == 0) {
            distinct_elements_in_window++; 
        }
        current_window_freq[a[head]]++;
     }
     
     if(distinct_elements_in_window == total_distinct_elements_count){
         min_len = min(min_len, head - tail + 1);
     }

     if(tail > head){
        tail++;
        head = tail - 1;
     } else {
        current_window_freq[a[tail]]--;
        if (current_window_freq[a[tail]] == 0) {
            distinct_elements_in_window--;
        }
        tail++;
     }
   } 
   
   cout<<min_len<<endl;
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