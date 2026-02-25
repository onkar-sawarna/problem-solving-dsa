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
 long long n;
 cin>>n;
 vector<long long> v(n);
 for (long long i = 0; i < n; i++) // Read the array elements
			cin >> v[i];

    // Initialize the answer with the difference between the last and first element
    long long answer = v[n - 1] - v[0];

    // Check the maximum difference between any element and the first element
    for (int i = 1; i < n; i++)
        answer = max(answer, v[i] - v[0]);

    // Check the maximum difference between the last element and any other element
    for (int i = 0; i < n - 1; i++)
        answer = max(answer, v[n - 1] - v[i]);

    // Check the maximum difference between consecutive elements
    for (int i = 0; i < n - 1; i++)
        answer = max(answer, v[i] - v[i + 1]);

    // Output the maximum difference found
    cout << answer << endl;
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