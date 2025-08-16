#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long // This means all 'int's below are 'long long'
#define endl "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

// MyHashMap using Direct Addressing (suitable for keys in a small, non-negative range, e.g., 0 to 10^6)
class MyHashMap {
public:
    // Using a large array as the underlying data structure.
    // MAX_KEY_VALUE should be set based on the maximum possible key.
    // For keys up to 10^6, this array size is feasible (approx 8MB for long long).
    static const int MAX_KEY_VALUE = 1000001; // Adjust this based on problem constraints
    int data[MAX_KEY_VALUE];
    bool exists[MAX_KEY_VALUE]; // To distinguish between value 0 and non-existent

    // Constructor: Initializes all elements to a default "not found" state.
    MyHashMap() {
        // std::fill works for primitive arrays
        fill(data, data + MAX_KEY_VALUE, 0); // Default value, assuming 0 is a valid value
        fill(exists, exists + MAX_KEY_VALUE, false); // Mark all keys as not existing
    }

    void put(int key, int val) {
        if (key >= 0 && key < MAX_KEY_VALUE) { // Basic bounds check
            data[key] = val;
            exists[key] = true;
        }
    }

    int get(int key) {
        if (key >= 0 && key < MAX_KEY_VALUE && exists[key]) {
            return data[key];
        }
        // Return a special value (e.g., -1, or some other predefined "not found" value)
        // Make sure this "not found" value doesn't conflict with possible valid values.
        return -1; // Assuming -1 means not found. Adjust if 0 or other values can be valid.
    }

    void remove(int key) {
        if (key >= 0 && key < MAX_KEY_VALUE) {
            exists[key] = false; // Simply mark as not existing
            // Optionally, data[key] can be reset to 0 or some default, but not strictly necessary for removal.
        }
    }
};

void solve(){
    // Example usage of MyHashMap (Direct Addressing)
    MyHashMap* obj = new MyHashMap(); // Using 'new'
    obj->put(1, 10);
    cout << "Put (1, 10)" << endl;

    cout << "Get(1): " << obj->get(1) << endl; // Expected: 10
    cout << "Get(5): " << obj->get(5) << endl; // Expected: -1

    obj->put(5, 500);
    cout << "Put (5, 500)" << endl;
    cout << "Get(5): " << obj->get(5) << endl; // Expected: 500

    obj->remove(1);
    cout << "Removed key 1" << endl;
    cout << "Get(1) after removal: " << obj->get(1) << endl; // Expected: -1

    obj->put(1000000, 999999);
    cout << "Put (1000000, 999999)" << endl;
    cout << "Get(1000000): " << obj->get(1000000) << endl; // Expected: 999999

    delete obj; // Clean up
}

signed main()
{
    IOS;
    int t;
    t=1;
    while(t--){
     solve();
    }
    return 0;
}