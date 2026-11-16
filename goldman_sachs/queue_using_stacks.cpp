// Question: Implement a first-in first-out queue with push, pop, peek, and empty, using only stacks.
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


class MyQueue {
private:
    stack<int> inStack;   // For push operations
    stack<int> outStack;  // For pop and peek operations
    
    // Helper function to move elements from inStack to outStack
    void moveInToOut() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        moveInToOut();
        int val = outStack.top();
        outStack.pop();
        return val;
    }
    
    int peek() {
        moveInToOut();
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

signed main() {
    MyQueue q;
    
    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    
    // Display front element
    cout << "Front element: " << q.peek() << endl;  // Should print 10
    
    // Pop elements and print them
    cout << "Pop element: " << q.pop() << endl;     // Should print 10
    cout << "Pop element: " << q.pop() << endl;     // Should print 20
    
    // Check if queue is empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;  // Should print No
    
    // Pop last element
    cout << "Pop element: " << q.pop() << endl;     // Should print 30
    
    // Check if queue is empty again
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;  // Should print Yes
    
    return 0;
}

// Time Complexity: O(1) amortized
// Space Complexity: O(n)
// Pattern: Two Stacks - Queue Simulation
// explanation:
/*
push writes the new value onto inStack.
pop and peek pour inStack onto outStack only when outStack is empty, reversing that batch into queue order.
Each value is moved from inStack to outStack once, so a sequence of operations is amortized constant time.
The two stacks together hold every value still in the queue.
*/
