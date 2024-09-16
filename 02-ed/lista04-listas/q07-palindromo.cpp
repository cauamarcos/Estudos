#include <iostream>
using namespace std;

class Noh {
    friend class lista;
    private:
        char mDado;
        Noh* mPtProx;
    public:
        Noh (char letra);
};

Noh::Noh (char letra) {
    mDado = letra;
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
        void inserirEmListaVazia (char letra);
        void inserirNoFinal (char letra);
        char retirarNoInicio ();
        char retirarNoFim ();
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

void lista::inserirEmListaVazia (char letra) {
    Noh* novo = new Noh (letra);
    mInicio = novo;
    mFim = novo;
    mTamanho++;
}

void lista::inserirNoFinal (char letra) {
    if (Vazia ())
        inserirEmListaVazia (letra);
    else {
        Noh* novo = new Noh (letra);
        mFim->mPtProx = novo;
        mFim = novo;
        mTamanho++;
    }
}

char lista::retirarNoInicio () {
    char letra;
    Noh *aux = mInicio;
    letra = aux->mDado;
    mInicio = aux->mPtProx;
    delete aux;
    mTamanho--;
    if (Vazia ()) {
        mFim = NULL;
        mInicio = NULL;
    }
    return letra;
}

char lista::retirarNoFim () {
    char letra = mFim->mDado;
    Noh* aux = mInicio;
    Noh* anterior = NULL;
    while (aux->mPtProx != NULL) {
        anterior = aux;
        aux = aux->mPtProx;
    }
    if (anterior == NULL)
        mInicio = NULL;
    else
        anterior->mPtProx = NULL;
    delete mFim;
    mFim = anterior;
    mTamanho--;
    return letra;
}

int main () {
    lista Lista;
    char letra;
    bool ok;
    while ((cin >> letra) and letra != '#')
        Lista.inserirNoFinal (letra);
    if (not Lista.Vazia ())
        ok = true;
    else
        ok = false;
    while (Lista.tamanho () > 1 and ok) {
        if (Lista.retirarNoInicio () != Lista.retirarNoFim ())
            ok = false;
    }
    if (ok)
        cout << "sim" << endl;
    else {
        cout << "nao" << endl;
    }

    return 0;
}
