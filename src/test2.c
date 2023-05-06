#include <stdio.h>
int main(){
	fib(5);
	return 0;
}

int fib(int a)
{
	if (a<2) return 1;
 return fib(a-1) + fib(a-2);
}
