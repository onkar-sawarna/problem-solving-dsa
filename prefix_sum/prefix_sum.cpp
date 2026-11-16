// Question: What is the sum of the array from index L through index R for each query?
#include <iostream>
#include <vector>

using namespace std;

vector<int> calculatePrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n, 0);
    
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    
    return prefixSum;
}

int queryRangeSum(const vector<int>& prefixSum, int L, int R) {
    if (L == 0) {
        return prefixSum[R];
    } else {
        return prefixSum[R] - prefixSum[L - 1];
    }
}

int main() {
    // Example Usage
    vector<int> array = {1, 2, 3, 4, 5};
    vector<int> prefixSum = calculatePrefixSum(array);
    
    int Q;
    cout << "Enter the number of queries (Q): ";
    cin >> Q;

    while (Q--) {
        int L, R;
        cout << "Enter query in the form ?LR: ";
        cin >> L >> R;

        int result = queryRangeSum(prefixSum, L, R);
        cout << "Sum of elements in range [" << L << ", " << R << "]: " << result << endl;
    }

    return 0;
}

// Time Complexity: O(n + Q)
// Space Complexity: O(n)
// Pattern: Prefix sum - Range query
// explanation:
/*
calculatePrefixSum sets prefixSum[0] to arr[0], then each later index adds arr[i] onto prefixSum[i - 1].
queryRangeSum returns prefixSum[R] when L is 0.
For any later L it returns prefixSum[R] minus prefixSum[L - 1].
Each of the Q queries reads one or two of those already built cells.
*/
