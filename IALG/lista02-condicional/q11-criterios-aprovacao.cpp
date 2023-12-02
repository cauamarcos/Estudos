#include <iostream>
using namespace std;

int main() {
	int matricula, nota, assiduidade, digitos;
	cin >> matricula >> nota >> assiduidade;
	digitos = matricula % 100000;
	string numeros(to_string(digitos));
	if ((nota >= 60 and assiduidade >= 75) or (nota >= 70 and assiduidade >= 65)) {
		string situacao = "A";
		cout << numeros + situacao;
	}else {
		string situacao = "R";
		cout << numeros + situacao;
	}
	
	return 0;
}
