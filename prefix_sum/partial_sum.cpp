// Question: What is the array after each update adds a value to every position in an inclusive range?
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N, 0); // Initialize the array with zeros

    // Process queries
    while (Q--) {
        int L, R, x;
        cin >> L >> R >> x;

        // Update the partial sum array
        arr[L - 1] += x;
        if (R < N) {
            arr[R] -= x;
        }
    }

    // Compute final array using partial sum
    for (int i = 1; i < N; ++i) {
        arr[i] += arr[i - 1];
    }

    // Print the final array
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}

// Time Complexity: O(N + Q)
// Space Complexity: O(N)
// Pattern: Difference array - Range add
// explanation:
/*
Each of the Q updates adds x at arr[L - 1] and, when R is inside the array, subtracts x at arr[R].
Those two positions mark where the added range starts and where it stops.
A single scan from index 1 to N - 1 adds arr[i - 1] into arr[i].
After that scan every position holds the total of the updates that cover it.
*/
