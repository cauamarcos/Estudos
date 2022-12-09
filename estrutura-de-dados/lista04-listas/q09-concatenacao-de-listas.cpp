#include <iostream>
using namespace std;

class Noh {
    friend class lista;
    private:
        int mDado;
        Noh* mPtProx;
    public:
        Noh (int aluno);
};

Noh::Noh (int aluno) {
    mDado = aluno;
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
        void retirarNoInicio ();
        void retirarNoFim ();
        bool Vazia () {return mTamanho == 0; }
        int tamanho () {return mTamanho; }
        int buscar (int num);
        void removerPosicao (int pos);
        void depurar ();
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
    mTamanho = 1;
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

void lista::retirarNoFim () {
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
}

void lista::retirarNoInicio () {
    Noh *aux = mInicio;
    mInicio = aux->mPtProx;
    delete aux;
    mTamanho--;
    if (Vazia ()) {
        mInicio = NULL;
        mFim = NULL;
    }
}

int lista::buscar (int num) {
    if (Vazia ())
        return -1;
    else {
        Noh* aux = mInicio;
        if (aux->mDado == num)
            return 0;
        else {
            for (int i = 1; i < mTamanho; i++) {
                aux = aux->mPtProx;
                if (aux->mDado == num)
                    return i;
            }
        }
        return -1;
    }
}

void lista::removerPosicao (int pos) {
    if (pos == 0)
        retirarNoInicio ();
    else if (pos == mTamanho - 1)
        retirarNoFim ();
    else {
        Noh *anterior, *aux = mInicio;
        for (int i = 0; i < pos; i++) {
            anterior = aux;
            aux = aux->mPtProx;
        }
        anterior->mPtProx = aux->mPtProx;
        mTamanho--;
        delete aux;
    }
}

void lista::depurar () {
    if (mTamanho > 0) {
        Noh *aux = mInicio;
        while (aux->mPtProx != NULL) {
            cout  << aux->mDado << " ";
            aux = aux->mPtProx;
        }
        cout << aux->mDado << endl;
    }
}

int main () {
    int num, vetor [3];
    lista lista1, lista2, lista3;
    for (int i = 0; i < 5; i++) {
        cin >> num;
        lista1.inserirNoFinal (num);
        lista3.inserirNoFinal (num);
    }
    for (int i = 0; i < 5; i++) {
        cin >> num;
        lista2.inserirNoFinal (num);
        lista3.inserirNoFinal (num);
    }
    for (int i = 0; i < 3; i++)
        cin >> vetor [i];
    lista3.depurar ();
    for (int i = 0; i < 3; i++) {
        int pos = lista3.buscar (vetor [i]);
        if (pos != -1)
            lista3.removerPosicao (pos);
    }
    lista1.depurar ();
    lista2.depurar ();
    lista3.depurar ();

    return 0;
}
