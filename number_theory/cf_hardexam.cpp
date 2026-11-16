// Question: What is the last digit of 1378 raised to the power n?
#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    cin>>n;
    int base = 1378%10;
    if(n==0)
    {cout<<"1"<<"\n"; 
        return;
    }
    n=n%4;
    if(n==0)n=4;
    int last_digit = 1;
    for(int i=0;i<n;i++){
        last_digit = (last_digit*base)%10;
    }
    cout<<last_digit<<"\n";
}

signed main(){
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
// Pattern: Number Theory - Last digit cycle
// explanation:
/*
Only the last digit of 1378^n is required, and that digit repeats every 4 multiplications.
n is reduced modulo 4, and a multiple of 4 is mapped to the fourth place in the cycle.
The last digit is then multiplied by 8 at most four times.
n == 0 is printed as 1. A few integers are enough.
*/
