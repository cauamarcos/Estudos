#include <iostream>
using namespace std;

struct Processo {
    unsigned codigo;
    int prioridade;
};

class Heap {
    private:
        Processo *arranjo;
        int capacidade;
        int mTamanho;
    public:
        Heap (int cap);
        ~Heap ();
        int pai (int i) {return (i - 1) / 2; } //em todas as funções, o parâmetro i representa a posição de um elemento no arranjo
        int esquerdo (int i) {return (2 *i + 1); }
        int direito (int i) {return (2 *i + 2); }
        void corrigeDescendo (int i);
        void corrigeSubindo (int i);
        bool vazia () {return mTamanho == 0; }
        Processo retiraRaiz ();
        void inserir (Processo valor);
};

Heap::Heap (int cap) {
    capacidade = cap;
    arranjo = new Processo [capacidade];
    mTamanho = 0;
}

Heap::~Heap () {
    delete [] arranjo;
}

void Heap::corrigeDescendo (int i) {
    int filhoEsquerdo = esquerdo (i);
    int filhoDireito = direito (i);
    int maior = i;
    if (filhoEsquerdo <= (mTamanho - 1) and (arranjo [filhoEsquerdo].prioridade > arranjo [filhoDireito].prioridade)) 
        maior = filhoEsquerdo;
    if (filhoDireito <= (mTamanho - 1) and (arranjo [filhoDireito].prioridade > arranjo [filhoEsquerdo].prioridade)) 
        maior = filhoDireito;
    if (maior != i) {
        Processo aux = arranjo [i];
        arranjo [i] = arranjo [maior];
        arranjo [maior] = aux;
        corrigeDescendo (maior);
    }
}

Processo Heap::retiraRaiz () {
    Processo valor = arranjo [0];
    arranjo [0] = arranjo [mTamanho - 1];
    arranjo [mTamanho - 1] = valor;
    mTamanho--;
    corrigeDescendo (0);
    return valor;
}

void Heap::corrigeSubindo (int i) {
    int Pai = pai (i);
    if (arranjo [i].prioridade > arranjo [Pai].prioridade) {
        Processo aux = arranjo [i];
        arranjo [i] = arranjo [Pai];
        arranjo [Pai] = aux;
        corrigeSubindo (Pai);
    }
}

void Heap::inserir (Processo valor) {
    arranjo [mTamanho] = valor;
    if (mTamanho > 0)
        corrigeSubindo (mTamanho);
    mTamanho++;
}

int main() {
    int cap;
    cin >> cap;
    Heap heap(cap);
    Processo processo;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir um processo no heap
                cin >> processo.codigo >> processo.prioridade;
                heap.inserir(processo);
                break;
            case 'o': // obter um processo do heap
                if (not heap.vazia ()) {
                    processo = heap.retiraRaiz ();
                    cout << processo.codigo << " " << processo.prioridade << endl;
                }
                else
                    cout << "Nao encontrado" << endl;
                break;
            case 's': //sair
                break;
        }
    } 
    while (comando != 's');

    return 0;
}
