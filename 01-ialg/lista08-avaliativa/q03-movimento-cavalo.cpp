#include <iostream>
using namespace std;

int main(){
	int n, l, c, cont = 0;
	cin >> n;
	int matriz[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> matriz[i][j];
			if (matriz[i][j] == 1){
				l = i;
				c = j;
			}
		}
	}
	if(l > 1 and c > 0){
		if(matriz[l-2][c-1] == 2)
			cont++;
	}
	if(l > 1 and c < n-1){
		if(matriz[l-2][c+1] == 2)
			cont++;
	}
	if(l > 0 and c > 1){
		if(matriz[l-1][c-2] == 2)
			cont++;
	}
	if(l > 0 and c < n-2){
		if(matriz[l-1][c+2] == 2)
			cont++;
	}
	if(l < n-2 and c > 0){
		if(matriz[l+2][c-1] == 2)
			cont++;
	}
	if(l < n-2 and c < n-1){
		if(matriz[l+2][c+1] == 2)
			cont++;
	}
	if(l < n-1 and c > 1){
		if(matriz[l+1][c-2] == 2)
			cont++;
	}
	if(l < n-1 and c < n-2){
		if(matriz[l+1][c+2] == 2)
			cont++;
	}
	cout << cont;
	return 0;
}
