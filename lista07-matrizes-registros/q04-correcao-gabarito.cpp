#include <iostream>
using namespace std;

int main(){
	char matriz[11][8];
	float cont = 0, aprovado = 0;
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 8; j++)
			cin >> matriz[i][j];
	}
	for (int i = 1; i < 11; i++){
		for (int j = 0; j < 8; j++){
			if(matriz[i][j] == matriz[0][j])
				cont++;
		}
		float nota = (cont / 8) * 100;
		cont = 0;
		cout << nota << endl;
		if(nota >= 60)
			aprovado++;
	}
	cout << aprovado * 10;

	return 0;
}
