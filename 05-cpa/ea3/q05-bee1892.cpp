#include <iostream>
using namespace std;

long long merge(string v[], string temp[], int inicio, int meio, int fim) {
    long long inversoes = 0;

    int i = inicio, j = meio + 1, k = inicio;
    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
            inversoes += meio - i + 1;
        }
    }

    while (i <= meio)
        temp[k++] = v[i++];
    while (j <= fim)
        temp[k++] = v[j++];

    for (i = inicio; i <= fim; i++)
        v[i] = temp[i];

    return inversoes;
}

long long merge_sort(string v[], string temp[], int inicio, int fim) {
    long long inversoes = 0;
    if (inicio < fim) {
        int mid = inicio + (fim - inicio) / 2;
        inversoes += merge_sort(v, temp, inicio, mid);
        inversoes += merge_sort(v, temp, mid + 1, fim);
        inversoes += merge(v, temp, inicio, mid, fim);
    }
    return inversoes;
}

int main() {
    int n;
    while (cin >> n) {
        string vetor[n];
        for (int i = 0; i < n; i++)
            cin >> vetor[i];
        string temp[n];
        long long inversoes = merge_sort(vetor, temp, 0, n - 1);
        cout << inversoes << endl;
    }

    return 0;
}
