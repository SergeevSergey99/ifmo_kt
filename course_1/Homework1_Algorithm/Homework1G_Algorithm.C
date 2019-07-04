#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
#define LEN 30000000

long x[LEN];

long min(long a, long b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

long f(long y) {
	//(y-z)%2^32 == 0 
	return ;
}


int main() {
	FILE* fin; 
	fopen(&fin,"queue-min.in", "r");
	//FILE* fout;
	//fopen(&fout, "stack-min.out", "w");

	long n, m, k;
	long a, b, c;

	fscanf(fin, "%ld", &n);
	fscanf(fin, "%ld", &m);
	fscanf(fin, "%ld", &k);

	fscanf(fin, "%ld", &a);
	fscanf(fin, "%ld", &b);
	fscanf(fin, "%ld", &c);

	long i = 0;
	for (; i < k; i++) {

		fscanf(fin, "%ld", &x[i]);

	}
	for (; i < k; i++) {

		x[i] = f(a * x[i - 2] + b * x[i - 1] + c);

	}


	fclose(fin);
//	fclose(fout);
	//fin.close();
	//fout.close();
	return 0;
}