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
        void inserirNoInicio (int valor);
        int retirarNoInicio ();
        int retirarNoFim ();
        bool Vazia () {return mTamanho == 0; }
        int tamanho () {return mTamanho; }
};

lista::lista () {
    mInicio = NULL;
    mFim = NULL;
    mTamanho = 0;
}

lista::~lista () {
    while (mInicio != NULL) {
        Noh *aux = mInicio;
        mInicio = mInicio->mPtProx;
        delete aux;
        mTamanho--;
    }
    mFim = NULL;
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

void lista::inserirNoInicio (int valor) {
    if (Vazia ())
        inserirEmListaVazia (valor);
    else {
        Noh *novo = new Noh (valor);
        novo->mPtProx = mInicio;
        mInicio = novo;
    }
}

int lista::retirarNoFim () {
    int valor;
    Noh* aux = mInicio;
    Noh* anterior = NULL;
    while (aux->mPtProx != NULL) {
        anterior = aux;
        aux = aux->mPtProx;
    }
    valor = aux->mDado;
    if (anterior == NULL)
        mInicio = NULL;
    else
        anterior->mPtProx = NULL;
    delete mFim;
    mFim = anterior;
    mTamanho--;
    return valor;
}

int lista::retirarNoInicio () {
    Noh *aux = mInicio;
    int valor = aux->mDado;
    mInicio = aux->mPtProx;
    delete aux;
    mTamanho--;
    if (Vazia ())
        mFim = NULL;
    return valor;
}
    
int main () {
    lista lista1, lista2;
    int qtd, num, posSeparar;
    cin >> qtd;
    for (int i = 0; i < qtd; i++) {
        cin >> num;
        lista1.inserirNoFinal (num);
    }
    cin >> posSeparar;
    if (posSeparar > qtd - 1) {
        int tam = lista1.tamanho ();
        for (int i = 0; i < tam; i++)
            cout << lista1.retirarNoInicio () << " ";
        cout << endl << "-1";
    }
    else {
        while (lista1.tamanho () > posSeparar + 1) {
            num = lista1.retirarNoFim ();
            lista2.inserirNoInicio (num);
        }
        int tam = lista1.tamanho ();
        for (int i = 0; i < tam; i++)
            cout << lista1.retirarNoInicio () << " ";
        cout << endl;
        for (int i = 0; i < qtd - posSeparar - 1; i++)
            cout << lista2.retirarNoInicio () << " ";
    }
    
    return 0;
}
