#include <iostream>
using namespace std;

unsigned fat(unsigned n){
	unsigned f = 1;
	while(n > 0){
		f *= n;
		n--;
	}
	return f;
}

int main(){
	string w;
	cin >> w;
	char* vetor;
	vetor = new char[w.size()];
	for(unsigned i = 0; i < w.size(); i++)
		vetor[i] = w[i];
	unsigned b = 0, cont = 0, x = 0;
	bool se = true;
	char verificadas[w.size()] = {'x'};
	unsigned denominador[w.size()] = {1};
	for (unsigned i = 0; i < w.size(); i++){
		for (unsigned j = 0; j < w.size(); j++){
			if (verificadas[j] == vetor[i])
				se = false;
		}
		if (se){
			verificadas[b] = vetor[i];
			b++;
		}
	}
	for (unsigned i = 0; i < b; i++){
		for (unsigned j = 0; j < w.size(); j++){
			if (verificadas[i] == vetor[j])
				cont++;
		}
		denominador[x] = cont;
		cont = 0;
		x++;
	}
	unsigned produto = 1;
	for (unsigned i = 0; i < x; i++)
		produto *= fat(denominador[i]);
	cout << fat(w.size()) / produto;

	delete vetor;

	return 0;
}
