#include <iostream>
#include <fstream>
using namespace std;

int primo(int a){
	int cont = 0, d = 2;
	if(a <= 0)
		return -1;
	while(d < a){
		if(a % d == 0)
			cont++;
		d++;
	}
	if(cont == 0)
		return a;
	else
		return -1;
}

int main(){
	ofstream escrever("inteiros.dat");
	ifstream ler("inteiros.dat");
	ofstream gravar("primos.dat");
	ifstream l("primos.dat");
	int x, h;
	cin >> x;
	int esc[x];
	for(int i = 0; i < x; i++)
		cin >> esc[i];
	escrever.write((const char*)(&x), sizeof(int));
	escrever.write((const char*)(esc), sizeof(int)*x);
	escrever.close();
	if (ler){
		int n, c = 0, b = 0;
		ler.read((char*)(&n), sizeof(int));
		int num[n];
		ler.read((char*)(num), sizeof(int)*n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++){
				if (num[i] == num[j])
					num[i] = -1;
			}
			num[i] = primo(num[i]);
		}
		for(int i = 0; i < n; i++){
			if(num[i] != -1)
				c++;
		}
		int primos[c];
		for(int i = 0; i < n; i++){
			if(num[i] != -1){
				primos[b] = num[i];
				b++;
			}
		}
		gravar.write((const char*)(&b), sizeof(int));
		gravar.write((const char*)(primos), sizeof(int)*c);
		gravar.close();
		ler.close();
	}
	l.read((char*)(&h), sizeof(int));
	int final[h];
	cout << h << " ";
	l.read((char*)(final), sizeof(int)*h);
	for(int i = 0; i < h; i++)
		cout << final[i] << " ";

	return 0;
}
