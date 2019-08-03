// https://www.interviewbit.com/problems/maximum-frequency-stack

// we maintain a stack for each frequency, and if an element occurs k times it will be in all stacks of freq 1 to k.
// we maintain maxfreq and pop from that stack, decrement it if it becomes empty
vector<int> Solution::solve(vector<vector<int>> &operations) {
    vector<int> ans;

    unordered_map<int, int> freq;              // element to frequency
    unordered_map<int, stack<int>> freqStack;  // frequency to stack of elements with that freq

    int maxFreq = 0;
    for (int i = 0; i < A.size(); i++) {
        int opt = A[i][0];
        int elem = A[i][1];

        if (opt == 1) {
            freq[elem]++;
            maxFreq = max(maxFreq, freq[elem]);
            freqStack[freq[elem]].push(elem);

            ans.push_back(-1);
        } else if (opt == 2) {
            int x = freqStack[maxFreq].top();
            freqStack[maxFreq].pop();
            freq[x]--;
            if (freqStack[maxFreq].size() == 0) maxFreq--;

            ans.push_back(x);
        }
    }
    return ans;
}
