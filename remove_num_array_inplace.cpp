void Swap2(int &one,int &two){
    int temp=one;
    one=two;
    two=temp;
}

void removeNum(int array[],int n,int &x, int &newN){
    int *top=array+(n);
    int *itr=array;
    while (itr<(top)){
        if ((*itr)==x){
            Swap2(*itr,(*(--top)));
        }else
        	itr++;
    }
    newN=top-array;
}