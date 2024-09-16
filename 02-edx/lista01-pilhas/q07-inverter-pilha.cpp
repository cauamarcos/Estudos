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
        void inverter ();
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

void pilha::inverter () {
    pilha aux1, aux2;
    int tam = mTamanho;
    for (int i = 0; i < tam; i++) {
        aux1.empilhar (desempilhar ());
    }
    for (int i = 0; i < tam; i++) {
        aux2.empilhar (aux1.desempilhar ());
    }
    for (int i = 0; i < tam; i++) {
        empilhar (aux2.desempilhar ());
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
    mPilha.inverter ();
    for (int i = 0; i < qtd; i++) {
        cout << mPilha.desempilhar () << " ";
    }

    return 0;
}
