//Cracking the Coding Interview, chapter 9 Q 9.1

long countHop( long n){
	if (n <= 3){
		return(n);
	}
	long arr[n] = {0};
	arr[0]=1;
	arr[1]=2;
	arr[2]=3;
	for (int i=3; i<n;i++){
		arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
	}
	return(arr[n]);


}