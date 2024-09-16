#include <iostream>
using namespace std;

int main(){
	int matriz[10][10];
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++)
			cin >> matriz[i][j];
	}
	int maior = matriz[0][0], l;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (matriz[i][j] > maior){
				maior = matriz[i][j];
				l = i;
			}
		}
	}
	int minimax = maior, c;
	for (int i = 0; i < 10; i++){
		if (matriz[l][i] < minimax){
			minimax = matriz[l][i];
			c = i;
		}
	}
	cout << minimax << endl << l << " " << c;
	
	return 0;
}
