#include <iostream>
using namespace std;

class Noh {
    friend class deque;
    private:
        string mDado;
        Noh* mPtProx;
    public:
        Noh (string acao);
};

Noh::Noh (string acao) {
    mDado = acao;
    mPtProx = NULL;
}

class deque {
    private:
        Noh* mInicio;
        Noh* mFim;
        int mTamanho;
        int capacidade;
    public:
        deque (int cap);
        ~deque ();
        void inserirEmListaVazia (string acao);
        void inserirNoFinal (string acao);
        string retirarNoInicio ();
        void retirarNoFim ();
        bool Vazia () {return mTamanho == 0; }
        int tamanho () {return mTamanho; }
};

deque::deque (int cap) {
    mInicio = NULL;
    mFim = NULL;
    mTamanho = 0;
    capacidade = cap;
}

deque::~deque () {
    while (not Vazia ())
        retirarNoInicio ();
}

void deque::inserirEmListaVazia (string acao) {
    Noh* novo = new Noh (acao);
    mInicio = novo;
    mFim = novo;
    mTamanho++;
}

void deque::inserirNoFinal (string acao) {
    if (Vazia ())
        inserirEmListaVazia (acao);
    else {
        Noh* novo = new Noh (acao);
        mFim->mPtProx = novo;
        mFim = novo;
        mTamanho++;
    }
    if (mTamanho > capacidade) {
        string esquecida = retirarNoInicio ();
        cout << "esqueci: comando " << esquecida << endl;
    }
}

string deque::retirarNoInicio () {
    string esquecer = mInicio->mDado;
    Noh *aux = mInicio;
    mInicio = aux->mPtProx;
    delete aux;
    mTamanho--;
    if (Vazia ()) {
        mFim = NULL;
        mInicio = NULL;
    }
    return esquecer;
}

void deque::retirarNoFim () {
    cout << "desfazer: comando " << mFim->mDado << endl;
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

int main () {
    string acao, comando;
    int qtd;
    cin >> qtd;
    deque Lista (qtd);
    while ((cin >> comando) and comando != "sair") {
        if (comando == "comando") {
            cin >> acao;
            Lista.inserirNoFinal (acao);
        }
        else if (comando == "undo") {
            if (not Lista.Vazia ())
                Lista.retirarNoFim ();
            else
                cout << "ERRO" << endl;
        }
    }

    return 0;
}
