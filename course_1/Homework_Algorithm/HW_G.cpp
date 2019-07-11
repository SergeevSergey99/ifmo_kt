#include <iostream>
#include <fstream>
#include <cmath>

#define LEN 100000
unsigned long long mas[LEN] = {0};
using namespace std;

ifstream fin("buckets.in");
ofstream fout("buckets.out");

unsigned int cur = 0;
unsigned long long a = 0, b = 0;

unsigned int nextRand24() {
    cur = cur * a + b;
    return cur >> 8;
}

unsigned int nextRand32() {
    unsigned int a = nextRand24(), b = nextRand24();
    return (a << 8) ^ b;
}

void fill(int n) {
    for (int i = 0; i < n; i++) {
        mas[i] = nextRand32();
    }
}

void bucketSort(int n) {
    unsigned int mas_i[65536];

    for(int i = 0; i<n;i ++)
    {
        unsigned int sqr = sqrt(mas[i]);
        mas_i[sqr] = mas[i] - sqr*sqr;
    }
    int j=0;
    for(unsigned int i = 0; i<4294967295;i ++)
    {
        if(mas_i[i]>0){
            mas[j++] = i*i + mas_i[i];
            n--;
            mas_i[i]=0;
        }
        if (n<=0)break;
    }
}

unsigned long long sum(int n){
    unsigned long long sum=0;
    for (int i = 0; i < n; i++) {
        sum+=mas[i]*(i+1);
    }
    return sum;
}
int main() {
    int t, n;
    fin >> t >> n >> a >> b;

    for (int i = 0; i < t; i++) {
        fill(n);
        bucketSort(n);
//        cout<<sum(n);
        fout<<sum(n);
    }
    fin.close();
    fout.close();
    return 0;
}
