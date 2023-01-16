#include <iostream>
using namespace std;

struct funcionario {
    string nome;
    int dia;
    int mes;
    int ano;
};

class Noh {
    friend class lista;
    private:
        funcionario Dado;
        Noh* mPtProx;
    public:
        Noh (funcionario d);
};

Noh::Noh (funcionario d) {
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
        void inserirEmListaVazia (funcionario valor);
        void inserirNoFinal (funcionario valor);
        funcionario retirarNoInicio ();
        void buscar (int dia, int mes);
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

void lista::inserirEmListaVazia (funcionario valor) {
    Noh* novo = new Noh (valor);
    mInicio = novo;
    mFim = novo;
    mTamanho++;
}

void lista::inserirNoFinal (funcionario valor) {
    if (Vazia ())
        inserirEmListaVazia (valor);
    else {
        Noh* novo = new Noh (valor);
        mFim->mPtProx = novo;
        mFim = novo;
        mTamanho++;
    }
}

funcionario lista::retirarNoInicio () {
    funcionario valor = mInicio->Dado;
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

void lista::buscar (int dia, int mes) {
    int cont = 0;
    if (not Vazia ()) {
        Noh* aux = mInicio;
        if (aux->Dado.dia == dia and aux->Dado.mes == mes)
            cont++;
        int tam = tamanho ();
        for (int i = 1; i < tam; i++) {
            aux = aux->mPtProx;
            if (aux->Dado.dia == dia and aux->Dado.mes == mes)
                cont++;
        }
    }
    cout << cont << " ";
}

class TabelaHash {
    private:
        int capacidade;
        float posOcupadas;
        lista* tabela;
    public:
        TabelaHash (int cap);
        ~TabelaHash ();
        void inserir (funcionario valor);
        void Buscar (int dia, int mes);
};

TabelaHash::TabelaHash (int cap) {
    capacidade = cap;
    posOcupadas = 0;
    tabela = new lista [cap];
}

TabelaHash::~TabelaHash () {
    delete [] tabela;
}

void TabelaHash::inserir (funcionario valor) {
    int pos = (valor.dia * valor.mes - 1) % capacidade;
    if (tabela [pos].Vazia ())
        posOcupadas++;
    tabela [pos].inserirNoFinal (valor);
}

void TabelaHash::Buscar (int dia, int mes) {
    int pos = (dia * mes - 1) % capacidade;
    tabela [pos].buscar (dia , mes);
    cout << float (posOcupadas) / capacidade << endl;
}

int main () {
    int cap, qtd, dia, mes;
    cin >> cap >> qtd;
    TabelaHash Tabela (cap);
    funcionario alguem;
    for (int i = 0; i < qtd; i++) {
        cin >> alguem.nome >> alguem.dia >> alguem.mes >> alguem.ano;
        Tabela.inserir (alguem);
    }
    cin >> dia >> mes;
    Tabela.Buscar (dia, mes);

    return 0;
}
