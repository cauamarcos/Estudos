#include <iostream>
using namespace std;

class Noh {
    friend class abb;
    private:
        int valor;
        int cont;
        int nivel;
        Noh* esq;
        Noh* dir;
    public:
        Noh (int mDado);
};

Noh::Noh (int mDado) {
    valor = mDado;
    cont = 1;
    nivel = 0;
    dir = NULL;
    esq = NULL;
}

class abb {
    private:
        Noh* raiz;
        void destrutorRec (Noh* umNoh);
        Noh* inserirRecAux (Noh* Raiz, int mDado, int& nivel);
        Noh* removerRecAux (Noh* umNoh, int valor);
        Noh* minimoAux (Noh* raizSubArvore);
        Noh* removeMenor (Noh* raizSub);
        Noh* buscaAux (int d);
        void percorreEmOrdemAux (Noh* umNoh);
        void reduzirNiveis (Noh* umNoh);
    public:
        abb ();
        ~abb ();
        void inserirRecursivamente (int mDado);
        void removerRecursivamente (int valor);
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
        destrutorRec (umNoh->esq);
        destrutorRec (umNoh->dir);
        delete umNoh;
    }
}

void abb::inserirRecursivamente (int mDado) {
    Noh* busca = buscaAux (mDado);
    int nivel = 0;
    if (busca == NULL)
        raiz = inserirRecAux (raiz, mDado, nivel);
    else
        busca->cont++;
}

Noh* abb::inserirRecAux (Noh* umNoh, int mDado, int& nivel) {
    if (umNoh == NULL) {
        Noh* novo = new Noh (mDado);
        novo->nivel = nivel;
        return novo;
    }
    else {
        if (mDado < umNoh->valor) {
            nivel++;
            umNoh->esq = inserirRecAux (umNoh->esq, mDado, nivel);
        }
        else {
            nivel++;
            umNoh->dir = inserirRecAux (umNoh->dir, mDado, nivel);
        }
    }
    return umNoh;
}

void abb::removerRecursivamente (int valor) {
    Noh* umNoh = buscaAux (valor);
    if (umNoh != NULL) {
        if (umNoh->cont == 1) {
            reduzirNiveis (umNoh);
            raiz = removerRecAux (raiz, valor);
        }
        else
            umNoh->cont--;
    }
}

Noh* abb::removerRecAux (Noh* umNoh, int valor) {
    Noh* novaRaizSubArvore = umNoh;
    if (valor < umNoh->valor)
        umNoh->esq = removerRecAux (umNoh->esq, valor);
    else if (valor > umNoh->valor)
        umNoh->dir = removerRecAux (umNoh->dir, valor);
    else {
        if (umNoh->esq == NULL)
            novaRaizSubArvore = umNoh->dir;
        else if (umNoh->dir == NULL)
            novaRaizSubArvore = umNoh->esq;
        else {
            novaRaizSubArvore = minimoAux (umNoh->dir);
            novaRaizSubArvore->dir = removeMenor (umNoh->dir);
            novaRaizSubArvore->esq = umNoh->esq;
        }
        delete umNoh;
    }
    return novaRaizSubArvore;
}

void abb::reduzirNiveis (Noh* umNoh) {
    if (umNoh != NULL) {
        reduzirNiveis (umNoh->esq);
        umNoh->nivel--;
        reduzirNiveis (umNoh->dir);
    }
}

Noh* abb::minimoAux (Noh* raizSubArvore) {
    while (raizSubArvore->esq != NULL)
        raizSubArvore = raizSubArvore->esq;
    return raizSubArvore;
}

Noh* abb::removeMenor (Noh* raizSub) {
    if (raizSub->esq == NULL)
        return raizSub->dir;
    else {
        raizSub->esq = removeMenor (raizSub->esq);
        return raizSub;
    }
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

void abb::percorreEmOrdem () {
    percorreEmOrdemAux (raiz);
}

void abb::percorreEmOrdemAux (Noh* umNoh) {
    if (umNoh != NULL) {
        percorreEmOrdemAux (umNoh->esq);
        cout << umNoh->valor << "(" << umNoh->cont << ")/" << umNoh->nivel << " ";
        percorreEmOrdemAux (umNoh->dir);
    }
}

int main () {
    abb ABB;
    int num;
    for (int i = 0; i < 10; i++) {
        cin >> num;
        ABB.inserirRecursivamente (num);
    }
    ABB.percorreEmOrdem ();
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cin >> num;
        ABB.removerRecursivamente (num);
    }
    ABB.percorreEmOrdem ();
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cin >> num;
        ABB.inserirRecursivamente (num);
    }
    ABB.percorreEmOrdem ();
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cin >> num;
        ABB.removerRecursivamente (num);
    }
    ABB.percorreEmOrdem ();
    cout << endl;
    
    return 0;
}
