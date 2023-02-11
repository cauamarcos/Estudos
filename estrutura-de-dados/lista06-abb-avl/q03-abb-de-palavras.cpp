#include <iostream>
#include <fstream>
using namespace std;

class Noh {
    friend class abb;
    private:
        string palavra;
        int* posicoes;
        int cont;
        Noh* esq;
        Noh* dir;
    public:
        Noh (string mDado, int pos);
};

Noh::Noh (string mDado, int pos) {
    palavra = mDado;
    posicoes = new int [1];
    posicoes [0] = pos;
    cont = 1;
    esq = NULL;
    dir = NULL;
}

class abb {
    private:
        Noh* raiz;
        void destrutorRec (Noh* umNoh);
        Noh* inserirRecAux (Noh* Raiz, string mDado, int pos);
        Noh* buscaAux (string palavra);
        bool buscaInserirAux (string palavra, int pos);
    public:
        abb ();
        ~abb ();
        void inserirRecursivamente (string mDado, int pos);
        void busca (string palavra);
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

void abb::inserirRecursivamente (string mDado, int pos) {
    if (not buscaInserirAux (mDado, pos))
        raiz = inserirRecAux (raiz, mDado, pos);
}

Noh* abb::inserirRecAux (Noh* umNoh, string mDado, int pos) {
    if (umNoh == NULL) {
        Noh* novo = new Noh (mDado, pos);
        return novo;
    }
    else {
        if (mDado < umNoh->palavra)
            umNoh->esq = inserirRecAux (umNoh->esq, mDado, pos);
        else
            umNoh->dir = inserirRecAux (umNoh->dir, mDado, pos);
    }
    return umNoh;
}

bool abb::buscaInserirAux (string palavra, int pos) {
    Noh* umNoh = buscaAux (palavra);
    if (umNoh == NULL)
        return false;
    else {
        umNoh->cont++;
        int aux = umNoh->cont;
        int* vetor = umNoh->posicoes;
        umNoh->posicoes = new int [aux];
        for (int i = 0; i < aux - 1; i++)
            umNoh->posicoes [i] = vetor [i];
        umNoh->posicoes [aux - 1] = pos;
        return true;
    }
}

void abb::busca (string palavra) {
    Noh* umNoh = buscaAux (palavra);
    if (umNoh == NULL)
        cout << "-1";
    else
        for (int i = 0; i < umNoh->cont; i++)
            cout << umNoh->posicoes [i] << " ";
    cout << endl;
}

Noh* abb::buscaAux (string palavra) {
    Noh* atual = raiz;
    while (atual != NULL) {
        if (atual->palavra == palavra)
            return atual;
        else {
            if (atual->palavra > palavra)
                atual = atual->esq;
            else
                atual = atual->dir;
        } 
    }
    return atual;
}

int main () {
    ifstream ler ("entrada.txt");
    abb ABB;
    string palavra;
    if (ler) {
        int pos = 0;
        while (ler >> palavra) {
            pos++;
            ABB.inserirRecursivamente (palavra, pos);
        }
        ler.close ();
    }
    cin >> palavra;
    ABB.busca (palavra);

    return 0;
}
