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
    Fila preferencial, padrao;
    string comando = "a", nome;
    int cont = 0;
    bool fim = false;
    while (not fim) {
        cin >> comando;
        if (comando == "normal") {
            cin >> nome;
            padrao.Inserir (nome);
        }
        else if (comando == "prioridade") {
            cin >> nome;
            preferencial.Inserir (nome);
        }
        else if (comando == "atender") {
            if ((preferencial.Tamanho () > 0 and cont < 3) or (cont >= 3 and padrao.Vazia () and preferencial.Tamanho () > 0)) {
                cout << preferencial.Remover () << endl;
                cont++;
            }
            else if (padrao.Tamanho () > 0) {
                cout << padrao.Remover () << endl;
                cont = 0;
            }
            else
                cout << "AGUARDE" << endl;
        }
        else if (comando == "fim")
            fim = true;
    }

    return 0;
}
