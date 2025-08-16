#include <bits/stdc++.h>
using namespace std;

void longestUniformSubstring(string s){
  int n = s.size();
  if(n == 0) cout<<"0 0"<<endl;
  
  int maxStart = 0, maxLen = 1;
  int currStart = 0, currLen = 1;

  for(int i=1;i<n;i++){
    if(s[i]==s[i-1]){
      currLen++;
    }else{
      if(currLen > maxLen){
        maxLen = currLen;
        maxStart = currStart;
      }
      currStart = i;
      currLen = 1;
    }
  }
   //check at the end
   if(currLen > maxLen){
    maxLen = currLen;
    maxStart = currStart;
   }
  cout<<maxStart<<" "<<maxLen;
}

// To execute C++, please define "int main()"
int main() {
  string s="aabBbBbCdAA";
  //cin>>s;
  longestUniformSubstring(s);
  return 0;
}


/**
 * Instructions to candidate.
 *  1) Run this code in the REPL to observe its behaviour. The
 *     execution entry point is main().
 *  2) Your task is to implement the following method ('longestUniformSubstring') 
 *  
 *  This method should return an integer array with two elements that correctly identifies the location of the longest 
 *  uniform substring within the input string. The first element of the array should be the starting index of the longest 
 *  substring and the second element should be the length.
 *  
 *  e.g.
 *      
 *      for the input: "abbbccda" the longest uniform substring is "bbb" (which starts at index 1 and is 3 characters long).
 *
 *  3) If time permits, add some additional test cases.
 */