#include <iostream>
#include <vector>
using namespace std;

int fibo(int n, vector<int> &cache)
{
    if (n == 0 || n == 1)
        return n;

    if (cache[n] != -1)
        return cache[n];

    return cache[n] = fibo(n - 1, cache) + fibo(n - 2, cache);
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibo(n, dp) << endl;
    return 0;
}
