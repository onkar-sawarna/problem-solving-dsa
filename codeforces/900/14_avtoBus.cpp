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

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n; // Read the total number of wheels for the current test case

    // If the number of wheels is less than 4 or odd, it's impossible to form buses
    if (n < 4 || n % 2 == 1)
        cout << -1 << '\n'; // Output -1 indicating no valid configuration
    else
    {
        // Calculate the minimum number of buses using 6-wheel buses
        long long min_buses = (n + 5) / 6; // integer ceil of n/6
        
        // Calculate the maximum number of buses using 4-wheel buses
        long long max_buses = n / 4;       // integer floor of n/4

        // Output the minimum and maximum number of buses
        cout << min_buses << " " << max_buses << '\n';
    }
}

// Time Complexity (TC): O(1)
// Space Complexity (SC): O(1)


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