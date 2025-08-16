#include <bits/stdc++.h>
using namespace std;

int n,k;

// declare the DS.
vector<int> queens;
void printer(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==queens[i]){
                cout<<"Q";
            }else{
                cout<<".";
            }   
        }
        cout<<endl;
    }
    cout<<endl;
}

bool check(int row,int col){
    for(int prow=0;prow<row;prow++){
        int pcol = queens[prow];
        if(pcol==-1) continue;
        if(pcol==col || abs(prow-row) == abs(pcol-col))
            return false;
    }
    return true;
}

//vector<vector<int>> allsol;

// framework
void rec(int level,int qleft){
    // base case
    if(level==n){
        if(qleft==0) {
            printer();
            // allsol.push_back(queens);
        }
        return;
    }
    // recursive
    // loop on choices
    
    // don't place a queen 
    queens.push_back(-1);
    rec(level+1, qleft);
    queens.pop_back();
    
    if(qleft>0){
        for(int col=0;col<n;col++){
            // check if its valid
            if(check(level,col)){
                // make the move
                queens.push_back(col);
                rec(level+1, qleft-1);
                queens.pop_back();
            }
        }
    }
    
}


int main()
{
    cin>>n>>k;
    rec(0,k);
    //cout<<allsol.size()<<endl;

    return 0;
}