#include <iostream>
using namespace std;

int funcaoHash (string chave, int cap) {
    unsigned pos = 1;
    for (unsigned i = 0; i < chave.size(); i++)
        pos = 13 * pos + chave [i];
    return pos % cap;
}

struct dado {
    string chave = "";
    int valor = -1;
};

class TabelaHash {
    private:
        int capacidade;
        int tamanho;
        dado* tabela;
    public:
        TabelaHash (int cap);
        ~TabelaHash ();
        int buscaChave (string chave);
        void inserir (dado valor);
        void remover (string chave);
        int consultar (string chave);
        void depurar ();
};

TabelaHash::TabelaHash (int cap) {
    capacidade = cap;
    tamanho = 0;
    tabela = new dado [cap];
}

TabelaHash::~TabelaHash () {
    delete [] tabela;
}

int TabelaHash::buscaChave (string chave) {
    int pos = funcaoHash (chave, capacidade);
    int posFinal = pos;
    do {
        dado Dado = tabela [pos];
        if (Dado.valor == -1)
            return -1;
        if (Dado.chave == chave)
            return pos;
        pos = (pos + 1) % capacidade;
    }
    while (pos != posFinal);
    return -1;
}

void TabelaHash::inserir (dado valor) {
    if (tamanho < capacidade) {
        if (buscaChave (valor.chave) == -1) {
            int pos = funcaoHash (valor.chave, capacidade);
            while (tabela [pos].valor != -1 and tabela [pos].valor != -2)
                pos = (pos + 1) % capacidade;
        tabela [pos] = valor;
        tamanho++;
        }
        else
            cout << "Inserção de chave que já existe" << endl;
    }
    else
        cout << "Tabela hash cheia" << endl;
}

void TabelaHash::remover (string chave) {
    int pos = buscaChave (chave);
    if (tamanho == 0)
        cout << "Impossível remover de hash vazia" << endl;
    else if (pos == -1)
        cout << "Chave não encontrada para remoção" << endl;
    else {
        tabela [pos].chave = "";
        tabela [pos].valor = -2;
        tamanho--;
    }
}

int TabelaHash::consultar (string chave) {
    int pos = funcaoHash (chave, capacidade);
    int posFinal = pos;
    do {
        dado Dado = tabela [pos];
        if (Dado.valor == -1)
            return -1;
        if (Dado.chave == chave)
            return Dado.valor;
        pos = (pos + 1) % capacidade;
    }
    while (pos != posFinal);
    return -1;
}

void TabelaHash::depurar () {
    for (int i = 0; i < capacidade; i++) {
        cout << "[" << i << ":";
        if (tabela [i].valor != -1) {
            if (tabela [i].valor == -2)
                cout << "REMOVIDO";
            else
                cout << tabela [i].chave << "/" << tabela [i].valor;
        }
        cout << "] ";
    }
    cout << endl;
}

int main () {
    int cap;
    char comando;
    cin >> cap >> comando;
    dado Dado;
    TabelaHash Tabela (cap);
    string key;
    while (comando != 'f') {
        if (comando == 'i') {
            cin >> Dado.chave >> Dado.valor;
            if (Dado.chave == "")
                cout << "Chave inválida" << endl;
            else
                Tabela.inserir (Dado);
        }
        else if (comando == 'r') {
            cin >> key;
            Tabela.remover (key);
        }
        else if (comando == 'c') {
            cin >> key;
            int valor = Tabela.consultar (key);
            if (valor == -1)
                cout << "Chave não encontrada para consulta" << endl;
            else
                cout << valor << endl;
        }
        else if (comando == 'd')
            Tabela.depurar ();
        cin >> comando;
    }

    return 0;
}
