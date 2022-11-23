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
        // Consulta a quantidade de itens na fila.
        unsigned Tamanho() const { return mTamanho; }
        // Consulta se a fila está vaiza.
        bool Vazia() const;
        void condicao ();
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
    if (mTamanho == 0)
        mUltimo = NULL;
    return nome;
}

bool Fila::Vazia() const {
    return (mTamanho == 0);
}

void Fila::condicao () {
    string carro;
    int tam = Tamanho ();
    for (int i = 0; i < tam; i++) {
        carro = Remover ();
        cout << carro << endl;
        Inserir (carro);
    }
}

int main() {
    Fila estacionamento;
    string placa, checar;
    char comando = 'a';
    while (comando != 'S') {
        cin >> comando;
        if (comando == 'E') {
            cin >> placa;
            estacionamento.Inserir (placa);
        }
        else if (comando == 'D') {
            int cont = 0, tam = estacionamento.Tamanho ();
            bool achou = false;
            cin >> placa;
            if (tam > 0) {
                while (cont <= tam and not achou) {
                    checar = estacionamento.Remover ();
                    cont++;
                    if (checar != placa)
                        estacionamento.Inserir (checar);
                    else if (checar == placa) {
                        cout << cont << endl;
                        if (estacionamento.Tamanho () > 0)
                            estacionamento.condicao ();
                        achou = true;
                    }
                    if (cont == tam and not achou)
                        cout << "NAO ENCONTRADO" << endl;
                }
            }
            else
                cout << "NAO ENCONTRADO" << endl;
        }
        else if (comando == 'S') {
            //fim do while
        }
    }    

    return 0;
}
