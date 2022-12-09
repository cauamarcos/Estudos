#include <iostream>
using namespace std;

class elemento {
    friend class lista;
    private:
        int chave;
        elemento *proximo;
        elemento *anterior;
    public:
        elemento (int c) {
            chave = c;
            proximo = NULL;
            anterior = NULL;
        }
};

class lista {
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
        void inserirOrdenado (int valor);
        int retirarInicio ();
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
        novo->proximo = NULL;
        fim = novo;
        tamanho++;
    }
}

void lista::insereInicio (int valor) {
    elemento *novo = new elemento (valor);
    novo->proximo = inicio;
    novo->anterior = NULL;
    inicio = novo;
    tamanho++;
}
        
void lista::inserirOrdenado (int valor) {
    if (vazia ())
        insereVazia (valor);
    else if (inicio->chave > valor)
        insereInicio (valor);
    else if (fim->chave < valor)
        insereFim (valor);
    else {
        elemento *novo = new elemento (valor);
        elemento *aux = inicio;
        bool inserido = false;
        while (aux->proximo != NULL and not inserido) {
            elemento *ant = aux;
            aux = aux->proximo;
            if (aux->chave == valor)
                inserido = true;
            else if (aux->chave > valor) {
                novo->anterior = aux->anterior;
                novo->proximo = aux;
                aux->anterior = novo;
                ant->proximo = novo;
                tamanho++;
                inserido = true;
            }
        }
    }
}

int lista::retirarInicio () {
    if (tamanho == 1) {
        int valor = inicio->chave;
        delete inicio;
        tamanho--;
        inicio = NULL;
        fim = NULL;
        return valor;
    }
    else {
        elemento *aux = inicio;
        int valor = inicio->chave;
        inicio->proximo->anterior = NULL;
        inicio = inicio->proximo;
        delete aux;
        tamanho--;
        return valor;
    }
}
        
void lista::imprimeLista () {
    if (tamanho > 0){
        elemento *auxiliar = inicio;
        while (auxiliar->proximo != NULL) {
            cout << auxiliar->chave << " ";
            auxiliar = auxiliar->proximo;
        }
        cout << auxiliar->chave << endl;
    }
}       
    
int main () {
    lista lista1, lista2, lista3;
    int chave;
    cin >> chave;
    while (chave != -1) {
        lista1.insereFim (chave);        
        cin >> chave;
    }
    cin >> chave;
    while (chave != -1) {
        lista2.insereFim (chave);        
        cin >> chave;
    }
    while (not lista1.vazia ()) {
        int chave = lista1.retirarInicio ();
        if (chave % 2 == 0 and chave != 0)
            lista3.inserirOrdenado (chave);
    }
    while (not lista2.vazia ()) {
        int chave = lista2.retirarInicio ();
        if (chave % 2 != 0)
            lista3.inserirOrdenado (chave);
    }
    lista3.imprimeLista ();
    
    return 0;
}
