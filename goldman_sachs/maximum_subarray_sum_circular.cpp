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

int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    
    if (n == 0) {
        return 0; 
    }

    int total_sum = 0;
    
    int max_so_far = nums[0];
    int current_max = nums[0];

    int min_so_far = nums[0];
    int current_min = nums[0];

    total_sum += nums[0]; 

    for (int i = 1; i < n; ++i) {
        total_sum += nums[i];

        current_max = max(nums[i], current_max + nums[i]);
        max_so_far = max(max_so_far, current_max);

        current_min = min(nums[i], current_min + nums[i]);
        min_so_far = min(min_so_far, current_min);
    }

    if (total_sum == min_so_far) {
        return max_so_far;
    }

    return max(max_so_far, total_sum - min_so_far);
}

void solve(){
   vi input = {1,2,3,-4,5,6,7,8,9}; 
   cout<<maxSubarraySumCircular(input)<<endl;
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