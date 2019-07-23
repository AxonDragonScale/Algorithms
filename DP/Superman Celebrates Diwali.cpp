// https://www.hackerrank.com/challenges/superman-celebrates-diwali/problem

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

int main() {
    int buildings, height, heightLost;
    cin >> buildings >> height >> heightLost;

    vector<vector<int>> people(buildings, vector<int>(height + 1, 0));
    // people[b][h] is the no of people in building b at height h

    for (int i = 0; i < buildings; i++) {
        int numPeople, floor;
        cin >> numPeople;

        for (int j = 0; j < numPeople; j++) {
            cin >> floor;
            people[i][floor]++;
        }
    }

    vector<int> heightDP(height + 1, 0);
    // max no of people that can be saved if we are at height h at (any building)
    vector<vector<int>> dp(buildings, vector<int>(height + 1, 0));
    // max people that can be saved if we are at building b at height h
    for (int h = 1; h <= height; h++) {
        for (int b = 0; b < buildings; b++) {
            dp[b][h] = max(dp[b][h - 1], h - heightLost > 0 ? heightDP[h - heightLost] : 0);
            dp[b][h] += people[b][h];

            heightDP[h] = max(heightDP[h], dp[b][h]);
        }
    }

    cout << heightDP[height] << endl;

    return 0;
}
