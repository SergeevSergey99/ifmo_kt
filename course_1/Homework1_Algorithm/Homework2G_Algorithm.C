#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
#define LEN 30000000

long A[LEN];
long B[LEN];
long q[LEN];
long i = 0;
long j = 0;

void q_push(long n) {
    A[j++] = n;
}

long q_pop() {
    return A[i++];
}

void q_popLast() {
    j--;
}

long q_peekLast() {
    return A[j - 1];
}

long q_peekFirst() {
    return A[i];
}
void q_enqueue(long t, long ii) {
    while (j - i > 0 && q_peekLast() > t) {
        q_popLast();
    }
    B[j] = ii;
    q_push(t);
}

void q_dequeue(long ii) {
	while (j - i > 0 && ii >= B[i]) {
		q_pop();
	}
}

long f(long y) {
    return y;
}


int main() {
	FILE* fin; 
	fopen(&fin,"queue-min.in", "r");
	FILE* fout;
	fopen(&fout, "stack-min.out", "w");

	long n, m, k;
	long a, b, c;
	long min = 0;

	fscanf(fin, "%ld", &n);
	fscanf(fin, "%ld", &m);
	fscanf(fin, "%ld", &k);

	fscanf(fin, "%ld", &a);
	fscanf(fin, "%ld", &b);
	fscanf(fin, "%ld", &c);

	for (ii = 0; ii < k; ii++) {

		fscanf(fin, "%ld", &q[ii]);
	        q_enqueue(q[ii], ii);

	}	
	for (long ii = k; ii < m - 1; ii++) {

		q[ii] = f(a * q[ii - 2] + b * q[ii - 1] + c);
		q_enqueue(q[ii], ii);
		min += q_peekLast();
	}
	for (long ii = m - 1; ii < n; ii++) {
		q[ii] = f(a * q[ii - 2] + b * q[ii - 1] + c);
		q_enqueue(q[ii], ii);
		min += q_peekFirst();
		q_dequeue( ii -  m + 1 );
 
	}

	fprintf("%ld", min);

	fclose(fin);
	fclose(fout);
	return 0;
}
