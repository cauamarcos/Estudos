#include <iostream>
using namespace std;

struct Aluno {
    int matricula;
    string nome;
    int periodo;
};

class Noh {
    friend class lista;
    private:
        Aluno mDado;
        Noh* mPtProx;
    public:
        Noh (Aluno aluno);
};

Noh::Noh (Aluno aluno) {
    mDado = aluno;
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
        void inserirEmListaVazia (Aluno aluno);
        void inserirNoFinal (Aluno aluno);
        void inserirNoInicio (Aluno aluno);
        Aluno retirarNoInicio ();
        Aluno retirarNoFim ();
        bool Vazia () {return mTamanho == 0; }
        int tamanho () {return mTamanho; }
        void depurar ();
};

lista::lista () {
    mInicio = NULL;
    mFim = NULL;
    mTamanho = 0;
}

lista::~lista () {
    while (mInicio != NULL) {
        Noh *aux = mInicio;
        mInicio = mInicio->mPtProx;
        delete aux;
        mTamanho--;
    }
    mFim = NULL;
}

void lista::inserirEmListaVazia (Aluno aluno) {
    Noh* novo = new Noh (aluno);
    mInicio = novo;
    mFim = novo;
    mTamanho = 1;
}

void lista::inserirNoFinal (Aluno aluno) {
    if (Vazia ())
        inserirEmListaVazia (aluno);
    else {
        Noh* novo = new Noh (aluno);
        mFim->mPtProx = novo;
        mFim = novo;
        mTamanho++;
    }
}

void lista::inserirNoInicio (Aluno aluno) {
    if (Vazia ())
        inserirEmListaVazia (aluno);
    else {
        Noh *novo = new Noh (aluno);
        novo->mPtProx = mInicio;
        mInicio = novo;
    }
}

Aluno lista::retirarNoFim () {
    Aluno valor;
    Noh* aux = mInicio;
    Noh* anterior = NULL;
    while (aux->mPtProx != NULL) {
        anterior = aux;
        aux = aux->mPtProx;
    }
    valor = aux->mDado;
    if (anterior == NULL)
        mInicio = NULL;
    else
        anterior->mPtProx = NULL;
    delete mFim;
    mFim = anterior;
    mTamanho--;
    return valor;
}

Aluno lista::retirarNoInicio () {
    Noh *aux = mInicio;
    Aluno valor = aux->mDado;
    mInicio = aux->mPtProx;
    delete aux;
    mTamanho--;
    if (Vazia ()) {
        mInicio = NULL;
        mFim = NULL;
    }
    return valor;
}

void lista::depurar () {
    cout << "[";
    if (mTamanho > 0) {
        Noh *aux = mInicio;
        while (aux->mPtProx != NULL) {
            cout << aux->mDado.matricula << " - " << aux->mDado.nome << ", ";
            aux = aux->mPtProx;
        }
        cout << aux->mDado.matricula << " - " << aux->mDado.nome;
    }
    cout << "]" << endl;
}

int main () {
    int num;
    lista Lista;
    Aluno aluno;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> aluno.matricula >> aluno.nome >> aluno.periodo;
        Lista.inserirNoFinal (aluno);
    }
    Aluno vetor [num];
    cout << "[";
    for (int i = 0; i < num; i++) {
        aluno = Lista.retirarNoInicio ();
        cout << aluno.matricula << " - " << aluno.nome;
        vetor [i] = aluno;
        if (i != num - 1)
            cout << ", ";
    }
    cout << "]" << endl;
    for (int i = num - 1; i >= 0; i--)
        Lista.inserirNoFinal (vetor [i]);
    Lista.depurar ();

    return 0;
}
