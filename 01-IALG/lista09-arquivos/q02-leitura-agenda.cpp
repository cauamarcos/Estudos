#include <iostream>
#include <fstream>
using namespace std;

struct amigo{
     string nome;
     int idade;
     float altura;
     string telefone;
};

int main(){
	ifstream ler("agenda.txt");
	ofstream gravar("saida.txt");
	int i = 0;
	if (ler){
		amigo* vetor, *copia;
		while(ler){
			vetor = new amigo[i+1];
			for(int a = 0; a < i; a++)
				vetor[a] = copia[a];
			ler >> vetor[i].nome >> vetor[i].idade >> vetor[i].altura >> vetor[i].telefone;
			i++;
			copia = vetor;
		}
		for(int j = 0; j < i-1; j++)
			gravar << "--------\n" << vetor[j].nome << " tem " << vetor[j].idade << " anos e " << vetor[j].altura << " de altura.\n" << "Tel.: " << vetor[j].telefone << ".\n--------\n";
		gravar.close();
	}

	return 0;
}
