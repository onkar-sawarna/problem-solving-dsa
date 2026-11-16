// Question: For each starting mood, what is the mood after every present, which adds a while the mood is at most p and otherwise subtracts b down to zero?
#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl  "\n"

struct Present {
  int p;
  int a;
  int b;
};

void solve(){
  int n;
  cin >> n;
  vector<Present> presents(n);
  for (int i = 0; i < n; ++i) {
    cin >> presents[i].p >> presents[i].a >> presents[i].b;
  }
  
  //taking threshold as 2k
  const int K = 2000;
  
  vector<int> final_mood(K + 1);
  
  for (int initial_mood = 0; initial_mood <= K; ++initial_mood) {
    int current_mood = initial_mood;
    for (int i = 0; i < n; ++i) {
      if (presents[i].p >= current_mood) {
        current_mood += presents[i].a;
      } else {
        current_mood = max(0LL, current_mood - presents[i].b);
      }
    }
    final_mood[initial_mood] = current_mood;
  }
  
  int net_change_large_x = final_mood[K] - K;
  
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;
    if (x <= K) {
      cout << final_mood[x] << endl;
    } else {
      cout << x + net_change_large_x << endl;
    }
  }
}

signed main()
{
    IOS;
    int t;
    t = 1;
    while(t--){
     solve();
    }
    return 0;
}

// Time Complexity: O(K * N + Q)
// Space Complexity: O(N + K)
// Pattern: Brute Force - Bounded mood simulation
// explanation:
/*
K is fixed at 2000. final_mood[x] is the mood after all n presents when the start value is x.
A present adds a while the mood is <= p, and otherwise subtracts b with a floor at 0.
Each start from 0 through K is simulated independently, so the table costs K passes over the presents.
A query with x <= K prints the stored mood.
A query above K prints x plus final_mood[K] - K, reusing the net shift measured at the top of the table.
*/
