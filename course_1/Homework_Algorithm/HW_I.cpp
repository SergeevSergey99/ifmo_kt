#include <iostream>
#include <fstream>
#include <cmath>

#define LEN 10000


using namespace std;

ifstream fin("supermarket.in");
ofstream fout("supermarket.out");

int main() {
    int m;//ЧИсло касс
    fin >> m;

    int a[LEN], b[LEN], t[LEN]; //Время на товар; Время на рассчет; Время на очередь
    bool b_mas[LEN] = {false};
    for (int i = 0; i < m; i++) {
        fin >> a[i] >> b[i] >> t[i];
        b[i] += t[i];
    }

    int n, p; //Число студентов и число суммарных покупок
    fin >> n >> p;

    int n_count = 0;
    for (int i = 0; i < p; i++) {

        int min_i = 0;

        for (int j = 0; j < m; j++) {
            if (n_count < n && (b[min_i] + a[min_i] > b[j] + a[j])) min_i = j;
        }
        b[min_i] += a[min_i];
        if (!b_mas[min_i])n_count++;
        b_mas[min_i] = true;
    }

    int _max=0;
    for (int k = 0; k < m; k++) {
        b[k] = b[k]*b_mas[k];
        if (_max<b[k])_max = b[k];
    }
    fout<<_max;
    cout<<_max;
    return 0;
}
