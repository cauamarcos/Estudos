#include <iostream>
using namespace std;

class Torneio {
    private:
        int *arranjo;
        int capacidade;
        int tamanhoInicial;
    public:
        Torneio (int *vetor, int tam);
        ~Torneio ();
        //em todas as funções, o parâmetro i representa a posição de um elemento no arranjo
        int esquerdo (int i) {return 2 * i + 1; }
        int direito (int i) {return 2 * i + 2; }
        void copiaMaior (int i);
        void copiaMenor (int i);
        void arruma ();
        int campeao () {return arranjo [0]; }
};

Torneio::Torneio (int *vetor, int tam) {
    int numPais = 1, cont = 0;
    while (numPais < tam)
        numPais *= 2;
    capacidade = numPais + tam - 1;
    arranjo = new int [capacidade];
    tamanhoInicial = tam;
    for (int i = capacidade - tam; i < capacidade; i++) {
        arranjo [i] = vetor [cont];
        cont++;
    }
}

Torneio::~Torneio () {
    delete [] arranjo;
}

void Torneio::arruma () {
    int cont = 0, nivel;
    if (tamanhoInicial % 2 == 0)
        nivel = tamanhoInicial / 2;
    else
        nivel = tamanhoInicial / 2 + 1;
    bool faseImpar = true;
    for (int i = capacidade - tamanhoInicial - 1; i >= 0; i--) {
        if (faseImpar and nivel > 0) {
            copiaMaior (i);
            if (arranjo [i] != -1)
                cont++;
            if (cont == nivel) {
                cont = 0;
                faseImpar = false;
                if (nivel % 2 != 0 and nivel != 1)
                    nivel++;
                nivel /= 2;
            }
        }
        else if (not faseImpar and nivel > 0) {
            copiaMenor (i);
            if (arranjo [i] != -1)
                cont++;
            if (cont == nivel) {
                cont = 0;
                faseImpar = true;
                if (nivel % 2 != 0 and nivel != 1)
                    nivel++;
                nivel /= 2;
            }
        }
    }
}

void Torneio::copiaMaior (int i) {
    int filhoEsquerdo = esquerdo (i);
    int filhoDireito = direito (i);
    int maior;
    if (filhoEsquerdo < capacidade and arranjo [filhoEsquerdo] != -1) {
        if (filhoDireito < capacidade and arranjo [filhoDireito] > arranjo [filhoEsquerdo])
            maior = filhoDireito;
        else
            maior = filhoEsquerdo;
        arranjo [i] = arranjo [maior];
    }
    else
        arranjo [i] = -1;
}

void Torneio::copiaMenor (int i) {
    int filhoEsquerdo = esquerdo (i);
    int filhoDireito = direito (i);
    int menor;
    if (filhoEsquerdo < capacidade and arranjo [filhoEsquerdo] != -1) {
        if (filhoDireito < capacidade and arranjo [filhoDireito] < arranjo [filhoEsquerdo] and arranjo [filhoDireito] != -1)
            menor = filhoDireito;
        else
            menor = filhoEsquerdo;
        arranjo [i] = arranjo [menor];
    }
    else
        arranjo [i] = -1;
}

int main() {
    int qtdParticipantes;
    cin >> qtdParticipantes;
    int *vetor = new int [qtdParticipantes];
    for (int i = 0; i < qtdParticipantes; i++)
        cin >> vetor [i];
    Torneio torneio (vetor, qtdParticipantes);
    torneio.arruma ();
    cout << torneio.campeao ();

    return 0;
}
