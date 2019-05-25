// https://www.geeksforgeeks.org/job-sequencing-problem/

// This is O(n^2). Disjoint set method is better

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define LN cout << __LINE__ << endl
#define ff first
#define ss second

using namespace std;

using iPair = pair<int, int>;
using vi = vector<int>;
using di = deque<int>;
using lli = long long int;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool comparator(const Job &a, const Job &b) { return a.profit > b.profit; }

int main() {
    int n, tId, tDeadline, tProfit, maxDeadline = 0;
    cin >> n;

    deque<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> tId >> tDeadline >> tProfit;
        jobs[i] = {tId, tDeadline, tProfit};
        maxDeadline = max(tDeadline, maxDeadline);
    }

    sort(jobs.begin(), jobs.end(), comparator);  // sort on profit

    int totalProfit = 0;
    deque<bool> slots(maxDeadline + 1, false);  // time slots for jobs
    deque<int> sequence(maxDeadline + 1, -1);
    for (int i = 0; i < n; i++) {
        int j = jobs[i].deadline;
        while (j > 0) {  // use the last time slot before the deadline
            if (slots[j] == false) {
                slots[j] = true;
                sequence[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            } else {
                j--;
            }
        }
    }

    // We can remove slots array and just use sequence array to check if that time slot is filled

    cout << "Job Sequence with profit " << totalProfit << " : ";
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << " ";
    }
    cout << endl;

    return 0;
}
