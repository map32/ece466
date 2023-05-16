int globe;
extern int external;
int fib(int a) {
	if (a<2) {
		return 1;
	} else {
		int b;
		b=fib(a-1);
		return b+fib(a-2);
	}
}
int main(int argc) {
	int a;
	a=fib(6);
	return a;
}