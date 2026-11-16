// Question: Return the total appeal of all substrings, where the appeal of a string is how many distinct characters it contains.
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

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Contribution - Letter Appeal
// explanation:
/*
Appeal of a substring is how many distinct letters it contains, so each letter is totaled on its own.
The string has n*(n+1)/2 substrings.
For one letter the scan sums the blocks that miss it, and the total minus that sum is the substrings that contain it.
Repeating the scan for all 26 letters and adding those counts is the appeal of every substring.
*/
