#include <iostream>
using namespace std;

struct equipe {
    string nome;
    string lider;
    string linguagem;
    int qntdMembros;
    string *membros;
};

class Noh {
    friend class lista;
    private:
        equipe mDado;
        Noh* mPtProx;
    public:
        Noh (equipe time);
};

Noh::Noh (equipe time) {
    mDado = time;
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
        void inserirEmListaVazia (equipe time);
        void inserirNoFinal (equipe time);
        void retirarNoInicio ();
        void retirarNoFim ();
        void depurar ();
        int buscar (string nome, equipe &busca);
        void removerPosicao (int pos);
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

void lista::inserirEmListaVazia (equipe time) {
    Noh* novo = new Noh (time);
    mInicio = novo;
    mFim = novo;
    mTamanho++;
}

void lista::inserirNoFinal (equipe time) {
    if (Vazia ())
        inserirEmListaVazia (time);
    else {
        Noh* novo = new Noh (time);
        mFim->mPtProx = novo;
        mFim = novo;
        mTamanho++;
    }
}

int lista::buscar (string nome, equipe &busca) {
    Noh* aux = mInicio;
    if (aux->mDado.nome == nome) {
        busca = aux->mDado;
        return 0;
    }
    int tam = tamanho ();
    for (int i = 1; i < tam; i++) {
        aux = aux->mPtProx;
        if (aux->mDado.nome == nome) {
            busca = aux->mDado;
            return i;
        }
    }
    return -1;
}

void lista::removerPosicao (int pos) {
    if (pos == 0)
        retirarNoInicio ();
    else if (pos == tamanho () - 1)
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
    Noh* aux = mInicio;
    for (int j = 0; j < mTamanho; j++) {
        cout  << "(" << aux->mDado.nome << ", " << aux->mDado.lider << ", " << aux->mDado.linguagem << ", [";
        for (int i = 0; i < aux->mDado.qntdMembros * 2; i += 2) {
            cout << aux->mDado.membros [i] << "/" << aux->mDado.membros [i + 1];
            if (i + 1 < (aux->mDado.qntdMembros * 2) - 1)
                cout << ", ";
            else
                cout << "])" << endl;
        }
        if (j < mTamanho)
            aux = aux->mPtProx;
    }
}

int main () {
    lista Lista;
    equipe time;
    string nome;
    char comando;
    int qtd, pos;
    do {
        cin >> comando;
        switch (comando) {
            case 'i':
                cin >> time.nome >> time.lider >> time.linguagem >> time.qntdMembros;
                qtd = time.qntdMembros;
                time.membros = new string [qtd * 2];
                for (int i = 0; i < qtd * 2; i++)
                    cin >> time.membros [i];
                Lista.inserirNoFinal (time);
                break;
            case 'a':
                cin >> nome;
                if (Lista.Vazia ())
                    cout << "Nao encontrado" << endl;
                else {
                    pos = Lista.buscar (nome, time);
                    if (pos != -1)
                        Lista.removerPosicao (pos);
                    else
                        cout << "Nao encontrado" << endl;
                }
                break;
            case 'p':
                Lista.depurar ();
                break;
            case 'b':
                cin >> nome;
                if (Lista.Vazia ())
                    cout << "Nao encontrado" << endl;
                else {
                    if (Lista.buscar (nome, time) != - 1) {
                        cout  << "(" << time.nome << ", " << time.lider << ", " << time.linguagem << ", [";
                        for (int i = 0; i < time.qntdMembros * 2; i += 2) {
                            cout << time.membros [i] << "/" << time.membros [i + 1];
                            if (i + 1 < (time.qntdMembros * 2) - 1)
                                cout << ", ";
                            else
                                cout << "])" << endl;
                        }
                    }
                    else
                        cout << "Nao encontrado" << endl;
                }
                break;
            default:
                break;
        }
    }
    while (comando != 's');

    return 0;
}
