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
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // head and tail
    int tail = 0, head = -1;

    // datastructure for the window
    map<int, int> mp;
    int distinctCnt = 0;

    // answer maintain
    int ans = 0;

    // for every start
    while (tail < n)
    {
        // eat as many elements as possible till its valid
        while (head + 1 < n && (distinctCnt < k || mp[arr[head + 1]] >= 1))
        {
            head++;
            // insert ds(head)
            if (mp[arr[head]] == 0)
            {
                distinctCnt++;
            }
            mp[arr[head]]++;
        }
        // update the answer for current start
        ans += (head - tail + 1);
        // move start one step forward.
        if (tail > head)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            // earse from ds(tail)
            mp[arr[tail]]--;
            if (mp[arr[tail]] == 0)
            {
                distinctCnt--;
            }

            tail++;
        }
    }

    cout << ans << endl;
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