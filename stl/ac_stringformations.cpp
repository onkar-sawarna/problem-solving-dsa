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

// Time Complexity: O(n + q)
// Space Complexity: O(n + q)
// Pattern: Deque - Lazy reversal
// explanation:
/*
The starting string is copied into a deque.
Type 1 only toggles flipped, so the characters are not reversed in place.
Type 2 pushes the new character to the front or the back, and flipped swaps those two sides before the push.
The final walk prints the deque forward, or backward when flipped is set.
Each query is a constant-time deque update, and the deque stores the original characters plus every insertion.
*/
