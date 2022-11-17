#include <iostream>
using namespace std;

int main(){
	int matriz[4][4];
	bool nao = false;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++)
			cin >> matriz[i][j];
	}
	for(int i = 0; i < 4; i++){
		int cont0 = 0, cont1 = 0;
		for(int j = 0; j < 4; j++){
			if (matriz[i][j] == 0)
				cont0++;
			else if(matriz[i][j] == 1)
				cont1++;
			else
				nao = true;
		}
		if(cont0 != 3 or cont1 != 1)
			nao = true;
	}
	if(nao)
		cout << "nao";
	else
		cout << "sim";
	
	return 0;
}
