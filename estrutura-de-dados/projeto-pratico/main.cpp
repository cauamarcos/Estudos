#include <fstream>
#include <iostream>
using namespace std;

struct Registro { // registro com os campos a serem lidos da base de dados
    char anzsic06 [5] = {'\0', '\0', '\0', '\0', '\0'};
    char Area [7] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0'};
    // os vetores de char sempre serão inicializados completos por caracteres nulos
    int ano;
    int geo_count;
    int ec_count;
};

void adicionarElemento () {
    fstream gravarNovoDado, reposicionarResto;
    string converter;
    // criação das funções de manipulação do arquivo binário
    gravarNovoDado.open ("CSV.dat", ios::in | ios::out | ios::ate);
    reposicionarResto.open ("CSV.dat", ios::in | ios::out | ios::ate);
    Registro novoRegistro, registro, gravar;
    int numLinha;
    cout << "Informe a posicao de insercao do registro: ";
    cin >> numLinha;
    // entrada de novos dados do registro que será inserido
    cout << "anzsic06: ";
    cin >> converter;
    unsigned cont = 0;
    while (cont < 5 and cont < converter.size ()) {
        novoRegistro.anzsic06 [cont] = converter [cont];
        cont++;
    }
    cout << "Area: ";
    cin >> converter;
    cont = 0;
    while (cont < 7 and cont < converter.size ()) {
        novoRegistro.Area [cont] = converter [cont];
        cont++;
    }
    cout << "ano: ";
    cin >> novoRegistro.ano;
    cout << "geo_count: ";
    cin >> novoRegistro.geo_count;
    cout << "ec_count: ";
    cin >> novoRegistro.ec_count;
    // posicionamento da cabeça de leitura na posição em que será inserido o novo registro
    reposicionarResto.seekg (numLinha * sizeof (Registro));
    // leitura do registro que ocupa a posição que será ocupada pelo novo
    reposicionarResto.read ((char*)(&registro), sizeof (Registro));
    // posicionamento da cabeça de escrita na posição em que deve ser inserido o novo registro
    gravarNovoDado.seekp (numLinha * sizeof (Registro));
    // inserção do novo registro
    gravarNovoDado.write ((const char*)(&novoRegistro), sizeof (Registro));
    while (not reposicionarResto.eof ()) {
        // "gravar" é usado para armazenar o registro que teve sua posição ocupada pelo registro que teve sua posição substituída para que ele ocupe a posição do seu sucessor
        gravar = registro;
        // antes de gravar o registro que foi "empurrado", é preciso ler seu sucessor também, que
        // será igualado a "gravar" no próximo looping para que o processo se repita e nenhum
        // registro seja perdido
        reposicionarResto.read ((char*)(&registro), sizeof (Registro));
        // gravação do registro substituído na posição de seu sucessor, que já foi lido para não ser
        // perdido também, fazendo necessária a repetição desse looping por toda a extensão do arquivo
        gravarNovoDado.write ((const char*)(&gravar), sizeof (Registro));
    }
    cout << endl << "Novo registro inserido!" << endl;
}

void lerLinhas () {
    Registro registro;
    ifstream leitura ("CSV.dat"); // criação da função de leitura do arquivo binário
    int linhaInicio, linhaFim;
    // entrada do intervalo de linhas que serão depuradas
    cout << "Digite a posicao da linha de inicio da leitura: ";
    cin >> linhaInicio;
    cout << "Digite a posicao da linha de termino da leitura: ";
    cin >> linhaFim;
    cout << endl;
    // posicionamento da cabeça de leitura na posição inicial
    leitura.seekg ((linhaInicio) * sizeof (Registro));
    for (int j = linhaInicio; j <= linhaFim; j++) {
        // a cada repetição é lido e depurado um registro
        leitura.read ((char*)(&registro), sizeof (Registro));
        for (int i = 0; i < 5; i++)
                cout <<  registro.anzsic06 [i];
            cout << ",";
        for (int i = 0; i < 7; i++)
            cout << registro.Area [i];
        cout << "," << registro.ano << "," << registro.geo_count << "," << registro.ec_count << endl;
    }
}

void editarRegistro () {
    Registro registro;
    string converter;
    int numLinha;
    fstream gravarNovoDado;
    // criação da função para manipular o registro a ser editado no arquivo binário
    gravarNovoDado.open ("CSV.dat", ios::in | ios::out | ios::ate);
    cout << "Informe a posicao do registro: ";
    cin >> numLinha;
    // entrada de novos dados do registro
    cout << "anzsic06: ";
    cin >> converter;
    unsigned cont = 0;
    while (cont < 5 and cont < converter.size ()) {
        registro.anzsic06 [cont] = converter [cont];
        cont++;
    }
    cout << "Area: ";
    cin >> converter;
    cont = 0;
    while (cont < 7 and cont < converter.size ()) {
        registro.Area [cont] = converter [cont];
        cont++;
    }
    cout << "ano: ";
    cin >> registro.ano;
    cout << "geo_count: ";
    cin >> registro.geo_count;
    cout << "ec_count: ";
    cin >> registro.ec_count;
    // posicionamento da cabeça de escrita na posição desejada pelo usuário
    gravarNovoDado.seekp (numLinha * sizeof (Registro));
    // gravação do registro com novos valores na posição solicitada
    gravarNovoDado.write ((const char*)(&registro), sizeof (Registro));
}

void inverterPosicoes () {
    Registro registro1, registro2;
    fstream receber1, receber2;
    receber1.open ("CSV.dat", ios::in | ios::out | ios::ate); // declaração das funções de manipulação do arquivo binário
    receber2.open ("CSV.dat", ios::in | ios::out | ios::ate);
    int pos1, pos2;
    cout << "Posicao de um registro: ";
    cin >> pos1;
    cout << "Posicao de outro registro: ";
    cin >> pos2;
    // posicionamento das cabeças de leitura nas posições desejadas
    receber1.seekg (pos1 * sizeof (Registro));
    receber2.seekg (pos2 * sizeof (Registro));
    // leitura dos registros nas posições solicitadas
    receber1.read ((char*)(&registro1), sizeof (Registro));
    receber2.read ((char*)(&registro2), sizeof (Registro));
    // posicionamento das cabeças de escrita invertendo as posições
    receber1.seekp (pos2 * sizeof (Registro));
    receber2.seekp (pos1 * sizeof (Registro));
    // gravação dos registros com as posições trocadas
    receber1.write ((const char*)(&registro1), sizeof (Registro));
    receber2.write ((const char*)(&registro2), sizeof (Registro));
    cout << endl << "Troca realizada!" << endl;
}

void depurarTodosRegistros () {
    ifstream ler ("CSV.dat"); // abre o arquivo binario para leitura
    Registro registro;
    if (ler) {
        while (not ler.eof ()) { // enquanto for possível ler, a variável "registro" recebe um registro lido do arquivo
            ler.read ((char*)(&registro), sizeof (Registro));
            for (int i = 0; i < 5; i++) // a cada registro lido são depurados seus atributos
                cout <<  registro.anzsic06 [i];
            cout << ",";
            for (int i = 0; i < 7; i++)
                cout << registro.Area [i];
            cout << "," << registro.ano << "," << registro.geo_count << "," << registro.ec_count << endl;
        }
    }
    else {
        ler.close (); // fechamento da função de leitura
    }
}

int main () {
    int comando = 0;
    while (comando != 6) { // impressão do menu de comandos
        cout << "Selecione uma opcao" << endl
             << "[ 1 ] = adicionar elemento" << endl
             << "[ 2 ] = ler posicoes espicificas" << endl
             << "[ 3 ] = alterar um registro" << endl
             << "[ 4 ] = trocar registros de posicao" << endl
             << "[ 5 ] = depurar arquivo binario completo" << endl
             << "[ 6 ] = sair" << endl
             << "Sua escolha: ";
        cin >> comando;
        cout << endl;
        if (comando == 1)
            adicionarElemento ();
        else if (comando == 2)
            lerLinhas ();
        else if (comando == 3)
            editarRegistro ();
        else if (comando == 4)
            inverterPosicoes ();
        else if (comando == 5)
            depurarTodosRegistros ();
        else if (comando == 6)
            cout << "Encerrando sistema...";
        else
            cout << "ERRO! Comando invalido" << endl;
        cout << endl;
    }

    return 0;
}
