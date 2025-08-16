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
    char matrix[10][10]; // Matrix size should be 10x10 as per loops
    for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
          cin >> matrix[i][j];
      }
    }
  
    int total_points = 0;
    for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
          if(matrix[i][j] == 'X'){
              // Calculate the minimum distance from any of the four boundaries
              int min_dist_row = min(i, 9 - i); // Distance from top or bottom
              int min_dist_col = min(j, 9 - j); // Distance from left or right
  
              // The layer index (0-indexed) is the minimum of these distances
              int layer = min(min_dist_row, min_dist_col);
  
              // Points for an 'X' at this layer (layer 0 gets 1 point, layer 1 gets 2 points, etc.)
              total_points += (layer + 1);
          }
      }
    }
    cout << total_points << endl; // You need to print the total_points
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