#include <iostream>
#include <fstream>
#include <cmath>

#define LEN 100000
unsigned long long mas[LEN] = {0};
using namespace std;

ifstream fin("invcnt.in");
ofstream fout("invcnt.out");

unsigned int cur = 0, m = 0;
unsigned int cnt = 0;
unsigned long long a = 0, b = 0;

unsigned int nextRand24() {
    cur = cur * a + b;
    return cur >> 8;
}

void fill(int n) {
    for (int i = 0; i < n; i++) {
        mas[i] = nextRand24() % m;
    }
}
/*
 * static unsigned long long B[LEN];

void MergeSortRec( unsigned long long *A, unsigned long N )
{
    unsigned long M, k, i = 0, j = N / 2;

    if (N < 2)
        return;
    M = N / 2;
    MergeSortRec( A, M );
    MergeSortRec( A + M, N - M );

    for (k = 0; k < N; k++)
        if ((j >= N || i < M) && A[i] < A[j])
            B[k] = A[i++];
        else {
            B[k] = A[j++];
            cnt+=M - i;
        }
    for (k = 0; k < N; k++)
        A[k] = B[k];
}

void MergeSort(unsigned long long *A, unsigned long N)
{
    MergeSortRec( A, N );
}
*/

void Inverses(unsigned long long *A, int N)
{
    cnt = 0;
    for(int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if( A[i] > A[j] )
                cnt++;
        }
    }
}
int main() {
    int n;
    fin >> n >> m >> a >> b;

    fill(n);
   // MergeSort(mas, n);
    Inverses(mas,n);
    fout<<cnt<<endl;
    fin.close();
    fout.close();
    return 0;
}
