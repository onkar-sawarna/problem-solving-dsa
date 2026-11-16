// Question: Add integers from a data stream and report the median of all numbers added so far.
#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // larger half

public:
    MedianFinder() {
        // Constructor
    }
    
    void addNum(int num) {
        maxHeap.push(num);

        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int topMax = maxHeap.top();
            maxHeap.pop();
            minHeap.push(topMax);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            int topMax = maxHeap.top();
            maxHeap.pop();
            minHeap.push(topMax);
        }
        if (minHeap.size() > maxHeap.size()) {
            int topMin = minHeap.top();
            minHeap.pop();
            maxHeap.push(topMin);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

int main() {
    MedianFinder mf;

    mf.addNum(1);
    cout << "Median after adding 1: " << mf.findMedian() << endl;  // Output: 1

    mf.addNum(2);
    cout << "Median after adding 2: " << mf.findMedian() << endl;  // Output: 1.5

    mf.addNum(3);
    cout << "Median after adding 3: " << mf.findMedian() << endl;  // Output: 2

    mf.addNum(4);
    cout << "Median after adding 4: " << mf.findMedian() << endl;  // Output: 2.5

    mf.addNum(5);
    cout << "Median after adding 5: " << mf.findMedian() << endl;  // Output: 3

    return 0;
}

// Time Complexity: O(log n) per insertion
// Space Complexity: O(n)
// Pattern: Two Heaps - Median Stream
// explanation:
/*
The smaller half is a max-heap and the larger half is a min-heap.
addNum pushes the new value and moves at most a few roots so the halves stay ordered.
The two sizes differ by at most one, and each heap operation costs log of the number inserted so far.
findMedian reads the max-heap root, or the average of both roots, in constant time.
*/
