#include <iostream>
using namespace std;

int horasMinutos(int mnts, int& h, int& m){
	h = mnts / 60;
	m = mnts % 60;
	return mnts;
}

int main(){
	int t, a, b;
	cin >> t;
	horasMinutos(t, a, b);
	cout << a << endl << b;

	return 0;
}
