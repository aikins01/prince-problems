#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int find_maximum(vector<int> array)
{
    int max = array[0];
    for (int i = 1; i < array.size(); ++i)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }
    return max;
}

/*
Helper function to read input. DO NOT CHANGE!!!
*/
vector<string> split(string s, string delimiter, size_t it)
{

    size_t pos_start = 0, pos_end, count = 0, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((count < it) && ((pos_end = s.find(delimiter, pos_start)) != string::npos))
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
        ++count;
    }

    res.push_back(s.substr(pos_start));
    return res;
}

int main(int argc, char *argv[])
{
    /*
        Retrieves and splits the input. DO NOT CHANGE!!!
    */
    string data;
    getline(cin, data);
    vector<string> data_v = split(data, " ", numeric_limits<size_t>::max());

    vector<int> arr;
    transform(data_v.begin(), data_v.end(), back_inserter(arr),
              [&](string s)
              {
                  return stoi(s);
              });

    /*
    Call function
    */
    cout << find_maximum(arr) << '\n';

    return 0;
}