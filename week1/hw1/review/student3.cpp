#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

inline void sum(int& p, int n, vector<int> d)
{
    p = 0;
    for (int i = 0; i < n; ++i)
        p = p + d[i];
}

int main()
{
    vector<int> data = vector<int>(N);
    int accum = 0;

    for (int i = 0; i < N; ++i)
        data[i] = i;

    sum(accum, N, data);

    cout << "sum is " << accum << endl;
    return 0;
}