// https://www.interviewbit.com/problems/subset/
// https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/

// method 1 - subsets in lexicographic order

// void util(vector<int> &arr, int start, vector<int> &cur, vector<vector<int>> &ans) {
//     ans.push_back(cur);

//     for(int i = start; i<arr.size(); i++) {
//         cur.push_back(arr[i]);
//         util(arr, i+1, cur, ans);
//         cur.pop_back();
//     }

//     return;
// }

// vector<vector<int> > Solution::subsets(vector<int> &arr) {
//     sort(arr.begin(), arr.end());

//     vector<vector<int>> ans;
//     vector<int> cur;
//     util(arr, 0, cur, ans);

//     return ans;
// }

// method 2 - Iterative (Use if you want ordering on length or dont need lexicographic order)
// bad bcoz we have sort ans which is 2^n in size

// vector<vector<int> > Solution::subsets(vector<int> &arr) {
//     sort(arr.begin(), arr.end());
//     long long int p = pow(2, arr.size());

//     vector<vector<int>> ans;
//     vector<int> cur;
//     for(int i = 0; i<p; i++) {
//         for(int j = 0; j<arr.size(); j++) {
//             if(i & 1<<j) {
//                 cur.push_back(arr[j]);
//             }
//         }

//         ans.push_back(cur);
//         cur.clear();
//     }

//     sort(ans.begin(), ans.end());    // remove if you dont need lexicographic order and need length based order
//     return ans;
// }

// If we dont sort ans, subsets will be in order of increasing length

// method 3 - bad bcoz we have sort ans which is 2^n in size

// void util(vector<int> &arr, int start, vector<int> &cur, vector<vector<int>> &ans) {
//     if(start == arr.size()) {
//         ans.push_back(cur);
//         return;
//     }

//     util(arr, start+1, cur, ans);
//     cur.push_back(arr[start]);
//     util(arr, start+1, cur, ans);

//     cur.pop_back();
// }

// vector<vector<int> > Solution::subsets(vector<int> &arr) {
//     sort(arr.begin(), arr.end());

//     vector<vector<int>> ans;
//     vector<int> cur;
//     util(arr, 0, cur, ans);

//     sort(ans.begin(), ans.end());
//     return ans;
// }

// If we dont sort ans, subsets will be in WEIRD order -
