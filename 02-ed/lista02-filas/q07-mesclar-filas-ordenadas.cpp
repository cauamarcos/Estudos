#include <iostream>
using namespace std;

class Noh {
    friend class Fila;
    private:
        int mDado;
        Noh* mPtProx;
    public:
        Noh (int d);
};

Noh::Noh (int d) {
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
        int Remover();
        // Insere um item no final da fila.
        void Inserir(const int& d);
        // Consulta a quantidade de itens na fila.
        unsigned Tamanho() const { return mTamanho; }
        // Consulta se a fila está vaiza.
        bool Vazia() const;
        void limparTudo ();
        void depurar ();
        void mesclar ();
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

void Fila::Inserir(const int& d) {
    Noh* novo = new Noh (d);
    if (Vazia ())
        mPrimeiro = novo;
    else
        mUltimo->mPtProx = novo;
    mUltimo = novo;
    mTamanho++;
}

int Fila::Remover() {
    int valor = mPrimeiro->mDado;
    Noh* temp = mPrimeiro;
    mPrimeiro = mPrimeiro->mPtProx;
    delete temp;
    mTamanho--;
    if (mTamanho == 0)
        mUltimo = NULL;
    return valor;
}

bool Fila::Vazia() const {
    return (mTamanho == 0);
}

void Fila::depurar () {
    int tam = Tamanho (), valor;
    for (int i = 0; i < tam; i++) {
        valor = Remover ();
        cout << valor << " ";
        Inserir (valor);
    }
    cout << endl;
}

int main() {
    Fila filaA, filaB;
    int num;
    char comando = 'a', escolha;
    while (comando != 't') {
        cin >> comando;
        if (comando == 'i') {
            cin >> escolha >> num;
            if (escolha == 'a') 
                filaA.Inserir (num);
            else if (escolha == 'b')
                filaB.Inserir (num);
        }
        else if (comando == 'e') {
            cin >> escolha;
            if (escolha == 'a') {
                if (not filaA.Vazia ())
                    filaA.depurar ();
            }
            else if (escolha == 'b') {
                if (not filaB.Vazia ())
                    filaB.depurar ();
            }
        }
        else if (comando == 'm') {
            Fila temporaria, tempA, tempB;
            int tamA = filaA.Tamanho (), tamB = filaB.Tamanho (), valor;
            for (int i = 0; i < tamA; i++) {
                valor = filaA.Remover ();
                tempA.Inserir (valor);
                filaA.Inserir (valor);
            }
            for (int i = 0; i < tamB; i++) {
                valor = filaB.Remover ();
                tempB.Inserir (valor);
                filaB.Inserir (valor);
            }
            int numA, numB;
            bool okA = true, okB = true;
            while ((not tempA.Vazia () or not tempB.Vazia ()) or not okA or not okB) {
                if (okA) {
                    if (not tempA.Vazia ()) {
                        numA = tempA.Remover ();
                        okA = false;
                    }
                }
                if (okB) {
                    if (not tempB.Vazia ()) {
                        numB = tempB.Remover ();
                        okB = false;
                    }
                }
                if (numA < numB and not okA) {
                    temporaria.Inserir (numA);
                    okA = true;
                }
                else if (numB < numA and not okB) {
                    temporaria.Inserir (numB);
                    okB = true;
                }
                else if (numA == numB) {
                    if (not okA) {
                        temporaria.Inserir (numA);
                        okA = true;
                    }
                    if (not okB) {
                        temporaria.Inserir (numB);
                        okB = true;
                    }
                }
                else if (not okA and tempB.Vazia () and okB) {
                    temporaria.Inserir (numA);
                    okA = true;
                }
                else if (not okB and tempA.Vazia () and okA) {
                    temporaria.Inserir (numB);
                    okB = true;
                }
            }
            int tam = temporaria.Tamanho ();
            for (int i = 0; i < tam; i++)
                cout << temporaria.Remover () << " ";
            cout << endl;
        }
        else if (comando == 't') {
            //fim do while
        }
    }    

    return 0;
}
