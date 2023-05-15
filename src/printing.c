#include <stdio.h>
int a;
int* p;
extern int b;
static long double c;
int fib(int n) {
    int a = n;
    int b = n+1;
    int c = a+b;
    int d = c;
    if (n<2) {
        return 1;
    } else return fib(n-1)+fib(n-2);
}
int test(int a, int b, int c, int z) {
    int d = a+b;
    int e = a+c;
    int f = b+c;
    int g = f+c;
    int h = g+d;
    int i = g-e;
    return d;
}
int main() {
    printf("fibonacci\n");
    int a = fib(8);
    int *b = &a;
    printf("%d",a);
    test((int)&a,*b,3,4);
    return 0;
}