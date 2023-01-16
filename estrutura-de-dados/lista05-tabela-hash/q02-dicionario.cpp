#include <iostream>
using namespace std;

struct dado {
    string palavra;
    string significado;
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
        int buscar (string nome);
        void imprimir (string nome);
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

int lista::buscar (string nome) {
    if (Vazia ())
        return -1;
    else {
        Noh* aux = mInicio;
        if (aux->Dado.palavra == nome)
            return 0;
        for (int i = 1; i < mTamanho; i++) {
            aux = aux->mPtProx;
            if (aux->Dado.palavra == nome)
                return i;
        }
        return -1;
    }
}

void lista::imprimir (string nome) {
    bool ok = false;
    if (not Vazia ()) {
        Noh* aux = mInicio;
        if (aux->Dado.palavra == nome) {
            cout << "[" << aux->Dado.palavra << "] => " << aux->Dado.significado << endl;
            ok = true;
        }
        for (int i = 1; i < mTamanho; i++) {
            aux = aux->mPtProx;
            if (aux->Dado.palavra == nome) {
                cout << "[" << aux->Dado.palavra << "] => " << aux->Dado.significado << endl;
                ok = true;
            }
        }
    }
    if (not ok)
        cout << "[" << nome << "] => NULL" << endl;
}

class TabelaHash {
    private:
        int capacidade;
        lista* tabela;
    public:
        TabelaHash ();
        ~TabelaHash ();
        void inserir (dado valor);
        void depurar (string chave);
};

TabelaHash::TabelaHash () {
    capacidade = 23;
    tabela = new lista [23];
}

TabelaHash::~TabelaHash () {
    delete [] tabela;
}

void TabelaHash::inserir (dado valor) {
    int pos = valor.palavra.size () % 101;
    if (tabela [pos].buscar (valor.palavra) == -1) {
        tabela [pos].inserirNoFinal (valor);
    }
}

void TabelaHash::depurar (string chave) {
    int pos = chave.size () % 23;
    tabela [pos].imprimir (chave);
}

int main () {
    int qtd;
    TabelaHash Tabela;
    string pal, sig;
    cin >> qtd;
    for (int i = 0; i < qtd; i++) {
        cin >> pal;
        getline (cin, sig);
        dado Dado;
        Dado.palavra = pal;
        Dado.significado = sig;
        Tabela.inserir (Dado);
    }
    cin >> pal;
    while (pal != "-1") {
        Tabela.depurar (pal);
        cin >> pal;
    }

    return 0;
}
