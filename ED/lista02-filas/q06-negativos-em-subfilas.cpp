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
        // Consulta a quantidade de itens na fila.
        unsigned Tamanho() const { return mTamanho; }
        // Consulta se a fila está vaiza.
        bool Vazia() const;
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

bool Fila::Vazia() const {
    return (mTamanho == 0);
}

int main() {
    Fila mFila, aux, aux2;
    int n, k , num, negativo;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        mFila.Inserir (num);
    }
    cin >> k;
    for (int i = 0; i < k - 1; i++)
        aux.Inserir (mFila.Remover ());
    for (int i = 0; i < (n - k + 1); i++) {
        aux.Inserir (mFila.Remover ());
        negativo = 0;
        for (int j = 0; j < k; j++) {
            num = aux.Remover ();
            if (negativo == 0 and num < 0)
                negativo = num;
            if (j != 0)
                aux2.Inserir (num);
        }
        for (int j = 0; j < k - 1; j++)
            aux.Inserir (aux2.Remover ());
        if (negativo == 0)
            cout << "inexistente ";
        else
            cout << negativo << " ";
    }

    return 0;
}
