enum Colors { RED, WHITE, BLUE };

void swap(Colors &a,Colors &b){
//	cerr << a <<"," <<b << endl;
	Colors temp=a;
	a=b;
	b=temp;
}

// n space, n time, bucked sort;
// n space soulution is to build a new array;
// i want n time 1 space;
bool dutch_sort(Colors array[],int n){
	if (array == NULL || n<0)
		return false;
    int start=-1;
    int end=n;
    int itr=0;
    while(itr<end){
        switch (array[itr]){
            case RED:
                swap(array[itr],array[++start]);
                itr++;
                break;
            case BLUE:
                swap(array[itr],array[--end]);
                break;
            default:
            	itr++;
            	break;
        }

    }
    return true;
}