#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int q;
    cin >> q;

    deque<char> dq;
    for (char ch : s) {
        dq.push_back(ch);
    }

    bool flipped = false;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            flipped = !flipped;
        } else {
            int f;
            char c;
            cin >> f >> c;
            if (flipped) {
                f = 3 - f;
            }
            if (f == 1) {
                dq.push_front(c);
            } else {
                dq.push_back(c);
            }
        }
    }
    if(flipped){
       for(auto it=dq.rbegin();it!=dq.rend();it++)cout<<*it; 
    }else{
      for (char ch : dq)cout << ch;
    }
    return 0;
}