// https://www.interviewbit.com/problems/distribute-candy/

// First give all kids 1 candy.
// Iterate and make sure kids with more rating than their left neighbour have 1 more candy than them
// Iterate Backward and make sure kids with more rating than their right neighbour have more candy than them (if they
// already do, dont change)

int Solution::candy(vector<int> &arr) {
    int n = arr.size();

    vector<int> candies(n, 1);
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {  // if current rating is greater, then prev + 1, else remain 1
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Now, all kids with higher rating than their left neighbours have more candies
    // So, Iterate backward, kids with more rating than right neighbour should have more candies
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int ans = 0;
    for (int i : candies) ans += i;
    return ans;
}
