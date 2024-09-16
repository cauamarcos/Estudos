#include <iostream>
using namespace std;

class noh {
    friend class pilha;
    private:
        int mValor;
        noh* mProximo;
    public:
        noh (int valor);
};

noh::noh (int valor) {
    mValor = valor;
    mProximo = NULL;
}

class pilha {
    private:
        noh* mTopo;
        int mTamanho;
    public:
        pilha ();
        ~pilha ();
        void empilhar (int valor);
        int desempilhar ();
        void ordenar ();
};

pilha::pilha () {
    mTopo = NULL;
    mTamanho = 0;
}

pilha::~pilha () {
    while (mTopo)
        desempilhar ();
}

void pilha::empilhar (int valor) {
    noh* novo = new noh (valor);
    novo->mProximo = mTopo;
    mTopo = novo;
    mTamanho++;
}

int pilha::desempilhar () {
    int valor = mTopo->mValor;
    noh* temp = mTopo;
    mTopo = mTopo->mProximo;
    delete temp;
    mTamanho--;
    return valor;
}

void pilha::ordenar () {
    pilha aux;
    int maior, var, tamanho;
    tamanho = mTamanho;
    for (int i = 0; i < mTamanho; i++) {
        maior = mTopo->mValor;
        for (int j = 0; j < tamanho; j++) {
            var = desempilhar ();
            if (var > maior) {
                aux.empilhar (maior);
                maior = var;
            }
            else 
                aux.empilhar (var);
        }
        tamanho--;
        empilhar (maior);
        for (int j = 0; j < tamanho; j++) {
            empilhar (aux.desempilhar ());
        }
    }
}

int main () {
    pilha mPilha;
    int valor, qtd;
    cin >> qtd;
    for (int i = 0; i < qtd; i++) {
        cin >> valor;
        mPilha.empilhar (valor);
    }
    mPilha.ordenar ();
    for (int i = 0; i < qtd; i++) {
        cout << mPilha.desempilhar () << " ";
    }

    return 0;
}
