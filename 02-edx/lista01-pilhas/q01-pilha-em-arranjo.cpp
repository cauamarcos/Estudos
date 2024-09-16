#include <iostream>
using namespace std;

typedef int Dado; // para facilitar a troca de int para outro tipo
 
// pilha implementada em arranjo 
class pilhav {
    private:
        int capacidade;
        Dado *dados;
        int tamanho;
        int posTopo;
    public:
        pilhav(int cap);
        ~pilhav();
        void empilha(Dado valor);
        Dado desempilha();
        Dado espia(); // acessa elemento do topo, mas não retira
        void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
        void info();  // imprime informações da pilha (tamanho e  posição do topo)
};

pilhav::pilhav (int cap) {
    capacidade = cap;
    tamanho = 0;
    posTopo = 0;
    dados = new Dado[capacidade];
}

pilhav::~pilhav () {
    delete [] dados;
}

void pilhav::empilha (Dado valor) {
    dados[tamanho] = valor;
    tamanho++;
    posTopo = tamanho - 1;
}
Dado pilhav::desempilha () {
    tamanho--;
    posTopo--;
    return dados[posTopo + 1];
}

Dado pilhav::espia () {
    return dados[posTopo];
}

void pilhav::depura () {
    for (int i = 0; i < tamanho; i++) {
        cout << dados[i] << " ";
    }
    cout << endl;
}

void pilhav::info () {
    cout << tamanho << " " << posTopo << endl;
}

int main () {
    int capacidade = 20;
    Dado listaDeEspera[4];
    pilhav minhaPiha (capacidade);
    for (int i = 0; i < 5; i++) {
        Dado n;
        cin >> n;
        minhaPiha.empilha(n);
    }
    for (int i = 0; i < 4; i++) {
        cin >> listaDeEspera[i];
    }
    for (int i = 0; i < 3; i++) {
        cout << minhaPiha.desempilha() << " ";
    }
    cout << endl;
    for (int i = 0; i < 4; i++) {
        minhaPiha.empilha(listaDeEspera[i]);
    }
    for (int i = 0; i < 3; i++) {
        cout << minhaPiha.desempilha() << " ";
    }
    cout << endl << minhaPiha.espia() << endl;
    minhaPiha.depura();
    minhaPiha.info();

	return 0;
}
