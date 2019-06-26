// https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/
// Given three prime number(p1, p2, p3) and an integer k. Find the first(smallest) k integers which have only p1, p2, p3
// or a combination of them as their prime factors.

vector<int> Solution::solve(int a, int b, int c, int k) {
    vector<int> primes = {a, b, c};
    sort(primes.begin(), primes.end());

    vector<int> ans;
    set<int> s;

    for (int i = 0; i < 3; i++) {
        s.insert(primes[i]);
    }

    auto it = s.begin();
    while (ans.size() != k) {
        int min = *it;

        ans.push_back(min);
        for (int i = 0; i < 3; i++) {
            s.insert(min * primes[i]);  // new inserted elements will be after 'it' as they are greater
        }
        it++;  // we can just go to next instead of erase previous min
    }

    return ans;
}

// vector<int> Solution::solve(int a, int b, int c, int k) {
//     vector<int> primes = {a, b, c};
//     sort(primes.begin(), primes.end());

//     vector<int> ans;
//     set<int> s;

//     for(int i = 0; i<3; i++) {
//         s.insert(primes[i]);
//     }

//     while(ans.size() != k) {
//         int temp = *s.begin();
//         s.erase(s.begin());

//         ans.push_back(temp);

//         for(int i = 0; i<3; i++) {
//             s.insert(temp*primes[i]);
//         }
//     }

//     return ans;
// }

// vector<int> Solution::solve(int a, int b, int c, int k) {
//     vector<int> primes = {a, b, c};
//     sort(primes.begin(), primes.end());

//     priority_queue<int, vector<int>, greater<int>> minHeap;
//     set<int> used;

//     for(int i = 0; i<3; i++) {
//         minHeap.push(primes[i]);
//     }

//     while(used.size() != k) {
//         int temp = minHeap.top();
//         minHeap.pop();
//         used.insert(temp);

//         for(int i = 0; i<3; i++) {
//             if(used.find(temp*primes[i]) == used.end()) {
//                 minHeap.push(temp*primes[i]);
//             }
//         }
//     }

//     return vector<int>(used.begin(), used.end());
// }
