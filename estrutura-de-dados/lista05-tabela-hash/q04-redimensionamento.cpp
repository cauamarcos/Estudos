#include <iostream>
using namespace std;

struct dado {
    int chave;
    string valor;
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
        void retirarNoFim ();
        void removerPosicao (int pos);
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
    if (not Vazia ()) {
        Noh* aux = mInicio;
        cout << aux->Dado.chave << " " << aux->Dado.valor;
        aux = aux->mPtProx;
        if (aux != NULL)
            cout << endl << "Lista de colisao: ";
        while (aux != NULL) {
            cout << aux->Dado.chave << " " << aux->Dado.valor;
            aux = aux->mPtProx;
            if (aux != NULL)
                cout << ", ";
        }
    }
}

class TabelaHash {
    private:
        int capacidade;
        int numValores;
        float posOcupadas;
        lista* tabela;
    public:
        TabelaHash (int cap);
        ~TabelaHash ();
        void inserir (dado valor);
        void remover (int chave);
        void buscar (int chave);
        void depurar ();
};

TabelaHash::TabelaHash (int cap) {
    capacidade = cap;
    posOcupadas = 0;
    numValores = 0;
    tabela = new lista [cap];
}

TabelaHash::~TabelaHash () {
    delete [] tabela;
}

void TabelaHash::inserir (dado valor) {
    int pos = valor.chave % capacidade;
    int num = numValores, cont = 0;
    if (tabela [pos].Vazia ())
        posOcupadas++;
    if (posOcupadas >= (capacidade * 0.7)) {
        capacidade *= 2;
        dado vetor [numValores];
        for (int i = 0; i < capacidade / 2; i++) {
            while (not tabela [i].Vazia ()) {
                vetor [cont] = tabela [i].retirarNoInicio ();
                cont++;
            }
        }
        tabela = new lista [capacidade];
        posOcupadas = 0;
        numValores = 0;
        for (int i = 0; i < num; i++)
            inserir (vetor [i]);
    }
    if (tabela [pos].buscar (valor.chave) == -1) {
        tabela [pos].inserirNoFinal (valor);
        numValores++;
    }
}

void TabelaHash::remover (int chave) {
    int pos = chave % capacidade;
    int posicao = tabela [pos].buscar (chave);
    if (posicao != -1)
        tabela [pos].removerPosicao (posicao);
    else
        cout << "ERRO" << endl;
}

void TabelaHash::buscar (int chave) {
    int pos = chave % capacidade;
    if (tabela [pos].buscar (chave) != -1)
        tabela [pos].imprimir (chave);
    else
        cout << "ERRO" << endl;
}

void TabelaHash::depurar () {
    for (int i = 0; i < capacidade; i++) {
        cout << "Posicao " << i << ": ";
        tabela [i].imprimirTudo ();
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

int main () {
    int cap, chave;
    char comando;
    cin >> cap >> comando;
    TabelaHash Tabela (cap);
    while (comando != 'S') {
        if (comando == 'I') {
            dado Dado;
            cin >> Dado.chave >> Dado.valor;
            Tabela.inserir (Dado);
        }
        else if (comando == 'R') {
            cin >> chave;
            Tabela.remover (chave);
        }
        else if (comando == 'B') {
            cin >> chave;
            Tabela.buscar (chave);
        }
        else if (comando == 'P')
            Tabela.depurar ();
        cin >> comando;
    }

    return 0;
}
