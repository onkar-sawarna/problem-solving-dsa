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