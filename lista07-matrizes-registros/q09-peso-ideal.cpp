#include <iostream>
using namespace std;

struct paciente{
	string nome;
	char sexo;
	float altura;
	float peso;
	float ideal;
};

int main(){
	int n;
	cin >> n;
	paciente vetor[n];
	for(int i = 0; i < n; i++){
		paciente x;
		cin >> x.nome >> x.sexo >> x.altura >> x.peso;
		vetor[i] = x;
	}
	float maior = vetor[0].peso;
	string pesado = vetor[0].nome;
	for(int i = 1; i < n; i++){
		if(vetor[i].peso > maior)
			pesado = vetor[i].nome;
	}
	cout << pesado << endl;
	for(int i = 0; i < n; i++){
		if(vetor[i].sexo == 'H')
			vetor[i].ideal = 72.7 * vetor[i].altura - 58;
		else
			vetor[i].ideal = 62.1 * vetor[i].altura - 44.7;
		if(vetor[i].peso > vetor[i].ideal)
			cout << vetor[i].nome << " " << vetor[i].ideal - vetor[i].peso << endl;
	}
	for(int i = 0; i < n; i++){
		if(vetor[i].peso < vetor[i].ideal)
				cout << vetor[i].nome << " " << vetor[i].ideal - vetor[i].peso << endl;
	}

	return 0;
}
