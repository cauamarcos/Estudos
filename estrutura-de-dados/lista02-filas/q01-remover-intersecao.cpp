#include <iostream>
using namespace std;

class Noh {
    friend class Fila;
    private:
        int mDado;
        Noh* mPtProx;
    public:
        Noh (int d);
};

Noh::Noh (int d) {
    mDado = d;
    mPtProx = NULL;
}

class Fila {
    public:
        // Constroi uma fila vazia.
        Fila();
        // Desaloca memória de todos os nós da fila.
        ~Fila();
        // Remove e retorna o primeiro item da fila.
        int Remover();
        // Insere um item no final da fila.
        void Inserir(const int& d);
        // Retorna o primeiro item da fila sem remover.
        int Proximo() const;
        // Remove todos os itens da fila.
        void LimparTudo();
        // Consulta a quantidade de itens na fila.
        unsigned Tamanho() const { return mTamanho; }
        // Consulta se a fila está vaiza.
        bool Vazia() const;
        void checar (int valor);
    private:
        Noh* mPrimeiro;
        Noh* mUltimo;
        unsigned mTamanho;
};

Fila::Fila() {
    mPrimeiro = NULL;
    mUltimo = NULL;
    mTamanho = 0;
}

Fila::~Fila() {
    while (mTamanho > 0)
        Remover ();
}

void Fila::Inserir(const int& d) {
    Noh* novo = new Noh (d);
    if (Vazia ())
        mPrimeiro = novo;
    else
        mUltimo->mPtProx = novo;
    mUltimo = novo;
    mTamanho++;
}

int Fila::Remover() {
    int valor = mPrimeiro->mDado;
    Noh* temp = mPrimeiro;
    mPrimeiro = mPrimeiro->mPtProx;
    delete temp;
    mTamanho--;
    return valor;
}

int Fila::Proximo() const {
    return mPrimeiro->mDado;
}

void Fila::LimparTudo() {
    while (mTamanho > 0)
        Remover ();
}

bool Fila::Vazia() const {
    return (mTamanho == 0);
}

void Fila::checar (int valor) {
    Fila aux;
    while (mTamanho > 0) {
        int x = Remover ();
        if (x != valor)
            aux.Inserir (x);
    }
    int tam = aux.Tamanho ();
    for (int i = 0; i < tam; i++)
        Inserir (aux.Remover ());
}

int main() {
    Fila f1, f2;
    int tam1, tam2, valor;
    cin >> tam1;
    for (int i = 0; i < tam1; i++) {
        cin >> valor;
        f1.Inserir (valor);
    }
    cin >> tam2;
    for (int i = 0; i < tam2; i++) {
        cin >> valor;
        f2.Inserir (valor);
    }
    for (int i = 0; i < tam2; i++)
        f1.checar (f2.Remover ());
    int tam = f1.Tamanho ();
    for (int i = 0; i < tam; i++) {
        cout << f1.Remover () << " ";
    }

    return 0;
}
