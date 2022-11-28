#include <iostream>
using namespace std;

class maxHeap {
    private:
        int *arranjo;
        int capacidade;
        int mTamanho;
    public:
        maxHeap (int cap);
        ~maxHeap ();
        int pai (int i) {return (i - 1) / 2; } //em todas as funções, o parâmetro i representa a posição de um elemento no arranjo
        int esquerdo (int i) {return (2 *i + 1); }
        int direito (int i) {return (2 *i + 2); }
        void corrigeDescendo (int i);
        void corrigeSubindo (int i);
        void heapify (int *vetor, int tam);
        int retiraRaiz ();
        void inserir (int valor);
        void depurar ();
};

maxHeap::maxHeap (int cap) {
    capacidade = cap;
    arranjo = new int [capacidade];
    mTamanho = 15;
}

maxHeap::~maxHeap () {
    delete [] arranjo;
}

void maxHeap::corrigeDescendo (int i) {
    int filhoEsquerdo = esquerdo (i);
    int filhoDireito = direito (i);
    int maior = i;
    if (filhoEsquerdo < mTamanho and arranjo [filhoEsquerdo] > arranjo [maior]) 
        maior = filhoEsquerdo;
    if (filhoDireito < mTamanho and arranjo [filhoDireito] > arranjo [maior])
        maior = filhoDireito;
    if (maior != i) {
        int aux = arranjo [i];
        arranjo [i] = arranjo [maior];
        arranjo [maior] = aux;
        corrigeDescendo (maior);
    }
}

void maxHeap::heapify (int *vetor, int tam) { //constroiHeap ();
    for (int i = 0; i < tam; i++)
        arranjo [i] = vetor [i];
    int metade = (tam - 2) / 2;
    for (int i = metade; i >= 0; i--)
        corrigeDescendo (i);
}

int maxHeap::retiraRaiz () {
    int valor = arranjo [0];
    arranjo [0] = arranjo [mTamanho - 1];
    arranjo [mTamanho - 1] = valor;
    mTamanho--;
    corrigeDescendo (0);
    return valor;
}

void maxHeap::corrigeSubindo (int i) {
    int Pai = pai (i);
    if (arranjo [i] > arranjo [Pai]) {
        int aux = arranjo [i];
        arranjo [i] = arranjo [Pai];
        arranjo [Pai] = aux;
        corrigeSubindo (Pai);
    }
}

void maxHeap::inserir (int valor) {
    arranjo [mTamanho] = valor;
    corrigeSubindo (mTamanho);
    mTamanho++;
}

void maxHeap::depurar () {
    for (int i = 0; i < mTamanho; i++)
        cout <<  arranjo [i] << " ";
    cout << endl;
}

int main() {
    int vetor1 [15], vetor2 [5];
    for (int i = 0; i < 15; i++) 
        cin >> vetor1 [i];
    maxHeap heap (20);
    heap.heapify (vetor1, 15);
    heap.depurar ();
    for (int i = 0; i < 5; i++) 
        cin >> vetor2 [i];
    for (int i = 0; i < 5; i++) 
        heap.inserir (vetor2 [i]);
    heap.depurar ();
    for (int i = 0; i < 20; i++)
        cout << heap.retiraRaiz () << " ";

    return 0;
}
