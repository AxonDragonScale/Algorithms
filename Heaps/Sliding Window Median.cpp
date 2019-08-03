// https://leetcode.com/problems/sliding-window-medianmultiset <double> m;

// Better, O(nlogn)
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> window(nums.begin(), nums.begin() + k);
    vector<double> medians;

    auto mid = next(window.begin(), k / 2);
    for (int i = k; i < nums.size(); i++) {
        medians.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);  // Push the current median.

        window.insert(nums[i]);
        if (nums[i] < *mid) mid--;       // what we add
        if (nums[i - k] <= *mid) mid++;  // what we remove
        // if we add and remove before mid, it remains same. if we add and remove after mid, it remains same
        // if we add before and remove after mid, mid--. if we add after and remove before mid, mid++

        window.erase(window.lower_bound(nums[i - k]));  // if we erase with value, it will delete all instances
    }

    return medians;
}

// simpler to understand, O(n^2 logn)
double findMedian(multiset<int>& m, double remove, double add) {
    m.insert(add);
    m.erase(m.find(remove));
    int n = m.size();
    double a = *next(m.begin(), n / 2 - 1);  // this is O(n)
    double b = *next(m.begin(), n / 2);
    return n & 1 ? b : (a + b) * 0.5;
}

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> m(nums.begin(), nums.end());
    vector<double> ans;

    if (nums.size() < k) return ans;

    for (int i = 0; i < k; i++) {
        m.insert(nums[i]);
    }

    ans.push_back(findMedian(0, 0));  // add 0 and remove 0, to get median of 1st k elements
    for (int i = k; i < nums.size(); i++) {
        ans.push_back(findMedian(nums[i - k], nums[i]));
    }
    return ans;
}

// ref -
// https://en.cppreference.com/w/cpp/iterator/prev
// https://en.cppreference.com/w/cpp/iterator/next