#include <fstream>
#include <iostream>
using namespace std;

struct Registro { // registro com os campos a serem lidos da base de dados
    char anzsic06 [5] = {char(0)};
    char Area [7] = {char(0)};
    char ano [7] = {char(0)};
    char geo_count [7] = {char(0)};
    char ec_count [7] = {char(0)};
    // os vetores de char sempre serão inicializados completos por caracteres nulos
};

void inverterPosicoes (long long int pos1, long long int pos2) {
    Registro registro1, registro2;
    fstream receber1, receber2;
    receber1.open ("CSV.bin", ios::in | ios::out | ios::ate); // declaração das funções de manipulação do arquivo binário
    receber2.open ("CSV.bin", ios::in | ios::out | ios::ate);
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
    // encerramento das funções
    receber1.close ();
    receber2.close ();
}

long long int particionar (fstream& arquivo, long long int menor, long long int maior) {
    // essa função irá dividir o arquivo
    Registro pivot, aux;
    arquivo.seekg (maior * sizeof (Registro));
    arquivo.read ((char*) (&pivot), sizeof (Registro));
    // leitura do último elemento do arquivo como pivot
    long long int i = menor - 1;
    for (long long int j = menor; j < maior; j++) {
        arquivo.seekg (j * sizeof (Registro));
        arquivo.read ((char*)(&aux), sizeof (Registro));
        // leitura dos outros elementos do arquivo, um a cada looping
        if (string (aux.Area) < string (pivot.Area) or (string (aux.Area) == string (pivot.Area) and string (aux.geo_count) <= string (pivot.geo_count))) {
            // caso a comparação atenda aos critérios de ordenação, é feita a troca de posições
            i++;
            inverterPosicoes (i, j);
        }
    }
    // por fim, trocamos as posições do pivô e do maior elemento
    inverterPosicoes (i + 1, maior);
    return i + 1;
}

void quicksort (fstream& arquivo, long long int menor, long long int maior) {
    // a função recebe como parâmetros a função de manipulação do arquivo
    // e as posições do primeiro e do último registros contidos nele
    if (menor < maior) {
        long long int pos = particionar (arquivo, menor, maior);
        quicksort (arquivo, menor, pos - 1);
        quicksort (arquivo, pos + 1, maior);
    }
}

int main () {
    fstream arquivo;
    arquivo.open ("CSV.bin", ios::in | ios::out); // abertura do arquivo para leitura e escrita
    Registro registro;
    arquivo.seekg (0, arquivo.end);
    // posicionamento da cabeça de leitura no final do arquivo
    long long int tam_bytes = arquivo.tellg ();
    long long int qtdCadastrados = tam_bytes / sizeof (Registro);
    arquivo.seekg (0, arquivo.beg);
    // retorno da cabeça de leitura para o início do arquivo
    quicksort (arquivo, 0, qtdCadastrados); // chamada do método de ordenação usado
    arquivo.close (); // encerramento da função de manipulação do arquivo
    cout << "Arquivo ordenado com sucesso!" << endl;
    
    return 0;
}
