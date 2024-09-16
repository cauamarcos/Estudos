#include <iostream>
using namespace std;

class fila {
    private:
        int mTamanho;
        int posInicio;
        int posFim;
        int *arranjo;
        int capacidade;
    public:
        fila (int cap);
        void enfileirar (int valor);
        int desenfileirar ();
        void info ();
        int tamanho () {return mTamanho; }
};

fila::fila (int cap) {
    arranjo = new int[cap];
    mTamanho = 0;
    posInicio = 0;
    posFim = 0;
    capacidade = cap;
}

void fila::enfileirar (int valor) {
    if (mTamanho == 0) {
        posFim = 0;
        arranjo[posFim] = valor;
        mTamanho++;
    }
    else {
        posFim++;
        if (posFim == capacidade)
            posFim = 0;
        arranjo[posFim] = valor;
        mTamanho++;
    }
}

int fila::desenfileirar () {
    int primeiro = posInicio;
    posInicio++;
    if (posInicio == capacidade)
        posInicio = 0;
    mTamanho--;
    return arranjo[primeiro];
}

void fila::info () {
    cout << "tamanho=" << mTamanho << " capacidade=" << capacidade << " inicio=" << posInicio << " fim=" << posFim << endl;
    int tam = mTamanho, pos = posInicio;
    for (int i = 0; i < tam; i++) {
        if ((pos) == capacidade) 
            pos = 0;
        cout << arranjo[pos] << " ";
        pos++;
    }
    cout << endl;
}

int main() {
    int capacidade, valor;
    cin >> capacidade;
    fila mFila (capacidade);
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'e': // enfileirar
                cin >> valor;
                mFila.enfileirar (valor);
                break;
            case 'd': // desenfileirar
                if (mFila.tamanho () > 0)
                    cout << mFila.desenfileirar () << endl;
                else
                    cout << "erro" << endl;
                break;
            case 'i': // informações da fila
                mFila.info ();
                break;
            case 't': //fim no do-while
                break;
            default:
                cerr << "comando inválido\n";
        }
    } while (comando != 't'); // terminar execução
    
    return 0;
}
