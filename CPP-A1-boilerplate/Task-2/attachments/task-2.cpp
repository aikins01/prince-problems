#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Order
{
public:
    size_t id;
    size_t selection_time;
    size_t shipping_time;

    /*
        Remove me if you don't need me.
        Add a method to assign to me.
    */
    Order *next;

    Order(size_t id, size_t t_selection, size_t t_shipping)
    {
        this->id = id;
        this->selection_time = t_selection;
        this->shipping_time = t_shipping;

        /*
            Remove me if you don't need me.
            Add a method to assign to me.
        */
        this->next = NULL;
    }
};

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

void sort(vector<Order> &orders, size_t n)
{
    /*
        TODO: Implement your sorting function and add the parameters you need.
    */

    // quick sort
    if (n > 1)
    {
        size_t pivot = orders[n - 1].selection_time;
        size_t i = 0, j = 0;
        while (j < n - 1)
        {
            if (orders[j].selection_time < pivot)
            {
                Order temp = orders[i];
                orders[i] = orders[j];
                orders[j] = temp;
                ++i;
            }
            ++j;
        }
        Order temp = orders[i];
        orders[i] = orders[n - 1];
        orders[n - 1] = temp;

        sort(orders, i);
        sort(orders, n - i);
    }
}

int main(int argc, char *argv[])
{
    /*
        Retrieves and splits the input
    */
    string data;
    getline(cin, data);
    vector<string> data_v = split(data, "; ", numeric_limits<size_t>::max());

    vector<Order> orders;

    for (string d : data_v)
    {
        vector<string> order_data = split(d, ", ", 2);
        size_t id = stoul(order_data.at(0));
        size_t selection = stoul(order_data.at(1));
        size_t shipping = stoul(order_data.at(2));

        orders.push_back(Order(id, selection, shipping));
    }

    sort(orders, orders.size());

    /*
        TODO: Print in stdout the id's of the sorted list (order.id) in one line.
        Terminate with a new line.
                i.e: 1 2 3 4 5 6\n
    */
    for (size_t i = 0; i < orders.size(); i++)
    {
        cout << orders[i].id << " ";
    }
    cout << endl;
    return 0;
}