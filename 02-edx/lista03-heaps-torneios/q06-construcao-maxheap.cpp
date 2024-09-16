#include <iostream>
using namespace std;

class maxHeap {
    private:
        int *arranjo;
        int capacidade;
        int mTamanho;
    public:
        maxHeap (int *vetor, int cap);
        ~maxHeap ();
        //em todas as funções, o parâmetro i representa a posição de um elemento no arranjo
        int esquerdo (int i) {return 2 * i + 1; }
        int direito (int i) {return 2 * i + 2; }
        void corrigeDescendo (int i);
};

maxHeap::maxHeap (int *vetor, int cap) {
    capacidade = cap;
    arranjo = new int [capacidade];
    mTamanho = cap;
    for (int i = 0; i < cap; i++)
        arranjo [i] = vetor [i];
}

maxHeap::~maxHeap () {
    delete [] arranjo;
}

void maxHeap::corrigeDescendo (int i) {
    int filhoEsquerdo = esquerdo (i);
    int filhoDireito = direito (i);
    int maior = i;
    if (filhoEsquerdo <= (mTamanho - 1) and (arranjo [filhoEsquerdo] > arranjo [maior])) 
        maior = filhoEsquerdo;
    if (filhoDireito <= (mTamanho - 1) and (arranjo [filhoDireito] > arranjo [maior])) 
        maior = filhoDireito;
    if (maior != i) {
        int aux = arranjo [i];
        arranjo [i] = arranjo [maior];
        arranjo [maior] = aux;
        corrigeDescendo (maior);
    }
    else {
        for (int j = 0; j < capacidade; j++)
            cout << arranjo [j] << " ";
        cout << endl;
    }
}

int main () {
    int cap, *vetor;
    cin >> cap;
    vetor = new int [cap];
    for (int i = 0; i < cap; i++)
        cin >> vetor [i];
    maxHeap heap (vetor, cap);
    int metade = (cap - 2) / 2;
    for (int i = metade; i >= 0; i--) {
        cout << i << ": ";
        heap.corrigeDescendo (i);
    }

    return 0;
}
