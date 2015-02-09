void merge_array (int small[],int large[],int n){
    if (small == NULL || large == NULL || n<1){
        cerr << "error";
        return;
    }
    //i will start by from the end, and will merege the array;
    int *itr_insert = large+2*n-1;
    int *itr_large = large+n-1;
    int *itr_small = small+n-1;
    // i need to have a loop from end to begining.
    while (itr_insert >= large && itr_small >= small){
        // i need to check which entery to take:
        if (*itr_small > *itr_large){
            *(itr_insert--)=*(itr_small--);
        }else{
             *(itr_insert--)=*(itr_large--);
        }
    }
}

int main(){
    int N;
    cin >> N;
    int arr_small[N];
    int arr_large[2*N];
    for (int i=0 ; i<N;i++){
        cin >> arr_small[i];
    }
    for (int i=0 ; i<N;i++){
        cin >> arr_large[i];
    }
    merge_array(arr_small,arr_large,N);
    for (int i=0 ; i<(2*N);i++){
        cout << arr_large[i] << " ";
    }
    cout << endl;
    return 0;
}