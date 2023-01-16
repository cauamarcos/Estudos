#include <iostream>
using namespace std;

struct dado {
    int chave = -1;
    string valor = "";
};

class Noh {
    friend class lista;
    private:
        dado Dado;
        Noh* mPtProx;
    public:
        Noh (dado d);
};

Noh::Noh (dado d) {
    Dado = d;
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
        void inserirEmListaVazia (dado valor);
        void inserirNoFinal (dado valor);
        void retirarNoInicio ();
        int buscar (int chave);
        void imprimir (int chave);
        void imprimirTudo ();
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

void lista::inserirEmListaVazia (dado valor) {
    Noh* novo = new Noh (valor);
    mInicio = novo;
    mFim = novo;
    mTamanho++;
}

void lista::inserirNoFinal (dado valor) {
    if (Vazia ())
        inserirEmListaVazia (valor);
    else {
        Noh* novo = new Noh (valor);
        mFim->mPtProx = novo;
        mFim = novo;
        mTamanho++;
    }
}

void lista::retirarNoInicio () {
    Noh *aux = mInicio;
    mInicio = aux->mPtProx;
    delete aux;
    mTamanho--;
    if (Vazia ()) {
        mFim = NULL;
        mInicio = NULL;
    }
}

int lista::buscar (int chave) {
    if (Vazia ())
        return -1;
    else {
        Noh* aux = mInicio;
        if (aux->Dado.chave == chave)
            return 0;
        for (int i = 1; i < mTamanho; i++) {
            aux = aux->mPtProx;
            if (aux->Dado.chave == chave)
                return i;
        }
        return -1;
    }
}

void lista::imprimir (int chave) {
    Noh* aux = mInicio;
    if (aux->Dado.chave == chave)
        cout << aux->Dado.valor << endl;
    for (int i = 1; i < mTamanho; i++) {
        aux = aux->mPtProx;
        if (aux->Dado.chave == chave)
            cout << aux->Dado.valor << endl;
    }
}

void lista::imprimirTudo () {
    int cont = 0;
    if (not Vazia ()) {
        Noh* aux = mInicio;
        while (aux->mPtProx != NULL) {
            cout << "[" << aux->Dado.chave << "/" << aux->Dado.valor << "]";
            aux = aux->mPtProx;
            cont++;
        }
        cout << "[" << aux->Dado.chave << "/" << aux->Dado.valor << "]";
        cont++;
    }
    while (cont < 4) {
        cout << "[-1/]";
        cont++;
    }
}

class TabelaHash {
    private:
        int tamanho;
        lista* tabela;
    public:
        TabelaHash (int cap);
        ~TabelaHash ();
        void inserir (dado valor);
        void recuperar (int chave);
        void depurar ();
};

TabelaHash::TabelaHash (int cap) {
    tamanho = cap;
    tabela = new lista [cap];
}

TabelaHash::~TabelaHash () {
    delete [] tabela;
}

void TabelaHash::inserir (dado valor) {
    int pos = valor.chave % tamanho;
    if (tabela [pos].buscar (valor.chave) == -1 and tabela [pos].tamanho () < 4) {
        tabela [pos].inserirNoFinal (valor);
    }
    else if (tabela [pos].buscar (valor.chave) != -1)
        cout << "ITEM JÁ ESTÁ NA TABELA!" << endl;
    else if (tabela [pos].tamanho () == 4)
        cout << "NÚMERO MÁXIMO DE COLISÕES PARA CHAVE!" << endl;
}

void TabelaHash::recuperar (int chave) {
    int pos = chave % tamanho;
    if (tabela [pos].buscar (chave) != -1)
        tabela [pos].imprimir (chave);
    else
        cout << "NÃO ENCONTRADO!" << endl;
}

void TabelaHash::depurar () {
    for (int i = 0; i < tamanho; i++) {
        cout << i << ":";
        tabela [i].imprimirTudo ();
        cout << endl;
    }
}

int main () {
    int tam, qtd, num;
    cin >> tam >> qtd;
    TabelaHash Tabela (tam);
    dado Dado;
    for (int i = 0; i < qtd; i++) {
        cin >> Dado.chave >> Dado.valor;
        Tabela.inserir (Dado);
    }
    for (int i = 0; i < 4; i++) {
        cin >> num;
        Tabela.recuperar (num);
    }
    Tabela.depurar ();

    return 0;
}
