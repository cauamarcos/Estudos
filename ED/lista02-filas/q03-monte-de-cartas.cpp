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

int main() {
    int cap1, cap2, valor;
    cin >> cap1;
    fila fila1 (cap1);
    for (int i = 0; i < cap1; i++) {
        cin >> valor;
        fila1.enfileirar (valor);
    }
    cin >> cap2;
    fila fila2 (cap2);
    for (int i = 0; i < cap2; i++) {
        cin >> valor;
        fila2.enfileirar (valor);
    }
    fila fila3 (cap1 + cap2);
    int ultimo, num1, num2;
    bool ok1 = false, ok2 = false, primeiraVez = true, fim1 = false, fim2 = false;
    while ((fila1.tamanho () > 0 or fila2.tamanho () > 0) or not ok1 or not ok2) {
        if (primeiraVez) {
            num1 = fila1.desenfileirar ();
            num2 = fila2.desenfileirar ();
            primeiraVez = false;
        }
        else {
            if (ok1) {
                while ((num1 == ultimo or num1 == num2) and not fim1) {
                    if (fila1.tamanho () > 0) {
                        num1 = fila1.desenfileirar ();
                        if ((num1 != ultimo and num1 != num2))
                            ok1 = false;
                    }
                    else
                        fim1 = true;
                }
            }
            if (ok2) {
                while ((num2 == ultimo or num2 == num1) and not fim2) {
                    if (fila2.tamanho () > 0) {
                        num2 = fila2.desenfileirar ();
                        if ((num2 != ultimo and num1 != num2))
                            ok2 = false;
                    }
                    else
                        fim2 = true;
                }
            }
        }
        if (num1 < num2 and not fim1) {
            fila3.enfileirar (num1);
            ultimo = num1;
            ok1 = true;
        }
        else if (num2 < num1 and not fim2) {
            fila3.enfileirar (num2);
            ultimo = num2;
            ok2 = true;
        }
        else if (num1 == num2 and not fim1) {
            fila3.enfileirar (num1);
            ultimo = num1;
            ok1 = true;
            ok2 = true;
        }
        else if (not ok1 and fim2 and ok2) {
            fila3.enfileirar (num1);
            ultimo = num1;
            ok1 = true;
        }
        else if (not ok2 and fim1 and ok1) {
            fila3.enfileirar (num2);
            ultimo = num2;
            ok2 = true;
        }
    }
    int tam = fila3.tamanho ();
    for (int i = 0; i < tam; i++) {
        cout << fila3.desenfileirar () << " ";
    }
    
    return 0;
}
