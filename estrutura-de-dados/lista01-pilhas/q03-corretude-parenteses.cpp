#include <iostream>
using namespace std;
 
// pilha implementada em arranjo 
class pilhav {
    private:
        int capacidade;
        unsigned *dados;
        int mTamanho;
        int posTopo;
    public:
        pilhav();
        ~pilhav();
        void empilha(int dado);
        int desempilha();
        int tamanho ();
};

pilhav::pilhav () {
    capacidade = 254;
    mTamanho = 0;
    posTopo = 0;
    dados = new unsigned[254];
}

pilhav::~pilhav () {
    delete [] dados;
}

void pilhav::empilha (int dado) {
    dados[mTamanho] = dado;
    mTamanho++;
    posTopo = mTamanho - 1;
}

int pilhav::desempilha () {
    mTamanho--;
    posTopo--;
    return dados[posTopo + 1];
}

int pilhav::tamanho () { return mTamanho; }

int main () {
    pilhav mPiha;
    string frase;
    getline (cin, frase);
    bool fecha = false;
    for (unsigned i = 0; i < frase.size (); i++) {
        if (frase[i] == '(' and fecha == false)
            mPiha.empilha (i);
        else if (frase[i] == ')' and mPiha.tamanho () > 0 and fecha == false)
            mPiha.desempilha ();
        else if (frase[i] == ')' and mPiha.tamanho () <= 0) {
            mPiha.empilha (i);
            fecha = true;
        }
    }
    if (mPiha.tamanho () == 0)
        cout << "correto" << endl;
    else {
        cout << mPiha.desempilha () << " ";
    }

	return 0;
}
