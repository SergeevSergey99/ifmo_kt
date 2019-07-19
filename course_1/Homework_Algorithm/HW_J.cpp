#include <iostream>
#include <fstream>
#include <cmath>

#define LEN 10000
int mas[LEN];

using namespace std;

ifstream fin("bigseg.in");
ofstream fout("bigseg.out");

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

int main() {
    int n, k;
    fin >> n >> k;
    fin >> a >> b;

    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        mas[i]=(int)nextRand32();
    }
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum+=mas[j];
            if (sum>=k)count++;
        }
    }
    fout<<count;

    fin.close();
    fout.close();
    return 0;
}
