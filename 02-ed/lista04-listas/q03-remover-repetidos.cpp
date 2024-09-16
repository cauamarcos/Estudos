#include <iostream>
using namespace std;

class elemento{
    friend class lista;
    private:
        int chave;
        elemento *proximo;
        elemento *anterior;
    public:
        elemento (int c){
            chave = c;
            proximo = NULL;
            anterior = NULL;
        }
};

class lista{
    private:
        elemento *inicio;
        elemento *fim;
        int tamanho;
    public:
        lista ();
        ~lista ();
        void insereVazia (int c);
        void insereInicio (int c);
        void insereFim (int c);
        void removeRepetidos ();//retorna a quantidade de elementos restantes na lista
        bool vazia () {return tamanho == 0; };
        int Tamanho () {return tamanho; }
        void imprimeLista ();
};
    
lista::lista () {
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}
        
lista::~lista () {
    while (inicio != NULL) {
        elemento* aux = inicio;
        inicio = aux->proximo;
        delete aux;
        tamanho--;
    }
    fim = NULL;
}

void lista::insereVazia (int c) {
    elemento *novo = new elemento (c);
    inicio = novo;
    fim = novo;
    tamanho++;
}
   
void lista::insereFim (int c) {
    if (vazia ())
        insereVazia (c);
    else {
        elemento* novo = new elemento (c);
        fim->proximo = novo;
        novo->anterior = fim;
        fim = novo;
        novo->proximo = NULL;
        tamanho++;
    }
}
        
void lista::removeRepetidos () {
    elemento *aux = inicio;
    bool primeiraVez = true;
    while (aux->proximo != NULL) {
        if (not primeiraVez)
            aux = aux->proximo;
        elemento *aux2 = aux;
        while (aux2->proximo != NULL) {
            primeiraVez = false;
            aux2 = aux2->proximo;
            if (aux2->chave == aux->chave) {
                if (fim == aux2) {
                    fim = aux2->anterior;
                    aux2->anterior->proximo = NULL;
                }
                else {
                    aux2->anterior->proximo = aux2->proximo;
                    aux2->proximo->anterior = aux2->anterior;
                }
                elemento *aux3 = aux2->anterior;
                delete aux2;
                aux2 = aux3;
                tamanho--;
            }
        }
    }
}
        
void lista::imprimeLista () {
    if (tamanho > 0){
        elemento *auxiliar = inicio;
        while (auxiliar->proximo != NULL) {
            cout << "(" << auxiliar->chave << ") ";
            auxiliar = auxiliar->proximo;
        }
        cout << "(" << auxiliar->chave << ")" << endl;
    }
    else
        cout << "VAZIA";
}       
    
int main () {
    lista listaD;
    int chave;
    cin >> chave;
    while (chave != -1) {
        listaD.insereFim (chave);        
        cin >> chave;
    }
    if (not listaD.vazia ())
        listaD.removeRepetidos ();
    cout << listaD.Tamanho () << endl;
    listaD.imprimeLista ();
    
    return 0;
}
