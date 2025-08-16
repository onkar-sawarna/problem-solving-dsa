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
    int N;
    long long target;
    cin >> N >> target;
    
    vi A(N);
    vin(A);

    sort(A.begin(), A.end());

    long long min_diff = LLONG_MAX; 

    for (int i = 0; i < N - 2; ++i) {
        if (i > 0 && A[i] == A[i-1]) {
            continue; 
        }

        int left = i + 1;
        int right = N - 1;

        while (left < right) {
            long long current_sum = A[i] + A[left] + A[right];
            long long diff = abs(current_sum - target);

            if (diff < min_diff) {
                min_diff = diff;
            }

            if (current_sum == target) {
                cout << 0 << endl;
                return;
            } 
            else if (current_sum < target) {
                left++;
                while (left < right && A[left] == A[left-1]) {
                    left++;
                }
            } 
            else { 
                right--;
                while (left < right && A[right] == A[right+1]) {
                    right--;
                }
            }
        }
    }
    
    cout << min_diff << endl;
}

signed main()
{
    IOS; 

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}