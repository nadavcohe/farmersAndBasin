void getLeastKNumbers(int[] input, int[] output,int n,int k) {
    int start = 0;
    int end = n - 1;
    int index = partition(input, start, end);
    while(index != k - 1) {
        if(index > k - 1) {
            end = index - 1;
            index = partition(input, start, end);
        }else {
            start = index + 1;
            index = partition(input, start, end);
        }
    }
    for(int i = 0; i < k; ++i)
        output[i] = input[i];
}