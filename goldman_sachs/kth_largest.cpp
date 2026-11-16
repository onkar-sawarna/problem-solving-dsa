// Question: Find the kth largest element in an unsorted array.
#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl  "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "
using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;

int findKthLargest(vector<int>& nums, int k) {
    // Create a min-priority queue.
    // The third template argument 'greater<int>' makes it a min-heap.
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int num : nums) {
        // Add the current number to the heap
        min_heap.push(num);

        // If the heap size exceeds k, remove the smallest element
        // This ensures the heap always contains the k largest elements seen so far
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    // The top element of the min-heap is the kth largest element
    return min_heap.top();
}
void solve(){
  vi input = {1,3,4,7,5,23,17,54,22};
  cout<<findKthLargest(input,4)<<endl;
}

signed main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
     solve();
    }
    return 0;
}

// Time Complexity: O(n log k)
// Space Complexity: O(k)
// Pattern: Heap - Kth Largest
// explanation:
/*
A min-heap keeps only the k largest values seen so far.
Each of the n numbers is pushed, and the root is popped once the heap grows past k.
The root is then the kth largest value.
Every push and pop is logarithmic in the heap size, which stays at most k.
*/
