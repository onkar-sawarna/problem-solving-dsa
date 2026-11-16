// Question: Merge two sorted arrays into the first array, which already has enough extra space at the end.
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

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;         // pointer for end of initial nums1
    int j = n - 1;         // pointer for end of nums2
    int k = m + n - 1;     // pointer for end of merged nums1

    // Merge from the back
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    // Copy any remaining elements of nums2 (if any)
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
    // No need to copy nums1's elements, as they are already in place
}

void solve(){
    vi arr1 = {1,2,3,4,5};
    arr1.resize(11);
    vi arr2 = {3,4,5,6,7,8};
    merge(arr1,5,arr2,6);
    vout(arr1);
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

// Time Complexity: O(m + n)
// Space Complexity: O(1)
// Pattern: Two Pointers - Backward Merge
// explanation:
/*
nums1 already has room for both arrays, so the merge writes from the last index backward.
The larger of the two remaining tails is placed, and that pointer moves left.
A leftover tail of nums2 is copied into the front, while a leftover tail of nums1 is already home.
The only extra state is the three indexes.
*/
