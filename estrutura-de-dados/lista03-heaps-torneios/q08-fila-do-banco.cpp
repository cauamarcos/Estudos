#include <iostream>
using namespace std;

struct Pessoa {
    int senha;
    int contador;
};

class maxHeap {
    private:
        Pessoa *arranjo;
        int capacidade;
        int mTamanho;
    public:
        maxHeap (int cap);
        ~maxHeap ();
        //em todas as funções, o parâmetro i representa a posição de um elemento no arranjo
        int pai (int i) {return (i - 1) / 2; }
        int esquerdo (int i) {return 2 * i + 1; }
        int direito (int i) {return 2 * i + 2; }
        int tamanho () {return mTamanho; }
        void corrigeDescendo (int i);
        void corrigeSubindo (int i);
        Pessoa retiraRaiz ();
        void inserir (Pessoa valor);
        bool vazia () {return mTamanho == 0; }
};

maxHeap::maxHeap (int cap) {
    capacidade = cap;
    arranjo = new Pessoa [capacidade];
    mTamanho = 0;
}

maxHeap::~maxHeap () {
    delete [] arranjo;
}

void maxHeap::corrigeDescendo (int i) {
    int filhoEsquerdo = esquerdo (i);
    int filhoDireito = direito (i);
    int maior = i;
    if (filhoEsquerdo < mTamanho and arranjo [filhoEsquerdo].contador > arranjo [maior].contador)
        maior = filhoEsquerdo;
    if (filhoDireito < mTamanho and arranjo [filhoDireito].contador > arranjo [maior].contador)
        maior = filhoDireito;
    if (maior != i) {
        Pessoa aux = arranjo [i];
        arranjo [i] = arranjo [maior];
        arranjo [maior] = aux;
        corrigeDescendo (maior);
    }
}

Pessoa maxHeap::retiraRaiz () {
    Pessoa valor = arranjo [0];
    arranjo [0] = arranjo [mTamanho - 1];
    arranjo [mTamanho - 1] = valor;
    mTamanho--;
    corrigeDescendo (0);
    return valor;
}

void maxHeap::corrigeSubindo (int i) {
    int Pai = pai (i);
    if (arranjo [i].contador > arranjo [Pai].contador) {
        Pessoa aux = arranjo [i];
        arranjo [i] = arranjo [Pai];
        arranjo [Pai] = aux;
        corrigeSubindo (Pai);
    }
}

void maxHeap::inserir (Pessoa valor) {
    arranjo [mTamanho] = valor;
    if (mTamanho > 0)
        corrigeSubindo (mTamanho);
    mTamanho++;
}

int main () {
    int cap, senha = 1, indice;
    cin >> cap;
    maxHeap heap (cap);
    char comando, tipo;
    Pessoa pessoa;
    int vetContadores[] = {50, 46, 42, 38};
    do {
        cin >> comando;
        switch (comando) {
            case 'c': // chegada
                cin >> tipo;
                if (heap.tamanho () == cap)
                    cout << "fila cheia" << endl;
                else {
                    switch (tipo) {
                        case 'P': indice = 0; break;
                        case 'V': indice = 1; break;
                        case 'C': indice = 2; break;
                        case 'N': indice = 3; break;
                    }
                    pessoa.senha = senha;
                    senha++;
                    pessoa.contador = vetContadores [indice];
                    vetContadores [indice]--;
                    if (vetContadores [indice] == 0) {
                        if (indice == 0)
                            vetContadores [indice] = 50;
                        else if (indice == 1)
                            vetContadores [indice] = 46;
                        else if (indice == 2)
                            vetContadores [indice] = 42;
                        else if (indice == 3)
                            vetContadores [indice] = 38;
                    }
                    heap.inserir (pessoa);
                    cout << pessoa.senha << " " << pessoa.contador << endl;
                }
                break;
            case 'a': // atendimento
                if (heap.vazia ())
                    cout << "ninguem na fila" << endl;
                else {
                    pessoa = heap.retiraRaiz ();
                    cout << pessoa.senha << endl;
                }
                break;
            case 's': //sair do programa
                break;
        }
    }
    while (comando != 's');

    return 0;
}
