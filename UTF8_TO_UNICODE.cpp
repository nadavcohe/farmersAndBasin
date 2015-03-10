

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

void utf8ToUnicode(char arr[],int n, int res[]){
		if (n < 2 || n % 2 == 1)
			return;
		int itr=0;
		while (itr < n){
			res[itr/2]=mergeInt(hexToInt(arr[itr]),hexToInt(arr[itr+1]));
			itr+=2;
		}
		if (n/2==1){
			res[0]&=  ((1 << 7 ) -1);
			return;
		}
		res[0]&=((1 << (7 - (n/2)) ) -1);
		for (int i=1; i < n/2;i++){
			res[i]&=((1 << 6 ) -1);
		}

}

int main(){
	int n=4;
	char UTF[n] = {'C','2','A','2'};
	int UNI[n/2] = {0};
	utf8ToUnicode(UTF,n,UNI);
	for (int i=0;i<n/2;i++){
		cerr << bitset<8>(UNI[i]) << " ";
	}
	return 0;
}