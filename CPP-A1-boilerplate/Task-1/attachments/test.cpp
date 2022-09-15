// IKEA has finally decided to invest in digitising their operations and the supply chain.They contracted you to design an algorithm to sort a list of orders by selection time(t selection, finding the good in the warehouse and bringing it to the surface) plus shipping time(t shipping, constant).The customer orders can be retrieved(in the same order as placed) from a server database.You should expect between 10*10K - 20*20K elements.
// Example 2. The program takes as input a data - set of orders where id, t selection and t shipping are of type unsigned int, n is the number of orders, and a space character.<id1>, <t selection1>, <t shipping1>;
// ...;
// <idn>, <t selectionn>, <t shippingn> \n The expected output is a space separated list of the ids, sorted by t selection + t shipping and terminated by a newline \n.Input : 1, 500, 100;
// your solution to run for several IKEA ware- houses
// 2, 700, 100;
// 3, 100, 100\n Output : 3 1 2\n

//  write your code here

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Order
{
public:
    size_t id;
    size_t selection_time;
    size_t shipping_time;
    Order *next;

    Order(size_t id, size_t selection_time, size_t shipping_time)
    {
        this->id = id;
        this->selection_time = selection_time;
        this->shipping_time = shipping_time;
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

void sort(...)
{
    /*
    
