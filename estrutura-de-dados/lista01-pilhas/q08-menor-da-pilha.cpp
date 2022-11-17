#include <iostream>
using namespace std;

class noh {
    friend class pilha;
    private:
        int mValor; // poderia ser outro tipo de variável
        noh* mPtProx;
    public:
        noh (int d);
};

noh::noh (int d) {
    mValor = d;
    mPtProx = NULL;
}

class pilha {
    public:
        // Constrói pilha vazia.
        pilha ();
        // Destrutor que desaloca memória.
        ~pilha ();
        // Retira e retorna o valor que estiver no mPtTopo da pilha.
        // Escreve uma mensagem de erro se não for possível desempilhar.
        int desempilhar (); // retorna o mPtTopo da Pilha
        // Insere um valor na pilha.
        void empilhar (const int& d);
        // Apagar todos os dados da pilha.
        int menor ();
        // Informa quantos valores existem na pilha.
        unsigned tamanho () { return mTamanho; }
        // Retorna o valor que está no mPtTopo sem desempilhar.
        int topo () const;
        // Informa se a pilha está Vazia.
        bool vazia () const;
    private:
        noh* mPtTopo;
        unsigned mTamanho;
};

pilha::pilha() {
    mPtTopo = NULL;
    mTamanho = 0;
}

pilha::~pilha() {
    while (mTamanho > 0)
        desempilhar ();
}

int pilha::desempilhar() {
    int valor = mPtTopo->mValor;
    noh* temp = mPtTopo;
    mPtTopo = mPtTopo->mPtProx;
    delete temp;
    mTamanho--;
    return valor;
}

void pilha::empilhar(const int& d) {
    noh* novo = new noh (d);
    novo->mPtProx = mPtTopo;
    mPtTopo = novo;
    mTamanho++;
}

int pilha::menor () {
    pilha aux;
    int menor = topo ();
    int tam = mTamanho;
    for (int i = 0; i < tam; i++) {
        int var = desempilhar ();
        if (var < menor)
            menor = var;
        aux.empilhar (var);
    }
    for (int i = 0; i < tam; i++) {
        empilhar (aux.desempilhar ());
    }
    return menor;
}

int pilha::topo() const {
    return mPtTopo->mValor;
}

bool pilha::vazia() const {
    return (mTamanho == 0);
}

int main() {
    pilha pilha;
    int valor;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'e': // inserir
                cin >> valor;
                pilha.empilhar (valor);
                break;
            case 'd': // remover
                if (pilha.tamanho () > 0)
                    cout << pilha.desempilhar () << endl;
                else
                    cout << "VAZIA" << endl;
                break;
            case 'm': // retornar o menor
                if (not pilha.vazia ())
                    cout << pilha.menor () << endl;
                else
                    cout << "VAZIA" << endl;
                break;
            case 's': // finalizar
                // checado no do-while
                break;
            default:
                cerr << "comando inválido\n";
        }
    } while (comando != 's'); // finalizar execução
    while (not pilha.vazia()) {
        cout << pilha.desempilhar() << ' ';
    }
    cout << endl;
    return 0;
}
