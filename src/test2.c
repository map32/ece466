int fib(int n) {
	int i,j;
	i=n-1;
	j=n-2;
	if (n<2)
		return 1;
	else
		return fib(i)+fib(j);
}
int main(){
	int a;
	a=5;
	int *b;
	b = &a;
	b = b + 1;
	int m[10][20];
	int i,j;
	a = m[i][j];
	fib(8);
	return 0;
}