#include <iostream>
using namespace std;

int main(){
	string s1, s2, s;
	getline(cin, s1), getline(cin, s2);
	s = s1 + s2;
	char* vet;
	int x = s1.size() + s2.size();
	vet = new char[x];
	for(unsigned i = 0; i < s.size(); i++)
		vet[i] = s[i];
	for(unsigned i = 0; i < s.size(); i++)
		cout << vet[i];

	return 0;
}
