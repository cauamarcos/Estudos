#include <iostream>
using namespace std;

int main() {
	char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
	string w;
	cin >> w;
	int cont = 0, c = 0;
	while(c < 5){
		for(unsigned i = 0; i < w.size(); i++){
			if(w[i] == vogais[c])
				cont++;
		}
		c++;
	}
	cout << cont;
	return 0;
}
