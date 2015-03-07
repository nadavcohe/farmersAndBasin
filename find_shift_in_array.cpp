#include <iostream>

using namespace std;

// array that is shifter from the start to the end
// example 2 3 4 5 6 7 8 9 10 1  , 2 2 2 2 2 4 2 2 2 2 , 3 4 5 6 7 8 9 10 1 2

int findShift(int array[],int n){
	if (array==NULL){
		return -1;
	}
	int start = 0;
	int end = n-1;
	int mid;
	while (end-start > 1){
	    
		mid = (start +(end-start)/2);
		if (array[start] > array[mid]){
			end = mid;
		}else if (array[mid] > array[end]) {
			start = mid;
		} else {
			// special case
			break;
		}
	}
	if (end-start>1){
		while (array[start++] <=array[end]){};
	}
	
	return (array[start]);
	
}

int main(){
	int n;
	cin >> n;
	int array[n];
	for (int i = 0 ; i<n ;i++){
		cin >> array[i];
	}
	
	cout << findShift(array,n) << endl;

	return 0;
}