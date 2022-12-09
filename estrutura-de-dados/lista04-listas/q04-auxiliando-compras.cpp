#include <iostream>
using namespace std;

struct Produto {
    string nome;
    int qtd;
};

class Noh {
    friend class lista;
    private:
        Produto mDado;
        Noh* mPtProx;
    public:
        Noh (Produto prod);
};

Noh::Noh (Produto prod) {
    mDado = prod;
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
        void inserirEmListaVazia (Produto produto);
        void inserirNoFinal (Produto produto);
        void retirarNoInicio ();
        void retirarNoFim ();
        void depurar ();
        int buscar (string nome, Produto &busca);
        void removerPosicao (int pos);
        bool Vazia () {return mTamanho == 0; }
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

void lista::inserirEmListaVazia (Produto produto) {
    Noh* novo = new Noh (produto);
    mInicio = novo;
    mFim = novo;
    mTamanho++;
}

void lista::inserirNoFinal (Produto produto) {
    if (Vazia ())
        inserirEmListaVazia (produto);
    else {
        Noh* novo = new Noh (produto);
        mFim->mPtProx = novo;
        mFim = novo;
        mTamanho++;
    }
}

int lista::buscar (string nome, Produto &busca) {
    if (Vazia ())
        return -1;
    else {
        Noh* aux = mInicio;
        if (aux->mDado.nome == nome) {
            busca = aux->mDado;
            return 0;
        }
        for (int i = 1; i < mTamanho; i++) {
            aux = aux->mPtProx;
            if (aux->mDado.nome == nome) {
                busca = aux->mDado;
                return i;
            }
        }
        return -1;
    }
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

void lista::depurar () {
    cout << "[";
    if (mTamanho > 0) {
        Noh *aux = mInicio;
        while (aux->mPtProx != NULL) {
            cout  << "(" << aux->mDado.nome << ", " << aux->mDado.qtd << "), ";
            aux = aux->mPtProx;
        }
        cout << "(" << aux->mDado.nome << ", " << aux->mDado.qtd << ")";
    }
    cout << "]" << endl;
}

int main () {
    lista Lista;
    Produto produto;
    string nome;
    char comando;
    int pos;
    do {
        cin >> comando;
        switch (comando) {
            case 'i':
                cin >> produto.nome >> produto.qtd;
                nome = produto.nome;
                if (Lista.buscar (nome, produto) == -1 and produto.qtd > 0)
                    Lista.inserirNoFinal (produto);
                break;
            case 'r':
                cin >> nome;
                pos = Lista.buscar (nome, produto);
                    if (pos != -1)
                        Lista.removerPosicao (pos);
                    else
                        cout << "item nao existente" << endl;
                break;
            case 'p':
                Lista.depurar ();
                break;
            case 'c':
                cin >> nome;
                if (Lista.buscar (nome, produto) != -1)
                    cout  << "(" << produto.nome << ", " << produto.qtd << ")" << endl;
                else
                    cout << "item nao existente" << endl;
                break;
            default:
                break;
        }
    }
    while (comando != 'q');
    Lista.depurar ();

    return 0;
}
