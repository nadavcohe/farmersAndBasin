// CONVERTS UTF8 hex into unicode bits
int hexToInt(char a){
	if (a>='0' && a<='9')
		return int(a-'0');
	return 10+int(a-'A');
}

int mergeInt(int a,int b){
	a <<= 4;
	return (a | b);
}

// find out how many leading 1 to know how many double hex we need
int firstOnes(int a){
	int check = 1 << 7;
	int count=0;
	while ((a & check) == check ){
		check>>=1;
		count++;
	}
	return count;

}

int utf8ToUnicode(char arr[],int n, int res[],int start){
		if (n < 2 || n % 2 == 1 || start > n)
			return -1;
		int itr=start;
		int end= firstOnes(mergeInt(hexToInt(arr[itr]),hexToInt(arr[itr+1])))*2;
		while (itr < n && itr < (start+end*2)){
			res[itr/2]=mergeInt(hexToInt(arr[itr]),hexToInt(arr[itr+1]));
			itr+=2;
		}
		if (n/2==1){
			res[0]&=  ((1 << 7 ) -1);
			return (start+end/2) ;
		}
		res[0]&=((1 << (7 - (n/2)) ) -1);
		for (int i=1; i < n/2;i++){
			res[i]&=((1 << 6 ) -1);
		}
		return (start+end/2);
}



int main(){
	int n=10;
	char UTF[n] = {'F','0','9','0','8','D','8','8','2','4'};
	int UNI[n/2] = {0};
	int end = utf8ToUnicode(UTF,n,UNI,0);
	cerr << end << endl;
	for (int i=0;i<end;i++){
		cerr << bitset<8>(UNI[i]) << " ";
	}
	cerr << endl;
	int start=end;
	end = utf8ToUnicode(UTF,n,UNI,start);
	for (int i=start;i<end;i++){
		cerr << bitset<8>(UNI[i]) << " ";
	}
	return 0;
}