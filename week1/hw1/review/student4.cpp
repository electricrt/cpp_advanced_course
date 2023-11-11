// Convert this program to C++
// change to C++ io
// change to one line comments
// change defines of constants to const
// change array to vector<>
// inline any short function

#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

inline void sum(int &p, const vector<int> &inData)
{
    p = 0;
    for (uint8_t loop=0; loop<inData.size(); loop++)
    {
        p += inData[loop];
    }
}

int main()
{
    vector<int> myData;
    int accum;

    for (int loop=0; loop<N; loop++)
    {
        myData.push_back(loop);
    }

    sum(accum, myData);

    cout << "sum is " << accum << endl;

    return 0;
}