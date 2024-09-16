#include <iostream>
#include <fstream>
using namespace std;

string cifrar(string x){
	ifstream ler(x);
	ofstream gravar("cifrado");
	if (ler){
		char caractere;
		while(ler.get(caractere)){
			if(caractere == 88)
				gravar << 'A';
			else if(caractere == 89)
				gravar << 'B';
			else if(caractere == 90)
				gravar << 'C';
			else if (caractere == 32 or caractere == 10)
				gravar << caractere;
			else
				gravar << char(caractere+3);
		}
		gravar.close();
		ler.close();
	}
	return "OK";
}

int main(){
	string nome;
	cin >> nome;
	cifrar(nome);

	return 0;
}
