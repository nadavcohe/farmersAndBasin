// unordered_map::begin/end example
// question from http://www.careercup.com/question?id=18517665
/*
Given an array of values, 
design and code an algorithm that returns whether there are two duplicates within k indices of each other?
*/
#include <iostream>
#include <vector>
#include <tr1/unordered_map>
using namespace std;

int find_dup(vector<int> &arr,int n,int k){
    std::tr1::unordered_map< int , bool > mymap;
    //Mymap mymap;
    int count=0;
    for (vector<int>::iterator itr = arr.begin();itr < arr.end();itr++){
        // i can add here plus +- 1 to check that;
        if (mymap[*itr]==true){
            return(*itr);
        }else{
            mymap[*itr]=true;
            count++;
        }
        if (count>k){
            mymap[*(itr-k)]=false;
        }
    }
    return -1;
}

int main ()
{
  int n,k;
  cin >> n;
  cin >> k;
  vector<int> arr;
  int value;
  for (int i=0;i < n;i++){
      cin >> value;
      arr.push_back(value);
  }
  cout << find_dup(arr,n,k) << endl;
  return 0;
}