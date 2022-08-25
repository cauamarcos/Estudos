#include <iostream>
#include <fstream>
using namespace std;

int validar(int a){
	if (a % 3 == 0)
		return -1;
	else
		return a;
}

int main(){
	string nome;
	cin >> nome;
	ifstream ler(nome);
	ofstream gravar("saida.txt");
	int n;
	if(ler){
		while(ler >> n){
			n = validar(n);
			if(n != -1)
				gravar << n << " ";
		}
	}

	return 0;
}
