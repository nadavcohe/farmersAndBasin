	// this is for ones to get the full number.
	// by Lagrange's four-square theorem we know that there are always 4 numbers for that

int countSquare(int n,int index=-1){
	if ( n == 0){
		return 0;
	}
	if (n < 0){
		return numeric_limits<int>::max();
	}
	if (index==0)
		return numeric_limits<int>::max();
	if  (index == -1)
		index = floor(sqrt(n));

	int sum=pow(index,2);
	int temp=min(countSquare(n,index-1),1+countSquare(n-sum,-1));
	cerr << n << "\t" << index << "\t" << temp << endl;
	return temp;
}