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
        void removerPosicao (int pos);
        int retirarNoInicio ();
        int retirarNoFim ();
        bool Vazia () {return mTamanho == 0; }
        int tamanho () {return mTamanho; }
        void remove (lista &Lista);
        int buscar (int num);
        void depurar ();
        void depurarInvertida ();
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

int lista::retirarNoFim () {
    int valor = mFim->mDado;
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
    return valor;
}

int lista::retirarNoInicio () {
    int valor = mInicio->mDado;
    Noh *aux = mInicio;
    mInicio = aux->mPtProx;
    delete aux;
    mTamanho--;
    if (Vazia ()) {
        mInicio = NULL;
        mFim = NULL;
    }
    return valor;
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


void lista::remove (lista &Lista) {
    int num;
    while (not Lista.Vazia ()) {
        int pos = 0;
        num = Lista.retirarNoInicio ();
        while (pos != -1) {
            pos = buscar (num);
            if (pos != -1)
                removerPosicao (pos);
        }
    }
}

void lista::depurar () {
    if (mTamanho > 0) {
        Noh *aux = mInicio;
        while (aux->mPtProx != NULL) {
            cout << aux->mDado << " ";
            aux = aux->mPtProx;
        }
        cout << aux->mDado << endl;
    }
}

void lista::depurarInvertida () {
    if (mTamanho > 0) {
        int cont = 0;
        for (int i = 0; i < mTamanho - 1; i++) {
            Noh *anterior, *aux = mInicio;
            for (int j = 0; j < mTamanho - cont; j++) {
                anterior = aux;
                aux = aux->mPtProx;
            }
            cont++;
            cout << anterior->mDado << " ";
        }
        cout << mInicio->mDado;
    }
}
    
int main () {
    lista lista1, lista2, lista3;
    int qtd, num;
    cin >> qtd;
    for (int i = 0; i < qtd; i++) {
        cin >> num;
        lista1.inserirNoFinal (num);
    }
    cin >> qtd;
    for (int i = 0; i < qtd; i++) {
        cin >> num;
        lista2.inserirNoFinal (num);
    }
    lista1.remove (lista2);
    if (lista1.Vazia ())
        cout << "-1";
    else {
        lista1.depurar ();
        lista1.depurarInvertida ();
    }
    
    return 0;
}
