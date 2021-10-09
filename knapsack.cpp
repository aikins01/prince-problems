#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>


using namespace std;
vector<int> included;

int knapsack(int capacity, vector<int> weights, vector<int> values, int n)
{
    if (n == 0 || capacity == 0)
    {
        return 0;
    }
    if (weights.at(n-1) > capacity)
    {
        
        return knapsack(capacity, weights, values, n - 1);
    }
    else
    {
        
        return max(values.at(n-1) + knapsack(capacity - weights.at(n - 1), weights, values, n - 1), knapsack(capacity, weights, values, n - 1));
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "No input filename given" << std::endl;
        return 1;
    }
    ifstream f;
    f.open(argv[1]);
    if (f)
    {
        int capacity;
        f >> capacity;
        vector<int> weights;
        vector<int> values;
        int weight, value;
        while (f >> weight >> value)
        {
            weights.push_back(weight);
            values.push_back(value);
        }
        cout << "With a capacity of " << capacity << "kg, the total value is " << knapsack(capacity, weights, values, weights.size()) << " Eur, leading to a weight of " << capacity << "kg" << endl;
        
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights.at(i) <= knapsack(capacity, weights, values, weights.size()) )
            {
                // included.push_back(i);
            }
        }
        cout << "The following items are included: ";
        for (int i = 0; i < included.size(); i++)
        {
            cout <<"[" << weights.at(included.at(i)) << "," << values.at(included.at(i)) << "] ";
        }
        return 0;
    }
    else
    {
        std::cerr << "Could not open file" << argv[1] << " " << std::endl;
        return 1;
    }
}
