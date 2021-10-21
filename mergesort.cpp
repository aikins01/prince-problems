#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    vector<int> data;
    data.push_back(5);
    data.push_back(3);
    data.push_back(1);
    data.push_back(4);
    data.push_back(2);
    mergeSort(data, 0, 4);
    for (unsigned int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    assert(data[0] == 1);
    assert(data[1] == 2);
    assert(data[2] == 3);
    assert(data[3] == 4);
    assert(data[4] == 5);
    return 0;
}