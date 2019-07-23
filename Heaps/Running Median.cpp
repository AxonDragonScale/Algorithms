
// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0
// https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/

vector<double> runningMedian(vector<int> a) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;

    vector<double> result(a.size());

    maxHeap.push(a[0]);
    result[0] = (double)maxHeap.top();
    for (int i = 1; i < a.size(); i++) {
        if (minHeap.size() == maxHeap.size()) {
            if (a[i] > minHeap.top()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();

                minHeap.push(a[i]);
            } else {
                maxHeap.push(a[i]);
            }

            result[i] = (double)maxHeap.top();
        } else {
            if (maxHeap.top() < a[i]) {
                minHeap.push(a[i]);
            } else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();

                maxHeap.push(a[i]);
            }

            result[i] = ((double)minHeap.top() + (double)maxHeap.top()) / 2;
        }
    }
    return result;
}

// or

#include <algorithm>
#include <climits>
#include <queue>
#include <string>
#include <vector>

#define LN cout << __LINE__ << endl
#define iPair pair<int, int>
#define ff first
#define ss second

using namespace std;

int main() {
    int n, temp;
    cin >> n;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int median = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> temp;

        if (maxHeap.size() == minHeap.size()) {
            if (temp < median) {
                maxHeap.push(temp);
            } else {
                minHeap.push(temp);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            median = maxHeap.top();
        } else if (maxHeap.size() == minHeap.size() + 1) {
            if (temp < median) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(temp);
            } else {
                minHeap.push(temp);
            }
            median = (maxHeap.top() + minHeap.top()) / 2;
        }

        cout << median << endl;
    }

    return 0;
}
