#include <iostream>
using namespace std;

class Noh {
    friend class Fila;
    private:
        string mDado;
        Noh* mPtProx;
    public:
        Noh (string d);
};

Noh::Noh (string d) {
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
        string Remover();
        // Insere um item no final da fila.
        void Inserir(const string& d);
        // Remove todos os itens da fila.
        void LimparTudo();
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

void Fila::Inserir(const string& d) {
    Noh* novo = new Noh (d);
    if (Vazia ())
        mPrimeiro = novo;
    else
        mUltimo->mPtProx = novo;
    mUltimo = novo;
    mTamanho++;
}

string Fila::Remover() {
    string nome = mPrimeiro->mDado;
    Noh* temp = mPrimeiro;
    mPrimeiro = mPrimeiro->mPtProx;
    delete temp;
    mTamanho--;
    return nome;
}

bool Fila::Vazia() const {
    return (mTamanho == 0);
}

int main() {
    Fila binarios;
    string base = "1";
    int num, cont = 1;
    cin >> num;
    binarios.Inserir (base);
    cout << binarios.Remover () << " ";
    for (int i = 0; i < num - 1; i++) {
        if (cont < num) {
            binarios.Inserir (base + "0");
            cont++;
        }
        if (cont < num) {
            binarios.Inserir (base + "1");
            cont++;
        }
        base = binarios.Remover ();
        cout << base << " ";
    }

    return 0;
}
