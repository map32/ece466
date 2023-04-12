
int aa[32][10];
int (*a)[32][10];
int main(){
	a = &aa;
    (*a)[3][4] = 10;
	return 0;
}