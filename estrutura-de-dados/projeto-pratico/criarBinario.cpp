#include <iostream>
#include <fstream>
using namespace std;

struct Registro { // criação do registro compatível aos dados que serão lidos do arquivo csv
        char anzsic06 [5] = {'\0', '\0', '\0', '\0', '\0'};
        char Area [7];
        int ano;
        int geo_count;
        int ec_count;
};

void tratar (string dados, Registro &registro) { // função para converter a linha retirada do arquivo no int main para um registro
    int contVirgulas = 0, posArea = 0, posVetor = 0;
    string converter = "";
    int tam = dados.size ();
    for (int i = 0; i < tam; i++) { // o laço de repetição vai rodar uma vez para cada caractere contido na linha lida do arquivo csv
        if (dados [i] != ',') {
            if (contVirgulas == 0) { // antes de ser encontrada a primeira vírgula todos os caracteres serão agrupados no vetor de caractere do anzsic06
                registro.anzsic06 [posVetor] = dados [i];
                posVetor++;
            }
            else if (contVirgulas == 1) { // depois da primeira vírgula vem a area, também armazenada como vetor de char
                registro.Area [posArea] = dados [i];
                posArea++;
            }
            else if (contVirgulas == 2) { // depois da segunda vírgula vem o ano
                converter += dados [i];
                registro.ano = stoi (converter); // usamos a função stoi () para converter uma string em um int a cada vez que a variável converter receber um novo número em sua extensão
            }
            else if (contVirgulas == 3) { // após a terceira vígula é convertido o geo_count
                converter += dados [i];
                registro.geo_count = stoi (converter);
            }
            else if (contVirgulas == 4) { // após a quarta vígula é convertido o ec_count
                converter += dados [i];
                registro.ec_count = stoi (converter);
            }
        }
        else { // se o caractere da posição i na linha lida for uma vírgula, então 
        // o contVírgulas será acrescido e a variável "converter" será limpada para receber o próximo dado
            converter = "";
            contVirgulas++;
        }
    }
}

void converterParaBinario (Registro registro) { // funçaõ de conversão que será chamada a cada linha lida
    ofstream gravar ("CSV.dat", ios::app); // abertura do arquivo para gravação em binário no final
    gravar.write ((const char*)(&registro), sizeof (Registro)); // gravação em binário
    gravar.close (); // fechamento da escrita no arquivo
}

int main () {
    ifstream ler ("Data7602DescendingYearOrder.csv"); // criação da função para leitura do arquivo csv
    string linha;
    Registro campos;
    if (ler) {
        getline (ler, linha); // leitura do cabeçalho, que não é gravado em binário 
        while (ler) {
            getline (ler, linha); // cada linha lida
            tratar (linha, campos); // é usada para criar um registro
            converterParaBinario (campos); // e o registro é gravado no arquivo binário
        }
    }
    else {
        ler.close (); // encerramento da função de leitura quando não é possível ler mais
    }
}
