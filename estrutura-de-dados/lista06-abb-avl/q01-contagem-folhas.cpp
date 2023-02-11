#include <iostream>
using namespace std;

class Noh {
    friend class abb;
    private:
        int dado;
        Noh* filhoEsquerdo;
        Noh* filhoDireito;
    public:
        Noh (int valor);
};

Noh::Noh (int valor) {
    dado = valor;
    filhoDireito = NULL;
    filhoEsquerdo = NULL;
}

class abb {
    private:
        Noh* raiz;
        Noh* inserirRecAux (Noh* Raiz, int valor);
        void percorreEmOrdemAux (Noh* umNoh, int& cont);
        void destrutorRec (Noh* umNoh);
    public:
        abb ();
        ~abb ();
        void inserirRecursivamente (int valor);
        void percorreEmOrdem ();
};

abb::abb () {
    raiz = NULL;
}

abb::~abb () {
    destrutorRec (raiz);
}

void abb::destrutorRec (Noh* umNoh) {
    if (umNoh != NULL) { 
        destrutorRec (umNoh->filhoEsquerdo);
        destrutorRec (umNoh->filhoDireito);
        delete [] umNoh; 
    }
}

void abb::inserirRecursivamente (int valor) {
    raiz = inserirRecAux (raiz, valor);
}

Noh* abb::inserirRecAux (Noh* umNoh, int valor) {
    if (umNoh == NULL) {
        Noh* novo = new Noh (valor);
        return novo;
    }
    else {
        if (valor < umNoh->dado)
            umNoh->filhoEsquerdo = inserirRecAux (umNoh->filhoEsquerdo, valor);
        else
            umNoh->filhoDireito = inserirRecAux (umNoh->filhoDireito, valor);
    }
    return umNoh;
}

void abb::percorreEmOrdem () {
    int folhas = 0;
    percorreEmOrdemAux (raiz, folhas);
    cout << folhas << endl;
}

void abb::percorreEmOrdemAux (Noh* umNoh, int& cont) {
    if (umNoh != NULL) {
        percorreEmOrdemAux (umNoh->filhoEsquerdo, cont);
        if (umNoh->filhoEsquerdo == NULL and umNoh->filhoDireito == NULL)
            cont++;
        percorreEmOrdemAux (umNoh->filhoDireito, cont);
    }
}

int main () {
    abb ABB;
    int num, mValor;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> mValor;
        ABB.inserirRecursivamente (mValor);
    }
    ABB.percorreEmOrdem ();
    
    return 0;
}
