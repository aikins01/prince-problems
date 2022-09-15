// worst time 0.441

#include<iostream>
#include<vector>
#include<limits>
#include<queue>

using namespace std;

class Job {
public:
    size_t id; 
    size_t p;
    size_t w;

    Job(){}
    Job(size_t id, size_t p, size_t w) {
        this->id = id;
        this->p = p;   
        this->w = w;
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

struct Priority{
    /*
        TODO: add ordering rule for the Priority Queue.
    */
};

int main(int argc, char *argv[]){
  
    priority_queue<Job, vector<Job>, Priority>  q;

    /*
        Retrieves and splits the input
    */
    string data;
    while(getline(cin, data)){
        vector<string> data_v = split(data, "; ", numeric_limits<size_t>::max());

        for(string d : data_v){
            vector<string> order_data = split(d, ", ", 2);
            size_t id = stoi(order_data.at(0));
            size_t p  = stoi(order_data.at(1));
            size_t w  = stoi(order_data.at(2));

            /*
                TODO: Add the job to the queue with respect to smiths rule.
            */
        }

        /*
            TODO: Print in stdout the id's of the jobs in the queue (.id) space separated in one line.
    	    Terminate with a new line.
                i.e: 1 2 3 4 5 6\n
        */
    }
}

			