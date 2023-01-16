#include <iostream>
using namespace std;

class TabelaHash {
    private:
        int tamanho;
        int capacidade;
        int* tabela;
    public:
        TabelaHash ();
        ~TabelaHash ();
        int buscaChave (int chave);
        void inserir (int chave);
        void remover (int chave);
        int pertinencia (int chave);
        void depurar ();
        int Tamanho () {return tamanho; }
};

TabelaHash::TabelaHash () {
    capacidade = 101;
    tamanho = 0;
    tabela = new int [101];
    for (int i = 0; i < 101; i++)
        tabela [i] = -1;
}

TabelaHash::~TabelaHash () {
    delete [] tabela;
}

int TabelaHash::buscaChave (int chave) {
    int pos = chave % 101;
    int posFinal = pos;
    do {
        int dado = tabela [pos];
        if (dado == -1)
            return -1;
        if (dado == chave)
            return pos;
        pos = (pos + 1) % capacidade;
    }
    while (pos != posFinal);
    return -1;
}

void TabelaHash::inserir (int chave) {
    if (buscaChave (chave) == -1 and tamanho < capacidade) {
        int pos = chave % 101;
        while (tabela [pos] != -1 and tabela [pos] != -2)
            pos = (pos + 1) % capacidade;
        tabela [pos] = chave;
        tamanho++;
    }
}

void TabelaHash::remover (int chave) {
    int pos = buscaChave (chave);
    if (tamanho > 0 and pos != -1) {
        tabela [pos] = -2;
        tamanho--;
    }
}

int TabelaHash::pertinencia (int chave) {
    int pos = chave % 101;
    int posFinal = pos;
    do {
        int dado = tabela [pos];
        if (dado == -1)
            return -1;
        if (dado == chave)
            return 1;
        pos = (pos + 1) % capacidade;
    }
    while (pos != posFinal);
    return -1;
}

void TabelaHash::depurar () {
    if (tamanho > 0) {
        for (int i = 0; i < 101; i++) {
            if (tabela [i] != -1 and tabela [i] != -2)
                cout << tabela [i] << " ";
        }
    }
    else
        cout << "{}";
    cout << endl;
}

int main () {
    TabelaHash Tabela;
    int num;
    for (int i = 0; i < 10; i++) {
        cin >> num;
        Tabela.inserir (num);
    }
    for (int i = 0; i < 3; i++) {
        cin >> num;
        Tabela.remover (num);
    }
    for (int i = 0; i < 2; i++) {
        cin >> num;
        cout << Tabela.pertinencia (num) << endl;
    }
    Tabela.depurar ();
    for (int i = 0; i < 3; i++) {
        cin >> num;
        Tabela.inserir (num);
    }
    Tabela.depurar ();

    return 0;
}
