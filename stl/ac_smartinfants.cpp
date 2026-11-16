#include <bits/stdc++.h>
using namespace std;
#define int long long 

int rating[200200];
int current_school[200200];

multiset<int> school_ratings[200200];
multiset<int> highest_ratings;

void reg(int kid,int school){
    //first erase
   if(school_ratings[school].size() > 0){
     int highest = *(school_ratings[school].rbegin());
     highest_ratings.erase(highest_ratings.find(highest));
   }
   //then insert
   school_ratings[school].insert(rating[kid]);
   //then update
   if(school_ratings[school].size() > 0){
    int highest = *(school_ratings[school].rbegin());
    highest_ratings.insert(highest);
  }
}

void dereg(int kid,int school){
     //first erase
   if(school_ratings[school].size() > 0){
    int highest = *(school_ratings[school].rbegin());
    highest_ratings.erase(highest_ratings.find(highest));
  }
  //then remove
  school_ratings[school].erase(rating[kid]);
  //then update
  if(school_ratings[school].size() > 0){
    int highest = *(school_ratings[school].rbegin());
    highest_ratings.insert(highest);
  }
}

int get_evenness(){
    return *(highest_ratings.begin());
}
signed main()
{   
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>rating[i]>>current_school[i];
        reg(i,current_school[i]);
    }
    while(q--){
        int c, d;
        cin>>c>>d;
        dereg(c,current_school[c]);
        current_school[c] = d;
        reg(c,current_school[c]);
        cout<<get_evenness()<<endl;
    }
    
}

// Time Complexity: O((n + q) log n)
// Space Complexity: O(n)
// Pattern: Multiset - School maxima
// explanation:
/*
Each school has a multiset of its children's ratings, and highest_ratings keeps one maximum per non-empty school.
reg and dereg drop the old school maximum, edit that school's multiset, then insert the new maximum.
A move is one dereg plus one reg, and get_evenness reads the smallest school maximum.
erase(rating[kid]) removes every equal rating in that school, so a tied rating costs more than a single node.
The multisets hold the n ratings.
*/
