// Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has
// an index smaller than i.

// G[i] for an element A[i] = an element A[j] such that
//     j is maximum possible AND
//     j < i AND
//     A[j] < A[i]

// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> prevSmaller(vector<int> &arr) {
    vector<int> ans(arr.size());
    stack<int> s;

    s.push(-1);
    for (int i = 0; i < arr.size(); i++) {
        while (s.top() >= arr[i]) s.pop();
        ans[i] = s.top();

        s.push(arr[i]);
    }

    return ans;
}
