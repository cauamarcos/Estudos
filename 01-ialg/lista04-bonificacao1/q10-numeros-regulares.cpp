#include <iostream>
using namespace std;

string regular (int n, string& x){
	string fatores = "";
	while (n % 2 == 0){
		n /= 2;
		fatores += "2 ";
	}
	while (n % 3 == 0){
		n /= 3;
		fatores += "3 ";
	}
	while (n % 5 == 0){
		n /= 5;
		fatores += "5 ";
	}
	if (n == 1){
		x = "REGULAR";
		return fatores;
	} else {
		int divisor = 7;
		while (n > 1){
			if (n % divisor == 0){
				n /= divisor;
				fatores += to_string(divisor) + " ";
			} else
				divisor++;
		}
		x = "NAO REGULAR";
		return fatores;
	}
}

int main(){
	int a;
	string s;
	cin >> a;
	cout << regular(a, s) << endl;
	cout << s;
	
	return 0;
}
