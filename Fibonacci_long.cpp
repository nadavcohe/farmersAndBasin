#include <iostream>

using namespace std;

void addArr(int a[],int b[],int n){
	int carry=0;
	int sum=0;
	for (int i = 0; i < n ; i++){
		sum = a[i]+b[i];
		sum+=carry;
		a[i] = (sum  % 10 );
		carry = sum /10;
	}
}

int main(){
	int n;
	cin >> n;
	int a[n+1] = {0};
	int b[n+1] = {0};
	a[0]=1;
	b[0]=1;
	int itr=0;
	while ((a[n]==0) && (b[n]==0)){
		if (itr % 2 ==0){
			addArr(a,b,n+1);
		}else{
			addArr(b,a,n+1);
		}
		itr++;
	}
	for (int i = 0; i < n ; i++){
		cout << a[i];
	}
	cout << endl;
	return 0;
}