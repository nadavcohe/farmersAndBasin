//question from https://www.hackerrank.com/challenges/the-quickest-way-up

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node;
typedef vector<Node*> nodes_type;
class Node{
private:
    nodes_type nodes;
    int data_;
    int dist_;
    bool visited_;
    Node *father_;
public:
    Node(int data){
        dist_ = -1;
        visited_ = false;
        data_ = data;
        father_=NULL;
    }
    bool add_child (Node *node,bool only_last=false){
        if (only_last){
            nodes.clear();
        }
        nodes.push_back(node);
        return true;
    }
    
    int get_data(){
        return (data_);
    }
    
    int get_dist(){
        return(dist_);
    }
    void find_home(int total_step, Node * prev){
        if (!visited_ ||(dist_ > (total_step))){
            visited_=true;
            dist_=total_step;
            father_ = prev;
  //          cerr << data_ << " " << dist_ << endl;        
            nodes_type::iterator itr=nodes.begin();
            while(itr<nodes.end()){
                (**itr).find_home(dist_+1,this);
                itr++;
            }
        }      
    };
    
    bool erase_child(Node * child){
        for (nodes_type::iterator itr=nodes.begin();itr<nodes.end();itr++){
            if ((*itr)==child){
                nodes.erase(itr);
                return true;
            }
        }
        return false;
    }
    void trace_back(){
        cerr << data_ << endl;
        if (father_ != NULL){
            (*father_).trace_back();
        }
    }
        
};

typedef vector<int> pair_type;


void parse_pair(string s,pair_type &res,string delimiter=","){
    size_t pos = 0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        res.push_back(std::stoi(s.substr(0, pos)));
        s.erase(0, pos + delimiter.length());
    }
    if (s.size()>0){
        res.push_back(std::stoi(s));
    }
}

void parse_string(string s,vector<pair_type> &res,string delimiter=" "){
    size_t pos = 0;
    std::string token;
    pair_type pair;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        pair.clear();
        parse_pair(token,pair);
        res.push_back(pair);
        s.erase(0, pos + delimiter.length());
    }
    if (s.size()>0){
        pair.clear();
        parse_pair(s,pair);
        res.push_back(pair);
    }
}

class game{
    private:
        int N;
        Node *ar_node[100];
    public:
    game() : N(100){
        
        // init of nodes
        for (int i=0;i < (N);i++){
            ar_node[i] = new Node(i+1);
        }
        for (int i=0;i < (N-1);i++){
            for (int g=i+1;g<=min(i+6,N-1);g++){
                (*ar_node[i]).add_child(ar_node[g],false);
            }
        }
    };
    void run_game(vector<pair_type> pair_list[2]){
        int edge_a,edge_b;
        for (int i=0;i<2;i++){
            for (vector<pair_type>::iterator itr=pair_list[i].begin();itr < pair_list[i].end(); itr++ ){
                edge_a = (i==0) ? (*itr)[0] : (*itr)[0];
                edge_b = (i==0) ? (*itr)[1] : (*itr)[1];
                (*ar_node[--edge_a]).add_child(ar_node[--edge_b],true);
                cerr << edge_a << "," << edge_b << endl;
            }
        }
        //int steps=0,best=std::numeric_limits<int>::max();
        (*(ar_node[0])).find_home(-1,NULL);
        cout <<  (*(ar_node[99])).get_dist() << endl;
        (*(ar_node[99])).trace_back();
    };
    
    int game_step(int loc,int step=0){
        if (loc>=N){
            return -1;
        }
    }
    ~game(){
        for (int i=0;i < N;i++){
            delete ar_node[i];
        }
    };
    
};

int main() {
   int M;
    int cases_num;
    cin >> cases_num;
    string pair_str;
    pair_type pair,nodes_numers;
    vector<pair_type> nodes_list[2];
    game *a_game;
    for (int run=0;run < cases_num ;run++){
        nodes_list[0].clear();
        nodes_list[1].clear();
        pair_str.clear();
        nodes_numers.clear();
        cin >> (pair_str);
        parse_pair(pair_str,nodes_numers);
        for (int i=0;i < 2;i++){
            for (int g=0;g < nodes_numers[i];g++){
                cin >> (pair_str);
                pair.clear();
                parse_pair(pair_str,pair);
                nodes_list[i].push_back(pair);
            }
        }
        a_game = new game();
        (*a_game).run_game(nodes_list);
        delete a_game;
    }

    return 0;
}