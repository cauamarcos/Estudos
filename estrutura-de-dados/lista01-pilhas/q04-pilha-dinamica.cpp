#include <iostream>
using namespace std;

typedef int Dado;

class Noh {
    friend class Pilha;
    private:
        Dado mDado; // poderia ser outro tipo de variável
        Noh* mPtProx;
    public:
        Noh (Dado d);
};

Noh::Noh (Dado d) {
    mDado = d;
    mPtProx = NULL;
}

class Pilha {
    public:
        // Constrói pilha vazia.
        Pilha();
        // Destrutor que desaloca memória.
        ~Pilha();
        // Retira e retorna o valor que estiver no mPtTopo da pilha.
        // Escreve uma mensagem de erro se não for possível desempilhar.
        Dado Desempilhar(); // retorna o mPtTopo da Pilha
        // Insere um valor na pilha.
        void Empilhar(const Dado& d);
        // Apagar todos os dados da pilha.
        void LimparTudo();
        // Informa quantos valores existem na pilha.
        unsigned Tamanho() { return mTamanho; }
        // Retorna o valor que está no mPtTopo sem desempilhar.
        Dado Topo() const;
        // Informa se a pilha está Vazia.
        bool Vazia() const;
    private:
        Noh* mPtTopo;
        unsigned mTamanho;
};

Pilha::Pilha() {
    mPtTopo = NULL;
    mTamanho = 0;
}

Pilha::~Pilha() {
    while (mTamanho > 0)
        Desempilhar ();
}

Dado Pilha::Desempilhar() {
    Dado valor = mPtTopo->mDado;
    Noh* temp = mPtTopo;
    mPtTopo = mPtTopo->mPtProx;
    delete temp;
    mTamanho--;
    return valor;
}

void Pilha::Empilhar(const Dado& d) {
    Noh* novo = new Noh (d);
    novo->mPtProx = mPtTopo;
    mPtTopo = novo;
    mTamanho++;
}

void Pilha::LimparTudo() {
    while (mTamanho > 0)
        Desempilhar ();
}

Dado Pilha::Topo() const {
    return mPtTopo->mDado;
}

bool Pilha::Vazia() const {
    return (mTamanho == 0);
}

int main() {
    Pilha pilha;
    Dado valor;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir
                cin >> valor;
                pilha.Empilhar(valor);
                break;
            case 'r': // remover
                if (pilha.Tamanho () > 0)
                    cout << pilha.Desempilhar() << endl;
                else
                    cout << "erro" << endl;
                break;
            case 'l': // limpar tudo
                pilha.LimparTudo();
                break;
            case 't': // consultar tamanho
                cout << pilha.Tamanho() << endl;
                break;
            case 'e': // espiar
                cout << pilha.Topo() << endl;
                break;
            case 'f': // finalizar
                // checado no do-while
                break;
            default:
                cerr << "comando inválido\n";
        }
    } while (comando != 'f'); // finalizar execução
    while (not pilha.Vazia()) {
        cout << pilha.Desempilhar() << ' ';
    }
    cout << endl;
    return 0;
}