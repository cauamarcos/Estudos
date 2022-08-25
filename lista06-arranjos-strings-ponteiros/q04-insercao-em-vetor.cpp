#include <iostream>
using namespace std;

int main(){
	int k, novo, p;
	cin >> k;
	int vetor[10] = {0};
	for(int i = 0; i < k; i++)
		cin >> vetor[i];
	cin >> novo >> p;
	if(p < 9){
		for(int i = 9; i > p; i--)
			vetor[i] = vetor[i-1];
	}
	vetor[p] = novo;
	for (int i = 0; i < 10; i++)
		cout << vetor[i] << " ";
	
	return 0;
}
