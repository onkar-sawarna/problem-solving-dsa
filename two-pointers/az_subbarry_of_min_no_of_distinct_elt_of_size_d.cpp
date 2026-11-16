// Question: What is the fewest distinct values in any subarray of length d?
#include <bits/stdc++.h>
using namespace std;

#define IOS \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

void solve()
{
    int n, d;
    cin >> n >> d;
    
    vi arr(n); 
    vin(arr);

    int tail = 0;
    int head = -1; 

    unordered_map<int, int> freq; 
    int distinct_count = 0;

    int min_penalty = n + 1; 

    while (tail <= n - d) 
    { 
        while (head + 1 < n && (head - tail + 1) < d) 
        {
            head++;
            
            if (freq[arr[head]] == 0) {
                distinct_count++;
            }
            freq[arr[head]]++;
        }
       
        if (head - tail + 1 == d) {
            min_penalty = min(min_penalty, distinct_count);
        }
        
        if (tail > head)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            freq[arr[tail]]--;
            if (freq[arr[tail]] == 0) {
                distinct_count--;
            }
            tail++;
        }
    }

    cout << min_penalty << endl;
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

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: Sliding window - Fixed length distinct
// explanation:
/*
head advances while the window is shorter than d, and freq counts values inside it.
The first time a value appears, distinct_count increases.
When head - tail + 1 equals d, min_penalty keeps the smaller distinct count.
tail decrements freq[arr[tail]] and steps forward, and a count that hits 0 lowers distinct_count.
*/
