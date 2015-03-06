#include <iostream>

using namespace std;

int findMedian(int a,int b,int c){
	if (a>b){
		if (b>c){
			return(b);
		}else{
		    if (a>c){
		        return(c);    
		    }else return(a);
		}
	}else{
		if (a>c){
			return(a);
		}else{
		    if (b>c)
		        return(c);
		    else
			    return(b);
		}
	}
	return(a);
}

int findMedian2(int a,int b,int c){
	int sum = a+b+c;
	sum-= max(max(a,b),c) + min(min(a,b),c);
	return (sum);
}

int main(){
	int a,b,c;
	cin >>a>>b>>c;
	cout << findMedian(a,b,c) << endl;
	return 0;
}