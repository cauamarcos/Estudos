#include <iostream>
using namespace std;

struct Elemento {
    unsigned dado;
    int prioridade;
};

class Heap {
    private:
        Elemento *arranjo;
        int capacidade;
        int mTamanho;
    public:
        Heap (int cap);
        ~Heap ();
        int pai (int i) {return (i - 1) / 2; } //em todas as funções, o parâmetro i representa a posição de um elemento no arranjo
        int esquerdo (int i) {return (2 *i + 1); }
        int direito (int i) {return (2 *i + 2); }
        void corrigeDescendo (int i);
        void corrigeSubindo (int i);
        bool vazia () {return mTamanho == 0; }
        Elemento retiraRaiz ();
        void inserir (Elemento valor);
        void alterarPrioridade ();
        void depurar ();
};

Heap::Heap (int cap) {
    capacidade = cap;
    arranjo = new Elemento [capacidade];
    mTamanho = 0;
}

Heap::~Heap () {
    delete [] arranjo;
}

void Heap::corrigeDescendo (int i) {
    int filhoEsquerdo = esquerdo (i);
    int filhoDireito = direito (i);
    int maior = i;
    if (filhoEsquerdo < mTamanho and (arranjo [filhoEsquerdo].prioridade > arranjo [maior].prioridade)) 
        maior = filhoEsquerdo;
    if (filhoDireito < mTamanho and (arranjo [filhoDireito].prioridade > arranjo [maior].prioridade)) 
        maior = filhoDireito;
    if (maior != i) {
        Elemento aux = arranjo [i];
        arranjo [i] = arranjo [maior];
        arranjo [maior] = aux;
        corrigeDescendo (maior);
    }
}

Elemento Heap::retiraRaiz () {
    Elemento valor = arranjo [0];
    arranjo [0] = arranjo [mTamanho - 1];
    arranjo [mTamanho - 1] = valor;
    mTamanho--;
    corrigeDescendo (0);
    return valor;
}

void Heap::corrigeSubindo (int i) {
    int Pai = pai (i);
    if (arranjo [i].prioridade > arranjo [Pai].prioridade) {
        Elemento aux = arranjo [i];
        arranjo [i] = arranjo [Pai];
        arranjo [Pai] = aux;
        corrigeSubindo (Pai);
    }
}

void Heap::inserir (Elemento valor) {
    arranjo [mTamanho] = valor;
    if (mTamanho > 0)
        corrigeSubindo (mTamanho);
    mTamanho++;
}

void Heap::alterarPrioridade () {
    Elemento novo;
    cin >> novo.dado >> novo.prioridade;
    for (int i = 0; i < mTamanho; i++) {
        if (arranjo [i].dado == novo.dado) {
            int prioridadeAntiga = arranjo [i].prioridade;
            arranjo [i] = novo;
            if (prioridadeAntiga < novo.prioridade)
                corrigeSubindo (i);
            else
                corrigeDescendo (i);
            i = mTamanho;
        }
    }
}

void Heap::depurar () {
    for (int i = 0; i < mTamanho; i++)
        cout << "[" << arranjo [i].dado << "/" << arranjo [i].prioridade << "] ";
    cout << endl;
}

int main() {
    int cap;
    cin >> cap;
    Heap heap(cap);
    Elemento elemento;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'I': // inserir um elemento no heap
                cin >> elemento.dado >> elemento.prioridade;
                heap.inserir(elemento);
                break;
            case 'R': // retira um elemento do heap
                if (not heap.vazia ()) {
                    elemento = heap.retiraRaiz ();
                    cout << elemento.dado << endl;
                }
                else
                    cout << "erro" << endl;
                break;
            case 'A':
                heap.alterarPrioridade ();
                break;
            case 'P':
                heap.depurar ();
                break;
            case 'Q': //sair
                break;
        }
    } 
    while (comando != 'Q');

    return 0;
}
