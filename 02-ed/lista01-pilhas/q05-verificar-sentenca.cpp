#include <iostream>
using namespace std;

class noh {
    friend class pilha;
    private:
        char mValor;
        noh* mPtProx;
    public:
        noh (char d);
};

noh::noh (char d) {
    mValor = d;
    mPtProx = NULL;
}

class pilha {
    public:
        // Constrói pilha vazia.
        pilha ();
        // Destrutor que desaloca memória.
        ~pilha ();
        // Retira o valor que estiver no mPtTopo da pilha.
        void desempilhar ();
        // Insere um valor na pilha.
        void empilhar (const char& d);
        // Informa quantos valores existem na pilha.
        int tamanho () { return mTamanho; }
        // Informa se a pilha está Vazia.
        bool vazia () const;
    private:
        noh* mPtTopo;
        int mTamanho;
};

pilha::pilha() {
    mPtTopo = NULL;
    mTamanho = 0;
}

pilha::~pilha() {
    while (mTamanho > 0)
        desempilhar ();
}

void pilha::desempilhar() {
    if (not vazia ()) {
        noh* temp = mPtTopo;
        mPtTopo = mPtTopo->mPtProx;
        delete temp;
        mTamanho--;
    }
}

void pilha::empilhar(const char& d) {
    noh* novo = new noh (d);
    novo->mPtProx = mPtTopo;
    mPtTopo = novo;
    mTamanho++;
}

bool pilha::vazia() const {
    return (mTamanho == 0);
}

int main() {
    pilha pilhaA, pilhaC;
    char letra = 0;
    int contA = 0, contC = 0;
    bool B = false, ok = true;
    while (letra != 'X' and ok) {
        cin >> letra;
        if (letra == 'A' and B == false) {
            pilhaA.empilhar (letra);
            contA++;
        }
        else if (letra == 'C' and B) {
            pilhaC.empilhar (letra);
            contC++;
            if (contC > contA * 2)
                ok = false;
        }
        else if ((letra == 'A' and B) or (letra == 'C' and B == false) or (letra != 'A' and letra != 'B' and letra != 'C' and letra != 'X') or (letra == 'B' and B))
            ok = false;
        else if (letra == 'B')
            B = true;
    }
    if (ok) {
        int tam = pilhaC.tamanho () / 2;
        for (int i = 0; i < tam; i++) {
            pilhaA.desempilhar ();
            pilhaC.desempilhar ();
            pilhaC.desempilhar ();
            if (pilhaA.vazia () or pilhaC.vazia ())
                i = tam;
        }
    }
    if (pilhaA.vazia () and pilhaC.vazia () and ok)
        cout << "sim " << pilhaA.tamanho () << " " << pilhaC.tamanho ();
    else {
        cout << "nao " << pilhaA.tamanho () << " " << pilhaC.tamanho ();
    }

    return 0;
}
