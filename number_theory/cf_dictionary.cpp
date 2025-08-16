#include <bits/stdc++.h>
using namespace std;
#define int long long 
void generate_berland_strings(string word[]) {
    int index = 1; // Start from index 1, as per your original code
    for (char firstChar = 'a'; firstChar <= 'z'; ++firstChar) {
        for (char secondChar = 'a'; secondChar <= 'z'; ++secondChar) {
            if (firstChar != secondChar) {
                word[index] = string(1, firstChar) + secondChar;
                index++;
            }
        }
    }
}
void solve(string word[]){
   string s;
   cin>>s;
   for(int i=1;i<=650;i++){
    if(word[i] == s){
        cout<<i<<"\n";
        return;
    }
   }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    string word[700];
    generate_berland_strings(word);
    while(t--){
        solve(word);
    }
    return 0;
}