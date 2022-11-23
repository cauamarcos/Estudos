#include <iostream>
using namespace std;

typedef int Dado;

class Noh {
    friend class Fila;
    private:
        Dado mDado;
        Noh* mPtProx;
    public:
        Noh (Dado d);
};

Noh::Noh (Dado d) {
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
        Dado Remover();
        // Insere um item no final da fila.
        void Inserir(const Dado& d);
        // Retorna o primeiro item da fila sem remover.
        Dado Proximo() const;
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

void Fila::Inserir(const Dado& d) {
    Noh* novo = new Noh (d);
    if (Vazia ())
        mPrimeiro = novo;
    else
        mUltimo->mPtProx = novo;
    mUltimo = novo;
    mTamanho++;
}

Dado Fila::Remover() {
    Dado valor = mPrimeiro->mDado;
    Noh* temp = mPrimeiro;
    mPrimeiro = mPrimeiro->mPtProx;
    delete temp;
    mTamanho--;
    return valor;
}

Dado Fila::Proximo() const {
    return mPrimeiro->mDado;
}

void Fila::LimparTudo() {
    while (mTamanho > 0)
        Remover ();
}

bool Fila::Vazia() const {
    return (mTamanho == 0);
}

int main() {
    Fila fila;
    Dado valor;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir
                cin >> valor;
                fila.Inserir(valor);
                break;
            case 'r': // remover
                if (fila.Tamanho () > 0)
                    cout << fila.Remover() << endl;
                else
                    cout << "erro" << endl;
                break;
            case 'l': // limpar tudo
                fila.LimparTudo();
                break;
            case 't': // escrever tamanho
                cout << fila.Tamanho() << endl;
                break;
            case 'e': // espiar proximo
                if (fila.Tamanho () > 0)
                    cout << fila.Proximo() << endl;
                else
                    cout << "erro" << endl;
                break;
            case 'f': // finalizar
                // vai verificar adiante
                break;
            default:
                cerr << "comando inválido\n";
        }
    } while (comando != 'f'); // finalizar execução
    while (not fila.Vazia()) {
        cout << fila.Remover() << ' ';
    }
    cout << endl;
    return 0;
}
