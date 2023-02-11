#include <iostream>
using namespace std;

class Noh {
    friend class abb;
    private:
        int valor;
        Noh* esq;
        Noh* dir;
    public:
        Noh (int mDado);
};

Noh::Noh (int mDado) {
    valor = mDado;
    dir = NULL;
    esq = NULL;
}

class abb {
    private:
        Noh* raiz;
        void destrutorRec (Noh* umNoh);
        Noh* inserirRecAux (Noh* Raiz, int mDado);
        Noh* buscaAux (int d);
    public:
        abb ();
        ~abb ();
        void inserirRecursivamente (int mDado);
        bool busca (int d);
};

abb::abb () {
    raiz = NULL;
}

abb::~abb () {
    destrutorRec (raiz);
}

void abb::destrutorRec (Noh* umNoh) {
    if (umNoh != NULL) { 
        destrutorRec (umNoh->esq);
        destrutorRec (umNoh->dir);
        delete umNoh;
    }
}

void abb::inserirRecursivamente (int mDado) {
    raiz = inserirRecAux (raiz, mDado);
}

Noh* abb::inserirRecAux (Noh* umNoh, int mDado) {
    if (umNoh == NULL) {
        Noh* novo = new Noh (mDado);
        return novo;
    }
    else {
        if (mDado < umNoh->valor)
            umNoh->esq = inserirRecAux (umNoh->esq, mDado);
        else
            umNoh->dir = inserirRecAux (umNoh->dir, mDado);
    }
    return umNoh;
}

bool abb::busca (int d) {
    Noh* umNoh = buscaAux (d);
    if (umNoh == NULL)
        return false;
    else
        return true;
}

Noh* abb::buscaAux (int d) {
    Noh* atual = raiz;
    while (atual != NULL) {
        if (atual->valor == d)
            return atual;
        else if (atual->valor > d)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return atual;
}

int main () {
    abb ABB;
    int num, cont = 0, contEsq = 0, contDir = 0;
    cin >> num;
    int raiz = num;
    while (num > 0) {
        if (not ABB.busca (num)) {
            if (cont > 0) {
                if (num > raiz)
                    contDir++;
                else
                    contEsq++;
            }
            cont++;
            ABB.inserirRecursivamente (num);
        }
        cin >> num;
    }
    cout << cont << " " << contEsq - contDir << endl;
    
    return 0;
}
