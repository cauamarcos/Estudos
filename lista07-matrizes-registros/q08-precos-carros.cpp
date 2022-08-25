#include <iostream>
using namespace std;

struct carro{
	string nome;
	int ano;
	int preco;
};

int main(){
	int n, ref;
	cin >> n;
	carro vetor[n];
	for(int i = 0; i < n; i++){
		carro x;
		cin >> x.nome >> x.ano >> x.preco;
		vetor[i] = x;
	}
	cin >> ref;
	for(int i = 0; i < n; i++){
		if(vetor[i].preco < ref)
			cout << vetor[i].nome << " " << vetor[i].ano << " " << vetor[i].preco << endl;
	}

	return 0;
}
