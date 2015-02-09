bool findPair(int &one,int &two,int* array,int n,int tSum){
    // two itr, one for the start of the vector and one for the end;
    int *itrS,*itrE;
    itrS = array;
    itrE= array +(n-1);
    // while there is still numbers we didn't go throw,
    while (itrS<itrE){
        if ((*itrS+*itrE)==tSum){
            one=*itrS;
            two=*itrE;
            return(true);
        }
        if (*itrS+*itrE)<tSum){
            itrS+
        }else{
            itrE--
        }
    }
    return(false);
}

//for find triplet
bool findPair(int &one,int &two,int* array,int n,int tSum, int* curIndex=NULL){
    // two itr, one for the start of the vector and one for the end;
    int *itrS,*itrE;
    itrS = array;
    itrE = array +(n-1);
    // while there is still numbers we didn't go throw,
    while (itrS<itrE){
        if (itrS==curIndex)
            itrS++;
        if (itrE==curIndex)
            itrE--;
        if ((*itrS+*itrE)==tSum){
            one=*itrS;
            two=*itrE;
            return(true);
        }
        if ((*itrS+*itrE)<tSum){
            itrS++;
        }else{
            itrE--;
        }
    }
    return(false);
}

bool findTriplet(int *array,int n){
    int one,two;
    std::sort(array,array+n);
    if (array==NULL || n<3)
        return false;
    for (int *itr=array;itr<(array+n);++itr){
        if (findPair(one,two,array,n,-(*itr),itr)){
            return true;
        }
    }
    return false;
}

int main(){
	//runQ3
	int array[] =  {-11,1, 2, 4, 7, 11, 15};
	int one,two;
	cerr << findPair(one,two,array,7,6) << endl;
	cerr << findTriplet(array,7);
	return 0;
}