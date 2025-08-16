#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    unordered_set<char> availablechars;
    char ch;
    int current_count=0,count=0;
    for(int i=0;i<k;i++){
        cin>>ch;
        availablechars.insert(ch);
    }
    for(int i=0;i<s.size();i++){
        if(availablechars.count(s[i])){
            current_count++;
        }else{
            count+=((current_count+1)*current_count)/2;
            current_count = 0;
        }
    }
    count+=((current_count+1)*current_count)/2;
    cout<<count<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}