#include <iostream>

using namespace std;


//the array is sorted // find most common
int findCommon(int array[],int n){
	if ((array == NULL) || (n<=0)){
		return -1;
	}
	int maxCout,curCount,maxNum,curNum;
	curNum= -1 ;
	for (int i = 0; i < n; i++){
		if (array[i] == curNum){
			curCount++;
		}else{
			if (curCount > maxCout){
				maxCout = curCount;
				maxNum = curNum;
			}
			curCount = 1;
			curNum = array[i];
		}
	}
	if (curCount > maxCout){
		maxCout = curCount;
		maxNum = curNum;
	}
	return (maxNum);
}

int main(){
	int n;
	cin >> n;
	int array[n];
	for (int i = 0 ; i < n ;i++){
		cin >> array[i];
	}
	cout << endl << findCommon(array,n) << endl;

	return 0;
}