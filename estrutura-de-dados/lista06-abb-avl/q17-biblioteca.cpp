#include <iostream>
#include <stdexcept>
using namespace std;

struct dado {
    unsigned chave;
    string nomeLivro;
    string localizacao;
    int quantidadeDisponivel;
};

ostream& operator<<(ostream& saida, const dado& e) {
    saida << "(" << e.chave << "," << e.nomeLivro << "," << e.localizacao << "," << e.quantidadeDisponivel << ")";
    return saida;
}

istream& operator>>(istream& entrada, dado& e) {
    entrada >> e.chave >> e.nomeLivro >> e.localizacao >> e.quantidadeDisponivel;
    return entrada;
}

typedef unsigned tipoChave;

class noh {
    friend class avl;
    private:
        dado elemento;
        noh* esq;
        noh* dir;
        unsigned altura;
    public:
        noh(const dado& umDado):
            elemento(umDado),  esq(NULL), dir(NULL), altura(1) { }
        ~noh() { }
        int informarAltura (noh* umNoh);
        void atualizaAltura ();
        int fatorBalanceamento ();
};

int noh::informarAltura (noh* umNoh) {
    if (umNoh == NULL)
        return 0;
    else
        return umNoh->altura;
}

void noh::atualizaAltura () {
    int altArvEsq = informarAltura (esq);
    int altArvDir = informarAltura(dir);
    int max;
    if (altArvDir > altArvEsq)
        max = altArvDir;
    else
        max = altArvEsq;
    altura = 1 + max;
}

int noh::fatorBalanceamento () {
    int altArvEsq = informarAltura (esq);
    int altArvDir = informarAltura(dir);
    int fatorBal = altArvEsq - altArvDir;
    return fatorBal;
}

class avl {
    friend ostream& operator<<(ostream& output, avl& arvore);
    private:
        noh* raiz;
        // percorrimento em ordem da árvore
        void percorreEmOrdemAux (noh* atual, int& contador, string local);
        // funções auxiliares para remoção
        noh* encontraMenor (noh* raizSub);
        noh* removeMenor (noh* raizSub);
        // funções auxiliares para inserção e remoção usando método recursivo
        // retorna o nó para ajustar o pai ou o raiz
        noh* insereAux (noh* umNoh, const dado& umDado);
        noh* removeAux (noh* umNoh, tipoChave chave);
        // métodos para manutenção do balanceamento
        noh* rotacaoEsquerda (noh* umNoh);
        noh* rotacaoDireita (noh* umNoh);
        noh* arrumaBalanceamento (noh* umNoh);
        // busca, método iterativo
        noh* buscaAux (tipoChave chave);
        // função auxiliar do destrutor, usa percorrimento pós-ordem
        void destruirRecursivamente (noh* umNoh);
        void imprimirDir (const std::string& prefixo, const noh* meuNoh);
        void imprimirEsq (const std::string& prefixo, const noh* meuNoh, bool temIrmao);
    public:
        avl () { raiz = NULL; }
        ~avl ();
        void imprimir ();
        // inserção e remoção são recursivos
        void insere (const dado& umDado);
        void remove (tipoChave chave);
        // inserção e remoção, métodos recursivos
        // busca retorna uma cópia do objeto armazenado
        dado busca (tipoChave chave);
        // efetua levantamento de quantos livros existem em um dado local
        int levantamento (string local);
};

// destrutor
avl::~avl() {
    destruirRecursivamente(raiz);
}

// destrutor é recursivo, fazendo percorrimento pós-ordem
void avl::destruirRecursivamente (noh* umNoh) {
    if (umNoh != NULL) { 
        destruirRecursivamente (umNoh->esq);
        destruirRecursivamente (umNoh->dir);
        delete umNoh;
    }
}

void avl::insere (const dado& umDado) {
    noh* busca = buscaAux (umDado.chave);
    if (busca == NULL)
        raiz = insereAux (raiz, umDado);
    else
        throw runtime_error ("Erro na inserção: chave já existente!");
}

// inserção recursiva, devolve nó para atribuição de pai ou raiz
noh* avl::insereAux (noh* umNoh, const dado& umDado) {
    if (umNoh == NULL) {
        noh* novo = new noh (umDado);
        return novo;
    }
    else {
        if (umDado.chave < umNoh->elemento.chave)
            umNoh->esq = insereAux (umNoh->esq, umDado);
        else
            umNoh->dir = insereAux (umNoh->dir, umDado);
    }
    return arrumaBalanceamento (umNoh);
}

// checa e arruma, se necessário, o balanceamento em umNoh,
// fazendo as rotações e ajustes necessários
noh* avl::arrumaBalanceamento(noh* umNoh) {
    if (umNoh == NULL)
        return umNoh;
    umNoh->atualizaAltura ();
    int fatorBal = umNoh->fatorBalanceamento ();
    if ((fatorBal >= -1) and (fatorBal <= 1)) {
        return umNoh;
    }
    else if (fatorBal > 1 and umNoh->esq->fatorBalanceamento () >= 0)
        return rotacaoDireita (umNoh);
    else if (fatorBal > 1 and umNoh->esq->fatorBalanceamento () < 0) {
        umNoh->esq = rotacaoEsquerda (umNoh->esq);
        return rotacaoDireita (umNoh);
    }
    else if (fatorBal < -1 and umNoh->dir->fatorBalanceamento () <= 0)
        return rotacaoEsquerda (umNoh);
    else if (fatorBal < -1 and umNoh->dir->fatorBalanceamento () > 0) {
        umNoh->dir = rotacaoDireita (umNoh->dir);
        return rotacaoEsquerda (umNoh);
    }
    return umNoh;
}

// rotação à esquerda na subárvore com raiz em umNoh
// retorna o novo pai da subárvore
noh* avl::rotacaoEsquerda(noh* umNoh) {
    if (umNoh != NULL) {
        noh* nohAux = umNoh->dir;
        umNoh->dir = nohAux->esq;
        nohAux->esq = umNoh;
        umNoh->atualizaAltura ();
        nohAux->atualizaAltura ();
        return nohAux;
    }
    else
        return umNoh;
}

// rotação à direita na subárvore com raiz em umNoh
// retorna o novo pai da subárvore
noh* avl::rotacaoDireita(noh* umNoh) {
    if (umNoh != NULL) {
        noh* nohAux = umNoh->esq;
        umNoh->esq = nohAux->dir;
        nohAux->dir = umNoh;
        umNoh->atualizaAltura ();
        nohAux->atualizaAltura ();
        return nohAux;
    }
    else
        return umNoh;
}

// método de busca auxiliar (retorna o nó), iterativo
noh* avl::buscaAux (tipoChave chave) {
    noh* atual = raiz;
    while (atual != NULL) {
        if (atual->elemento.chave == chave)
            return atual;
        else if (atual->elemento.chave > chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return atual;
}

// busca elemento com uma dada chave na árvore e retorna o registro completo
dado avl::busca (tipoChave chave) {
    noh* resultado = buscaAux(chave);
    if (resultado != NULL)
        return resultado->elemento;
    else
        throw runtime_error("Erro na busca: elemento não encontrado!");
}

// nó mínimo (sucessor) de subárvore com raiz em raizSub (folha mais à esquerda)
noh* avl::encontraMenor (noh* raizSub) {
    while (raizSub->esq != NULL)
        raizSub = raizSub->esq;
    return raizSub;
}

// procedimento auxiliar para remover o sucessor substituíndo-o pelo
// seu filho à direita
noh* avl::removeMenor (noh* raizSub) {
    if (raizSub->esq == NULL)
        return raizSub->dir;
    else {
        raizSub->esq = removeMenor (raizSub->esq);
        return arrumaBalanceamento (raizSub);
    }
}

// remoção recursiva
void avl::remove (tipoChave chave) {
    raiz = removeAux (raiz, chave);
}

noh* avl::removeAux (noh* umNoh, tipoChave chave) {
    if (umNoh == NULL) {
        throw runtime_error ("Erro na remoção: chave não encontrada!");
    } 
    else {
        noh* novaRaizSubArvore = umNoh;
        if (chave < umNoh->elemento.chave)
            umNoh->esq = removeAux (umNoh->esq, chave);
        else if (chave > umNoh->elemento.chave)
            umNoh->dir = removeAux (umNoh->dir, chave);
        else {
            if (umNoh->esq == NULL)
                novaRaizSubArvore = umNoh->dir;
            else if (umNoh->dir == NULL)
                novaRaizSubArvore = umNoh->esq;
            else {
                novaRaizSubArvore = encontraMenor (umNoh->dir);
                novaRaizSubArvore->dir = removeMenor (umNoh->dir);
                novaRaizSubArvore->esq = umNoh->esq;
            }
            delete umNoh;
        }
        return arrumaBalanceamento (novaRaizSubArvore);
    }
}

// utiliza o nó atual e seu nível na árvore (para facilitar visualização)
void avl::percorreEmOrdemAux (noh* umNoh, int& contador, string local) {
    if (umNoh != NULL) {
        percorreEmOrdemAux (umNoh->esq, contador, local);
        if (umNoh->elemento.localizacao == local)
            contador += umNoh->elemento.quantidadeDisponivel;
        percorreEmOrdemAux (umNoh->dir, contador, local);
    }
}

ostream& operator<<(ostream& output, avl& arvore) {
    arvore.imprimir ();
    return output;
}

// imprime formatado seguindo o padrao tree as subarvores direitas de uma avl
void avl::imprimirDir (const std::string& prefixo, const noh* meuNoh) {
    if ( meuNoh != nullptr ) {
        std::cout << prefixo
                  << "└d─"
                  << "(" << meuNoh->elemento.chave << "," << meuNoh->elemento.nomeLivro << ")"
                  << std::endl;

        // Repassa o prefixo para manter o historico de como deve ser a formatacao e chama no filho direito e esquerdo
        imprimirEsq ( prefixo + "    " , meuNoh->esq , meuNoh->dir==nullptr );
        imprimirDir ( prefixo + "    " , meuNoh->dir );
    }
}

// imprime formatado seguindo o padrao tree as subarvores direitas de uma avl
void avl::imprimirEsq (const std::string& prefixo, const noh* meuNoh, bool temIrmao) {
    if( meuNoh != nullptr ) {
        std::cout << prefixo ;

        // A impressao da arvore esquerda depende da indicacao se existe o irmao a direita
        if (temIrmao)
            std::cout << "└e─" ;
        else
            std::cout << "├e─";

        std::cout << "(" << meuNoh->elemento.chave << "," << meuNoh->elemento.nomeLivro << ")"
                  << std::endl;

        // Repassa o prefixo para manter o historico de como deve ser a formatacao e chama no filho direito e esquerdo
        imprimirEsq( prefixo + "│   " , meuNoh->esq, meuNoh->dir==nullptr );
        imprimirDir( prefixo + "│   " , meuNoh->dir );
    }
}

// imprime formatado seguindo o padrao tree uma avl
void avl::imprimir () {
    if( this->raiz != nullptr ) {
        std::cout << "(" << this->raiz->elemento.chave << "," << this->raiz->elemento.nomeLivro << ")" << std::endl;
        // apos imprimir a raiz, chama os respectivos metodos de impressao nas subarvore esquerda e direita
        // a chamada para a impressao da subarvore esquerda depende da existencia da subarvore direita
        imprimirEsq( " " , this->raiz->esq, this->raiz->dir==nullptr );
        imprimirDir( " " , this->raiz->dir );
    }
    else
        std::cout << "*arvore vazia*" << std::endl;
}

int avl::levantamento (string local) {
    int cont = 0;
    percorreEmOrdemAux (raiz, cont, local);
    return cont;
}

int main () {
    avl arvore;
    tipoChave chave;
    dado umDado;
    string local;
    int quantidade;
    char operacao;
    do {
        try {
            cin >> operacao;
            switch (operacao) {
                case 'i': // Inserir recursivamente
                    // objeto recebe chave, nome do livro, localização, quantidade disponível
                    cin >> umDado;
                    arvore.insere (umDado);
                    break;
                case 'r': // Remover recursivamente
                    cin >> chave;
                    arvore.remove (chave);
                    break;
                case 'b': // Buscar
                    cin >> chave; // ler a chave
                    umDado = arvore.busca (chave); // escrever o nome do livro
                    cout << "Elemento buscado: " << umDado << endl;
                    break;
                case 'l': // Levantamento por local
                    cin >> local; // ler o local
                    quantidade = arvore.levantamento (local);
                    cout << "Levantamento do local " << local << ": " << quantidade << endl;
                    break;
                case 'e': // Escrever tudo (em ordem)
                    cout << arvore;
                    break;
                case 'f': // Finalizar execução
                    break;
                default:
                    cout << "Comando invalido!\n";
            }
        } catch (runtime_error& e) {
            cout << e.what () << endl;
        }
    }
    while (operacao != 'f');

    return 0;
}
