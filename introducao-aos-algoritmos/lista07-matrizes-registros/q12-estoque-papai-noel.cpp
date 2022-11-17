#include <iostream>
using namespace std;

struct Cartinha{
	string nome;
	string presente;
};

struct Brinquedo{
	string brinquedo;
	int qtd_disp;
	int qtd_ped;
};


int main(){
	int n, x, cont = 0;
	cin >> n;
	Cartinha vetor[n];
	for(int i = 0; i < n; i++)
		cin >> vetor[i].nome >> vetor[i].presente;
	cin >> x;
	Brinquedo estoque[x];
	for(int i = 0; i < x; i++){
		cin >> estoque[i].brinquedo >> estoque[i].qtd_disp;
		estoque[i].qtd_ped = 0;
	}
	bool tem = false;
	while(cont < n){
		for(int j = 0; j < x; j++){
			if(vetor[cont].presente == estoque[j].brinquedo){
				estoque[j].qtd_ped++;
				tem = true;
			}
		}
		if(tem == false)
			cout << vetor[cont].presente;
		cont++;
	}
	for(int i = 0; i < x; i++){
		if(estoque[i].qtd_ped > estoque[i].qtd_disp)
			cout << estoque[i].brinquedo << " ";
	}

	return 0;
}
