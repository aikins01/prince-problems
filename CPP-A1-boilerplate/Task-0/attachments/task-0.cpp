#include <iostream>
#include <vector>
#include <limits>
using namespace std;

enum string_code
{
    eq,
    gt,
    lt,
    le,
    ge,
    nd
};

class Obj
{
public:
    int var;
    Obj(int var)
    {
        this->var = var;
    }

    bool operator==(Obj const &op)
    {
        return (this->var == op.var);
    }

    bool operator>(Obj const &op)
    {
        return (this->var > op.var);
    }

    bool operator<(Obj const &op)
    {
        return (this->var < op.var);
    }

    bool operator<=(Obj const &op)
    {
        return (this->var <= op.var);
    }

    bool operator>=(Obj const &op)
    {
        return (this->var >= op.var);
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

string_code switch_hash(string const &inString)
{
    if (inString == "==")
        return eq;
    if (inString == ">")
        return gt;
    if (inString == "<")
        return lt;
    if (inString == "<=")
        return le;
    if (inString == ">=")
        return ge;

    return nd;
}

int main(int argc, char *argv[])
{
    /*
        Retrieve input
    */
    string data;
    getline(cin, data);
    vector<string> data_v = split(data, " ", 2);

    /*
        Create Objects
    */
    Obj left = Obj(stoi(data_v.at(0)));
    Obj right = Obj(stoi(data_v.at(2)));

    /*
        Perform operations
    */
    bool res;
    switch (switch_hash(data_v.at(1)))
    {
    case eq:
        res = (left == right);
        break;
    case gt:
        res = (left > right);
        break;

    case lt:
        res = (left < right);
        break;

    case le:
        res = (left <= right);
        break;

    case ge:
        res = (left >= right);
        break;

    default:
        cout << "Not Implemented";
        break;
    }

    cout << res;
}