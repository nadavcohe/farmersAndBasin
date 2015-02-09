#include <iostream>
#include <algorithm>

using namespace std;

//remember test cases!!! (NULL)
int find_dup(int arr[], int n){
    if (arr==NULL || n<1){
        cerr << "error";
        return -1;
    }
    // do i need to check validiti of all numbers?
    //sort(arr,arr+n);
    int temp;
    for (int i = 1;i < n;i++){
        if (arr[i]!=i){
            if (arr[arr[i]] == arr[i]){
                return (arr[i]);
            }else{
                temp = arr[i];
                arr[i] = arr[arr[i]];
                arr[temp] = temp;
            }
        }
        
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout << find_dup(arr,n) << endl;
    for (int i = 0;i < n;i++){
        cout <<  arr[i] << "\t";
    }
    cout << endl;
    return 0;
}