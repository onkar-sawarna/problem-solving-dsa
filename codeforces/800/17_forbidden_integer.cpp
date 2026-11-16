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
   int n,k,x;
   cin>>n>>k>>x;

   if(x!=1){
    cout<<"Yes"<<endl;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<1<<" ";
    }cout<<endl;
    return;
   }else{
    if(k==1 || (k==2 and n%2==1)){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        if(n%2 == 0){
            cout<<n/2<<endl;
            for(int i=0;i<n/2;i++){
                   cout<<2<<" ";      
            }
            cout<<endl; 
        }else{
            cout<<(n-3)/2+1<<endl;
            for(int i=1;i<=(n-3)/2;i++){
                cout<<2<<" ";
            }
            cout<<3<<endl;
        }
    }
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

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Constructive - Sum without x
// explanation:
/*
When x is not 1, the sum is n ones.
When x is 1, k == 1 cannot form any positive sum, and k == 2 cannot form an odd n, so both print No.
An even n is built from n / 2 twos.
An odd n is built from twos plus a final 3, which needs k at least 3.
*/
