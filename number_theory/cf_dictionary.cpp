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

// Time Complexity: O(t)
// Space Complexity: O(1)
// Pattern: Brute Force - Letter pair list
// explanation:
/*
generate_berland_strings fills a fixed table of the 26*25 two-letter words whose letters differ.
Each of the t tests walks that table from index 1 until the input word matches.
The table size does not depend on t, so a query is a short scan of a constant list.
The word array is allocated once and reused for every test.
*/
