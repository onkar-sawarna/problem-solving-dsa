#include <bits/stdc++.h>
using namespace std;

int n;

// declare the DS.
vector<int> queens;
void printer(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<queens.size() && j==queens[i]){
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
        if(pcol==col || abs(prow-row) == abs(pcol-col))
            return false;
    }
    return true;
}

vector<vector<int>> allsol;

// framework
void rec(int level){
    //printer();
    // base case
    if(level==n){
        printer();
        allsol.push_back(queens);
        return;
    }
    // recursive
    // loop on choices
    for(int col=0;col<n;col++){
        // check if its valid
        if(check(level,col)){
            // make the move
            queens.push_back(col);
            rec(level+1);
            queens.pop_back();
        }
    }
}


int main()
{
    cin>>n;
    rec(0);
    cout<<allsol.size()<<endl;

    return 0;
}