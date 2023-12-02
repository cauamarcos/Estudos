#include <iostream>
using namespace std;

class Noh {
    friend class lista;
    private:
        int mDado;
        Noh* mPtProx;
    public:
        Noh (int d);
};

Noh::Noh (int num) {
    mDado = num;
    mPtProx = NULL;
}

class lista {
    private:
        Noh* mInicio;
        Noh* mFim;
        int mTamanho;
    public:
        lista ();
        ~lista ();
        void inserirEmListaVazia (int valor);
        void inserirNoFinal (int valor);
        int retirarNoInicio ();
        int percorrerLista ();
        void depurar ();
        bool Vazia () {return mTamanho == 0; }
        int tamanho () {return mTamanho; }
};

lista::lista () {
    mInicio = NULL;
    mFim = NULL;
    mTamanho = 0;
}

lista::~lista () {
    while (not Vazia ())
        retirarNoInicio ();
}

void lista::inserirEmListaVazia (int valor) {
    Noh* novo = new Noh (valor);
    mInicio = novo;
    mFim = novo;
    mTamanho++;
}

void lista::inserirNoFinal (int valor) {
    if (Vazia ())
        inserirEmListaVazia (valor);
    else {
        Noh* novo = new Noh (valor);
        mFim->mPtProx = novo;
        mFim = novo;
        mTamanho++;
    }
}

int lista::percorrerLista () {
    Noh* aux = mInicio;
    int cont = 0, valor = aux->mDado;
    while (valor != -1) {
        aux = aux->mPtProx;
        valor = aux->mDado;
        cont++;
    }
    return cont;
}

int lista::retirarNoInicio () {
    Noh *aux = mInicio;
    int valor = aux->mDado;
    mInicio = aux->mPtProx;
    delete aux;
    mTamanho--;
    if (Vazia ()) {
        mFim = NULL;
        mInicio = NULL;
    }
    return valor;
}

void lista::depurar () {
    Noh* aux = mInicio;
    int valor = aux->mDado;
    cout << valor << " ";
    for (int i = 0; i < mTamanho; i++) {
        aux = aux->mPtProx;
        valor = aux->mDado;
        if (valor >= 0)
            cout << valor << " ";
    }
}

int main() {
    lista lista1, lista2, lista3;
    int num = 0;
    while (num != -1) {
        cin >> num;
        lista1.inserirNoFinal (num);
    }
    num = 0;
    while (num != -1) {
        cin >> num;
        lista2.inserirNoFinal (num);
    }
    int tam1 = lista1.percorrerLista ();
    int tam2 = lista2.percorrerLista (), tam3, armazenaDezena = 0;
    if (tam1 > tam2)
        tam3 = tam1;
    else
        tam3 = tam2;
    for (int i = tam3; i > 0; i--) {
        int soma = armazenaDezena;
        if (lista1.tamanho () > 1)
            soma += lista1.retirarNoInicio ();
        if (lista2.tamanho () > 1)
            soma += lista2.retirarNoInicio ();
        if (soma > 9) {
            armazenaDezena = soma / 10;
            soma %= 10;
        }
        else
            armazenaDezena = 0;
        lista3.inserirNoFinal (soma);
    }
    if (armazenaDezena > 0)
        lista3.inserirNoFinal (armazenaDezena);
    while (not lista3.Vazia ())
        cout << lista3.retirarNoInicio () << " ";

    return 0;
}
