#include <iostream>   
using namespace std;

struct Aluno {
    string nome;
    int somaNotas = 0;
    int tentativas = 0;
    unsigned matricula;
};

class Heap {
    // classe Heap (max-heap, o maior fica na raiz/inicio)
    public:
        // Criar heap sem dados e com capacidade informada
        Heap(int cap);
        // Destruttor
        ~Heap();
        // Inserir um dado na heap
        void Inserir(const Aluno& d);
        // Consulta a raiz
        Aluno Raiz();
        // Retira e retorna a raiz
        Aluno Retirar();
        // Verifica se a heap está vazia
        bool Vazia();
    protected:
        void ArrumarDescendo(int i);
        void ArrumarSubindo(int i);
        int Direito(int i);
        int Esquerdo(int i);
        int Pai(int i);
        int mCapacidade;
        int mTamanho;
        Aluno* mVetDados;
};

Heap::Heap(int cap) {
    mCapacidade = cap;
    mVetDados = new Aluno [cap];
    mTamanho = 0;
}

Heap::~Heap() {
    delete [] mVetDados;
}

void Heap::ArrumarDescendo(int i) {
    int filhoEsquerdo = Esquerdo (i);
    int filhoDireito = Direito (i);
    int maior = i;
    if (filhoEsquerdo <= (mTamanho - 1)) {
        if (mVetDados [filhoEsquerdo].somaNotas > mVetDados [maior].somaNotas)
            maior = filhoEsquerdo;
        else if (mVetDados [filhoEsquerdo].somaNotas == mVetDados [maior].somaNotas) {
            if (mVetDados[filhoEsquerdo].tentativas < mVetDados [maior].tentativas)
                maior = filhoEsquerdo;
            else if (mVetDados[filhoEsquerdo].tentativas == mVetDados [maior].tentativas) {
                string nomeEsquerdo = mVetDados [filhoEsquerdo].nome;
                string nomeMaior = mVetDados [maior].nome;
                bool ok = false;
                int letra = 0;
                while (not ok) {
                    if (nomeEsquerdo[letra] < nomeMaior[letra]) {
                        maior = filhoEsquerdo;
                        ok = true;
                    }
                    else if (nomeMaior[letra] < nomeEsquerdo[letra])
                        ok = true;
                    else
                        letra++;
                }
            }
        }
    }
    if (filhoDireito <= (mTamanho - 1)) {
        if (mVetDados [filhoDireito].somaNotas > mVetDados [maior].somaNotas)
            maior = filhoDireito;
        else if (mVetDados [filhoDireito].somaNotas == mVetDados [maior].somaNotas) {
            if (mVetDados[filhoDireito].tentativas < mVetDados [maior].tentativas)
                maior = filhoDireito;
            else if (mVetDados[filhoDireito].tentativas == mVetDados [maior].tentativas) {
                string nomeDireito = mVetDados [filhoDireito].nome;
                string nomeMaior = mVetDados [maior].nome;
                bool ok = false;
                int letra = 0;
                while (not ok) {
                    if (nomeDireito[letra] < nomeMaior[letra]) {
                        maior = filhoDireito;
                        ok = true;
                    }
                    else if (nomeMaior[letra] < nomeDireito[letra])
                        ok = true;
                    else
                        letra++;
                }
            }
        }
    }
    if (maior != i) {
        Aluno aux = mVetDados [i];
        mVetDados [i] = mVetDados [maior];
        mVetDados [maior] = aux;
        ArrumarDescendo (maior);
    }
}

void Heap::ArrumarSubindo(int i) {
    int pai = Pai (i);
    bool trocar = false;
    if (mVetDados [i].somaNotas > mVetDados [pai].somaNotas)
        trocar = true;
    else if (mVetDados[i].somaNotas == mVetDados[pai].somaNotas) {
        if (mVetDados[i].tentativas < mVetDados[pai].tentativas)
            trocar = true;
        else if (mVetDados[i].tentativas == mVetDados[pai].tentativas) {
            string nomeFilho = mVetDados[i].nome;
            string nomePai = mVetDados [pai].nome;
            bool ok = false;
            int letra = 0;
            while (not ok) {
                if (nomeFilho[letra] < nomePai[letra]) {
                    trocar = true;
                    ok = true;
                }
                else if (nomePai[letra] < nomeFilho[letra])
                    ok = true;
                else
                    letra++;
            }
        }
    }
    if (trocar) {
        Aluno aux = mVetDados [i];
        mVetDados [i] = mVetDados [pai];
        mVetDados [pai] = aux;
        ArrumarSubindo (pai);
    }
}

int Heap::Pai(int i) {
    return (i - 1) / 2;
}

int Heap::Esquerdo(int i) {
    return 2 * i + 1;
}

int Heap::Direito(int i) {
    return 2 * i + 2;
}

Aluno Heap::Retirar() {
    Aluno valor = mVetDados [0];
    mVetDados [0] = mVetDados [mTamanho - 1];
    mVetDados [mTamanho - 1] = valor;
    mTamanho--;
    ArrumarDescendo (0);
    return valor;
}

bool Heap::Vazia() {
    return (mTamanho == 0);
}

void Heap::Inserir(const Aluno& d){
    mVetDados [mTamanho] = d;
    if (mTamanho > 0)
        ArrumarSubindo (mTamanho);
    mTamanho++;
}

int main() {
    unsigned qtdeAlunos, qtdeAtividades;
    cin >> qtdeAlunos >> qtdeAtividades;
    Heap heap (qtdeAlunos);
    int tentativas, nota;
    for (unsigned i = 0; i < qtdeAlunos; i++) {
        Aluno aluno;
        cin >> aluno.matricula >> aluno.nome;
        for (unsigned j = 0; j < qtdeAtividades; j++) {
            cin >> nota >> tentativas;
            aluno.somaNotas += nota;
            aluno.tentativas += tentativas;
        }
        heap.Inserir (aluno);
    }
    Aluno alunoDestaque (heap.Retirar ());
    cout << "[" << alunoDestaque.matricula << "] " << alunoDestaque.nome << endl;

    return 0;
}
