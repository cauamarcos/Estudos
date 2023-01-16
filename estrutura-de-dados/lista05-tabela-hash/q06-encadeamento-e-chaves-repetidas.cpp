#include <iostream>
using namespace std;

int funcaoHash (string s, int cap) {
    long h = 0;
    for (unsigned i = 0; i < s.length(); i++) {
        h = (83 * h + s[i]) % cap;
    }
    return h;
}

struct dado {
    string chave;
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
        dado retirarNoInicio ();
        void recuperar (string chave);
        void imprimir ();
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

dado lista::retirarNoInicio () {
    dado valor = mInicio->Dado;
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

void lista::recuperar (string chave) {
    string concatenar = "";
    if (not Vazia ()) {
        Noh* aux = mInicio;
        if (aux->Dado.chave == chave)
            concatenar += aux->Dado.valor;
        int tam = tamanho ();
        for (int i = 1; i < tam; i++) {
            aux = aux->mPtProx;
            if (aux->Dado.chave == chave)
                concatenar += aux->Dado.valor;
        }
    }
    cout << concatenar << endl;
}

void lista::imprimir () {
    if (not Vazia ()) {
        Noh* aux = mInicio;
        cout << "[" << aux->Dado.chave << "/" << aux->Dado.valor << "]->";
        int tam = tamanho ();
        for (int i = 1; i < tam; i++) {
            aux = aux->mPtProx;
            cout << "[" << aux->Dado.chave << "/" << aux->Dado.valor << "]->";
        }
    }
    cout << "NULL  ";
}

class TabelaHash {
    private:
        int capacidade;
        lista* tabela;
    public:
        TabelaHash (int cap);
        ~TabelaHash ();
        void inserir (dado valor);
        void Recuperar (string chave);
        void depurar ();
};

TabelaHash::TabelaHash (int cap) {
    capacidade = cap;
    tabela = new lista [cap];
}

TabelaHash::~TabelaHash () {
    delete [] tabela;
}

void TabelaHash::inserir (dado valor) {
    int pos = funcaoHash (valor.chave, capacidade);
    tabela [pos].inserirNoFinal (valor);
}

void TabelaHash::Recuperar (string chave) {
    int pos = funcaoHash (chave, capacidade);
    tabela [pos].recuperar (chave);
}

void TabelaHash::depurar () {
    for (int i = 0; i < capacidade; i++) {
        cout << i << ":";
        tabela [i].imprimir ();
    }
    cout << endl;
}

int main () {
    int cap;
    char comando;
    cin >> cap >> comando;
    dado Dado;
    TabelaHash Tabela (cap);
    string key;
    while (comando != 'Q') {
        if (comando == 'I') {
            cin >> Dado.chave >> Dado.valor;
            Tabela.inserir (Dado);
        }
        else if (comando == 'R') {
            cin >> key;
            Tabela.Recuperar (key);
        }
        else if (comando == 'P')
            Tabela.depurar ();
        cin >> comando;
    }

    return 0;
}
