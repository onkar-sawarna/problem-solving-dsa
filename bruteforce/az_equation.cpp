// abcde/fghij = n 
#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
   int n;
   cin>>n;
   string s = "0123456789";
   do{
     int num = stoi(s.substr(0,5));
     int den = stoi(s.substr(5,5));
     if(num%den==0 and num/den==n){
        cout<<num<<" "<<den<<"\n";
     }
   }while(next_permutation(s.begin(),s.end()));
}
void solve2(){
    int n;
    cin>>n;
    for(int fghij=01234;fghij<=98765/n;fghij++){
        int abcde = fghij*n;
        set<int> st;
        int temp;
        temp=fghij;
        for(int i=0;i<5;i++){
            int r=temp%10;
            temp/=10;
            st.insert(r);
        }
        temp=abcde;
        for(int i=0;i<5;i++){
            int r=temp%10;
            temp/=10;
            st.insert(r);
        }
        if(st.size()==10)cout<<abcde<<" "<<fghij<<"\n";
    }
 }

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve2();
    }
    return 0;
}

// Time Complexity: O(10^5)
// Space Complexity: O(1)
// Pattern: Brute Force - Digit products
// explanation:
/*
main calls solve2. fghij runs up to 98765/n, and abcde is fghij * n.
Each candidate inserts the ten digits of the two numbers into a set.
A set of size 10 means the pair uses every digit once, and both numbers are printed.
The unused solve walks permutations of the ten digit characters instead of this numeric range.
The set never holds more than ten digits.
*/
