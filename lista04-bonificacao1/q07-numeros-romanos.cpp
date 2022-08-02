#include <iostream>
using namespace std;

string romano (int n){
	int contx = n/10, contv = (n%10)/5, conti = (n%10)%5;
	string num = "";
	if (n > 50)
		num = "NUMERO INVALIDO\n";
	else {
		if (contx == 5)
			num += "L";
		else if (contx == 4)
			num += "XL";
		else {
			while (contx > 0){
				num += "X";
				contx--;
			}
		}
		if (contv == 1 and conti == 4)
			num += "IX";
		else if (contv == 0 and conti == 4)
			num += "IV";
		else {
			while (contv > 0){
				num += "V";
				contv--;
			}
			while (conti > 0){
			num += "I";
			conti--;
			}
		}
		num += "\n";
	}
	return num;
}

int main(){
	int n;
	string resp = "";
	cin >> n;
	while (n > 0){
		resp += romano(n);
		cin >> n;
	}
	cout << resp;
		
	return 0;
}
