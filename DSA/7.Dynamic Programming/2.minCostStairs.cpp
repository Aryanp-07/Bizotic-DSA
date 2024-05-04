//* Leetcode 746. Min Cost Climbing Stairs
#include <iostream>
#include <vector>
using namespace std;

//* Recursion
int recurMinCost(vector<int> &cost, int n)
{
    if (n == 0 || n == 1)
        return cost[n];
    return cost[n] + min(recurMinCost(cost, n - 1), recurMinCost(cost, n - 2));
}

//* Memoization
int memoMinCost(vector<int> &cost, vector<int> &dp, int n)
{
    if (n == 0 || n == 1)
        return cost[n];
    if (dp[n] != 0)
        return dp[n];
    return dp[n] = cost[n] + min(memoMinCost(cost, dp, n - 1), memoMinCost(cost, dp, n - 2));
}

int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    // vector<int> cost = {10, 15, 20};
    int n = cost.size();

    //* Recursion
    int recurRes = min(recurMinCost(cost, n - 1), recurMinCost(cost, n - 2));
    cout << recurRes << endl;

    //* Memoization
    vector<int> dp(n + 1, 0);
    int memoRes = min(memoMinCost(cost, dp, n - 1), memoMinCost(cost, dp, n - 2));
    cout << memoRes << endl;

    //* Tabulation
    vector<int> cache(n + 1);
    cache[0] = cost[0];
    cache[1] = cost[1];
    for (int i = 2; i < n; i++)
    {
        cache[i] = cost[i] + min(cache[i - 1], cache[i - 2]);
    }
    int tabRes = min(cache[n - 1], cache[n - 2]);
    cout << tabRes << endl;

    //* Space Optimization
    int penultimate = cost[0];
    int ultimate = cost[1];
    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(penultimate, ultimate);
        penultimate = ultimate;
        ultimate = curr;
    }
    int spaceRes = min(penultimate, ultimate);
    cout << spaceRes << endl;

    return 0;
}