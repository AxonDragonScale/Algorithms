// https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

vector<int> Solution::lszero(vector<int> &arr) {
    int n = arr.size();

    int sum = 0, start = 0, end = -1;
    map<int, int> sumIdx;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sumIdx.find(sum) != sumIdx.end()) {  // if sum is same, then sum of element between is 0
            if (i - (sumIdx[sum] + 1) > end - start) {
                end = i;
                start = sumIdx[sum] + 1;
            }
        } else {
            sumIdx[sum] = i;
        }

        if (sum == 0) {  // we can also insert 0, -1 into the map instead of this
            start = 0;
            end = i;
        }
    }

    vector<int> ans;
    for (int i = start; i <= end; i++) {
        ans.push_back(arr[i]);
    }
    return ans;
}

// vector<int> Solution::lszero(vector<int> &arr) {
//     int n = arr.size();

//     int sum = 0, start = 0, end = -1;
//     map<int, int> sumIdx;
//     for(int i = 0; i<=n; i++) {
//         if(sumIdx.find(sum) != sumIdx.end()) {
//             if(i-(sumIdx[sum]) > end-start) {
//                 end = i; start = sumIdx[sum];
//             }
//         } else {
//             sumIdx[sum] = i;
//         }

//         if(i<n) sum += arr[i];
//     }

//     vector<int> ans;
//     for(int i = start; i<end; i++) {
//         ans.push_back(arr[i]);
//     }
//     return ans;
// }
