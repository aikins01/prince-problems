#include<iostream>
#include<vector>
#include <limits>
using namespace std;
 
class Job {
public:
    size_t id; 
    size_t p;
    size_t w;

    /*
        Remove me if you don't need me.
        Add a method to assign to me.
    */
    Job *next;

    Job(size_t id, size_t p, size_t w) {
        this->id = id;
        this->p = p;   
        this->w = w;

        /*
            Remove me if you don't need me.
            Add a method to assign to me.
        */
        this->next = NULL;
    }
};

vector<string> split(string s, string delimiter, size_t it){

    size_t pos_start = 0, pos_end, count = 0, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((count < it) && ((pos_end = s.find (delimiter, pos_start)) != string::npos)) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
        ++count;
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void sort(...){
    /*
        TODO: Implement your sorting function and add the parameters you need.
    */
}

int main(int argc, char *argv[]){
    /*
        Retrieves and splits the input
    */
    string data;
    getline(cin, data);
    vector<string> data_v = split(data, "; ", numeric_limits<size_t>::max());
    
    for(string d : data_v){
        vector<string> job_data = split(d, ", ", 2);
        size_t id = stoul(job_data.at(0));
        size_t p  = stoul(job_data.at(1));
        size_t w  = stoul(job_data.at(2));
        
        Job *jobs = new Job(id, p, w);
        /*
            TODO: Append the `order` object to your structure.
        */
    }

    sort();

    /*
        TODO: Print in stdout the id's of the sorted list (order.id) in one line.
        Terminate with a new line.
                i.e: 1 2 3 4 5 6\n
    */

}