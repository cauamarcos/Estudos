#include <iostream>
using namespace std;

struct dado {
    int chave;
    string valor;
};

class Noh {
    friend class abb;
    private:
        dado Dado;
        Noh* esq;
        Noh* dir;
    public:
        Noh (dado mDado);
};

Noh::Noh (dado mDado) {
    Dado = mDado;
    dir = NULL;
    esq = NULL;
}

class abb {
    private:
        Noh* raiz;
        Noh* inserirRecAux (Noh* Raiz, dado mDado);
        void percorreEmOrdemAux (Noh* umNoh);
        void destrutorRec (Noh* umNoh);
        Noh* buscaAux (int d);
    public:
        abb ();
        ~abb ();
        void inserirRecursivamente (dado mDado);
        void percorreEmOrdem ();
        void busca (int d);
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

void abb::inserirRecursivamente (dado mDado) {
    raiz = inserirRecAux (raiz, mDado);
}

void abb::percorreEmOrdem () {
    percorreEmOrdemAux (raiz);
}

Noh* abb::inserirRecAux (Noh* umNoh, dado mDado) {
    if (umNoh == NULL) {
        Noh* novo = new Noh (mDado);
        return novo;
    }
    else {
        if (mDado.chave < umNoh->Dado.chave)
            umNoh->esq = inserirRecAux (umNoh->esq, mDado);
        else
            umNoh->dir = inserirRecAux (umNoh->dir, mDado);
    }
    return umNoh;
}

void abb::percorreEmOrdemAux (Noh* umNoh) {
    if (umNoh != NULL) {
        percorreEmOrdemAux (umNoh->esq);
        cout << umNoh->Dado.valor << " ";
        percorreEmOrdemAux (umNoh->dir);
    }
}

void abb::busca (int d) {
    Noh* umNoh = buscaAux (d);
    if (umNoh == NULL)
        cout << "INEXISTENTE" << endl;
    else
        cout << umNoh->Dado.valor << endl;;
}

Noh* abb::buscaAux (int d) {
    Noh* atual = raiz;
    while (atual != NULL) {
        if (atual->Dado.chave == d)
            return atual;
        else if (atual->Dado.chave > d)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return atual;
}

int main () {
    abb ABB;
    char comando = 'a';
    dado mDado;
    int num;
    while (comando != 'f') {
        cin >> comando;
        if (comando == 'i') {
            cin >> mDado.chave >> mDado.valor;
            ABB.inserirRecursivamente (mDado);
        }
        else if (comando == 'b') {
            cin >> num;
            ABB.busca (num);
        }
        else if (comando == 'e') {
            ABB.percorreEmOrdem ();
            cout << endl;
        }
    }
    
    return 0;
}
