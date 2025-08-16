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
