// Best Time to Buy and Sell Stocks I

// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/
// Given an array with prices of stocks on n days, find the max profit if you can buy and sell only once.
int Solution::maxProfit(const vector<int> &arr) {
    int n = arr.size();
    int profit = 0;

    int minIdx = 0, maxIdx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < arr[minIdx]) {
            minIdx = i;
            maxIdx = i;
        } else if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }

        profit = max(profit, arr[maxIdx] - arr[minIdx]);
    }

    return profit;
}

// Best Time to Buy and Sell Stocks II

// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/
// Given an array with prices of stocks on n days, find the max profit if you can buy and sell infinte times.
int Solution::maxProfit(const vector<int> &arr) {
    int n = arr.size();
    int profit = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1]) profit += arr[i] - arr[i - 1];
    }

    return profit;
}

// Best Time to Buy and Sell Stocks III

// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/
// https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/
// Given an array with prices of stocks on n days, find the max profit if you can buy and sell only twice.
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
int Solution::maxProfit(const vector<int> &prices) {
    int n = prices.size();
    if (n <= 1) return 0;

    vector<int> profit(n, 0);

    // Get max profit with one transaction
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (prices[i] > maxPrice) maxPrice = prices[i];

        // Buy later profit (already calculated) or buy at prices[i] and sell at maxPrice
        profit[i] = max(profit[i + 1], maxPrice - prices[i]);
    }
    // profit[i] has max profit for i..n-1, i.e, buy at or after i

    // Get max profit for second transaction
    int minPrice = prices[0];
    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) minPrice = prices[i];

        // profit for i-1 or sell at prices[i]
        profit[i] = max(profit[i - 1], profit[i] + (prices[i] - minPrice));
    }

    return profit[n - 1];
}

// Buy and Sell stocks k times

// https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-k-times/
// Given the stock price of n days, the trader is allowed to make at most k transactions, where a new transaction can
// only start after the previous transaction is complete, find out the maximum profit

int maxProfit(const vector<int> &prices, int k) {
    int n = prices.size();

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    // dp[t][i] stores max profit using t transactions for first i days
    // base cases - dp[t][0] = 0, no profit on day 0 and dp[0][i] = 0, no profit if there are no transactions

    for (int t = 1; t <= k; t++) {
        int prevDiff = INT_MIN;
        for (int i = 0; i < n; i++) {
            prevDiff = max(prevDiff, dp[t - 1][i - 1] - prices[i - 1]);
            dp[t][i] = max(profit[t][i - 1], prevDiff + prices[i]);
        }
    }

    return dp[k][n - 1];
}