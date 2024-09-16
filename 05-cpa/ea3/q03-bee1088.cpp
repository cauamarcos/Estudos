#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n > 0) {
        int vetor[n], cont = 0;
        for(int i = 0; i < n; i++)
            cin >> vetor[i];
        for(int i = 0; i < n; i++) {
            while(vetor[i] != i+1) {
                int aux = vetor[i];
                vetor[i] = vetor[aux-1];
                vetor[aux-1] = aux;
                cont++;
            }
        }
        if(cont % 2 == 0)
            cout << "Carlos" << endl;
        else
            cout << "Marcelo" << endl;
        cin >> n;
    }

    return 0;
}
