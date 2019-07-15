// https://www.interviewbit.com/problems/gas-station/

// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station
// (i+1). You begin the journey with an empty tank at one of the gas stations. Return the minimum starting gas station’s
// index if you can travel around the circuit once, otherwise return -1. You can only travel in one direction. i to i+1,
// i+2, ... n-1, 0, 1, 2.. Completing the circuit means starting at i and ending up at i again.

//  Greedily, if your tank becomes empty, start from the next station
int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int n = gas.size();

    int totalGas = 0, totalCost = 0, tank = 0, start = 0;
    for (int i = 0; i < n; i++) {
        totalGas += gas[i];
        totalCost += cost[i];

        tank += gas[i] - cost[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    if (totalGas - totalCost < 0)
        return -1;
    else
        return start;
}

// Actually trying all starting points and checking if tank goes empty
int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int n = gas.size();

    vector<int> res(2 * n);
    for (int i = 0; i < n; i++) {
        res[i] = gas[i] - cost[i];
        res[n + i] = res[i];
    }

    for (int i = 0; i < n; i++) {
        int tank = 0;
        int j = i;
        while (j < i + n) {
            tank += res[j++];
            if (tank < 0) break;
        }

        if (tank >= 0) return i;
    }

    return -1;
}

https:  // www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/  -> Different Method