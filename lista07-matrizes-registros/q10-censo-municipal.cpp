#include <iostream>
#include <cmath>
using namespace std;

struct habitante{
	float salario;
	int idade;
	int filhos;
};

int main(){
	int n;
	cin >> n;
	habitante vetor[n];
	for(int i = 0; i < n; i++){
		habitante x;
		cin >> x.salario >> x.idade >> x.filhos;
		vetor[i] = x;
	}
	float maior = vetor[0].salario, s = 0, f = 0, cont = 0;
	for(int i = 0; i < n; i++){
		if(vetor[i].salario > maior)
			maior = vetor[i].salario;
		s += vetor[i].salario;
		f += vetor[i].filhos;
		if(vetor[i].salario > 1000)
			cont++;
	}
	cout << s / n << endl << f / n << endl << maior << endl << round((cont/n)*100) << "%";

	return 0;
}
