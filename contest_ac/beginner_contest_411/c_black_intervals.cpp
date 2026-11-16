#include <bits/stdc++.h>
using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<bool> squares(N + 2, false); 
    int blackIntervalsCount = 0;

    for (int k = 0; k < Q; ++k) {
        int flippedSquareIndex;
        cin >> flippedSquareIndex;

        bool wasBlack = squares[flippedSquareIndex];

        if (!wasBlack) {
            squares[flippedSquareIndex] = true; 

            if (!squares[flippedSquareIndex - 1]) {
                blackIntervalsCount++;
            }
            if (squares[flippedSquareIndex + 1]) {
                blackIntervalsCount--;
            }
        } else {
            squares[flippedSquareIndex] = false; 

            if (!squares[flippedSquareIndex - 1]) {
                blackIntervalsCount--;
            }
            if (squares[flippedSquareIndex + 1]) {
                blackIntervalsCount++;
            }
        }
        cout << blackIntervalsCount << "\n";
    }
}

signed main()
{
    IOS;
    int t = 1; 
    while(t--){
        solve();
    }
    return 0;
}

// Time Complexity: O(N + Q)
// Space Complexity: O(N)
// Pattern: Math - Neighbor flips
// explanation:
/*
squares[0] and squares[N + 1] stay false, so the neighbor tests need no extra edge cases.
Turning a white cell black adds an interval when the left neighbor is white, and cancels one when the right neighbor is already black, which is a merge.
Turning a black cell white removes an interval when the left neighbor is white, and adds one when the right neighbor is black, which is a split.
Each query flips one cell, adjusts the counter from those two neighbors, and prints it.
The boolean array is allocated once for the whole row.
*/
