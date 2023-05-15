int globe;
extern int external;
int fib(int a) {
	if (a<2) {
		return 1;
	} else {
		return fib(a-1)+fib(a-2);
	}
}
int main(int argc) {
	int a;
	a=fib(8);
	return a;
}