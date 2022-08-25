#include <iostream>
using namespace std;

struct ladrao{
	string nome;
	string partido;
};

struct op{
	string nome;
	string politico;
	int desviado;
};

int main(){
	int a, b, s = 0;
	cin >> a;
	ladrao vetor[a];
	for(int i = 0; i < a; i++)
		cin >> vetor[i].partido >> vetor[i].nome;
	cin >> b;
	op vet[b];
	for(int i = 0; i < b; i++)
		cin >> vet[i].nome >> vet[i].politico >> vet[i].desviado;
	string p, o;
	cin >> p >> o;
	for(int i = 0; i < b; i++){
		if(o == vet[i].nome){
			for(int j = 0; j < a; j++){
				if(vet[i].politico == vetor[j].nome){
					if(vetor[j].partido == p)
						s += vet[i].desviado;
				}
			}
		}
	}
	cout << s;

	return 0;
}
