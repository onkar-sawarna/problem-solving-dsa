#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        //contribution technique problem
        long long appealSum(string s) {
            long long int n=s.size();
            long long int substring[26] = {0ll};
            long long int total = (n*(n+1)/2);
            for(int i=0;i<26;i++){
                char ch = 'a'+i;
                long long int cnt = 0ll;
                long long int sum = 0ll;
                for(int j=0;j<n;j++){
                    if(s[j] != ch)cnt++;
                    else{
                      sum+=(cnt*(cnt+1)/2);
                      cnt=0ll;
                    }
                }
                if(cnt!=0ll)sum+=(cnt*(cnt+1)/2);
                substring[i] = total-sum;
            }
            long long ans = 0ll;
            for(int i=0;i<26;i++)ans+=substring[i];
            return ans;
        }
    };