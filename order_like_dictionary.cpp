// question from http://www.careercup.com/question?id=15555705
#include <iostream>
#include <unordered_map>

using namespace std;
// i have a problem with blank str_2
// if i used array of 26 letters it can be better
int main(){
    string str_1,str_2;
    cin >> str_1;
    cin >> str_2;
    unordered_map<char,int> str_order;
    char str_out[str_1.size()];
    for (int i = 0;i < str_1.size(); i++){
        str_order[char(str_1[i])]++;
    }
    char cur_char;
    int itr_new_string = 0;
    for (int i = 0;i < str_2.size(); i++){
        cur_char=char(str_2[i]);
        for(int g = 0 ; g < str_order[cur_char];g++){
            str_out[itr_new_string++]=cur_char;
        }
        str_order[cur_char]=0;
    }
    for (auto itr = str_order.begin(); itr != str_order.end() ; itr++){
        for (int i = 0; i < itr->second; i++){
            str_out[itr_new_string++]=itr->first;
        }   
    }
    while (itr_new_string<=str_1.size()){
        str_out[itr_new_string++]='\0';
    }
    
    cout << str_out ;//<< " "<<  itr_new_string << endl;
    return 0;
}