#include <fstream>
#include <iostream>
using namespace std;

struct Registro { // registro com os campos a serem lidos da base de dados
        char anzsic06 [5] = {'\0', '\0', '\0', '\0', '\0'};
        char Area [7] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0'};
        // os vetores de char sempre serão inicializados completos por caracteres vazios
        int ano;
        int geo_count;
        int ec_count;
};

void adicionarElemento () {

}

void lerLinhas () {
    Registro registro;
    ifstream leitura ("CSV.dat");
    int linhaInicio, linhaFim;
    cout << "Digite a posicao da linha de inicio da leitura: ";
    cin >> linhaInicio;
    cout << "Digite a posicao da linha de termino da leitura: ";
    cin >> linhaFim;
    cout << endl;
    leitura.seekg ((linhaInicio) * sizeof (Registro));
    for (int i = linhaInicio; i <= linhaFim; i++) {
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
    gravarNovoDado.open ("CSV.dat", ios::in | ios::out | ios::ate);
    cout << "Informe a posicao do registro: ";
    cin >> numLinha;
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
    gravarNovoDado.seekp (numLinha * sizeof (Registro));
    gravarNovoDado.write ((const char*)(&registro), sizeof (Registro));
}

void inverterPosicoes () {
    Registro registro1, registro2;
    fstream receber1, receber2;
    receber1.open ("CSV.dat", ios::in | ios::out | ios::ate);
    receber2.open ("CSV.dat", ios::in | ios::out | ios::ate);
    int pos1, pos2;
    cout << "Posicao de um registro: ";
    cin >> pos1;
    cout << "Posicao de outro registro: ";
    cin >> pos2;
    receber1.seekg (pos1 * sizeof (Registro));
    receber2.seekg (pos2 * sizeof (Registro));
    receber1.read ((char*)(&registro1), sizeof (Registro));
    receber1.seekp (pos2 * sizeof (Registro));
    receber1.write ((const char*)(&registro1), sizeof (Registro));
    receber2.seekp (pos1 * sizeof (Registro));
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
    while (comando != 6) {
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
        else if (comando != 6)
            cout << "ERRO! Comando invalido" << endl;
        cout << endl;
    }

    return 0;
}
