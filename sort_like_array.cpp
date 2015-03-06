#include <iostream>

using namespace std;

void switchArr(int array[],int a,int b){
	int temp;
	temp=array[a];
	array[a]=array[b];
	array[b]=temp;
}

// you need an array like this a1 > a2 < a3 > a4 < a5 > a6
void likeSort(int array[], int n){
	if (array == NULL || n<=0){
		return;
	}
	bool stiwchMode;
	for (int i=1;i < n;i++){
		stiwchMode=(i % 2 ==1);
		if ((array[i-1]<array[i])==stiwchMode){
			switchArr(array,i-1,i);
		}
	}	
}

int main(){
	int n;
	cin >> n;
	int array[n];
	for (int i = 0 ; i < n ;i++){
		cin >> array[i];
	}
	likeSort(array,n);
	for (int i = 0 ; i < n ;i++){
		cout << array[i] << "\t";
	}

	return 0;
}