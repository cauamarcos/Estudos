#include <iostream>
using namespace std;

int main(){
	int n, divisor = 1;
	cin >> n;
	while (divisor <= n){
		if (n % divisor == 0){
			if ((divisor * (divisor+1) * (divisor+2)) == n){
				cout << "TRIANGULAR " << divisor << " " << divisor+1 << " " << divisor+2;
				divisor = n + 1;
			}
			else if (divisor == n){
			divisor++;
			cout << "NAO TRIANGULAR";
			}
			else
				divisor++;
		}
		else
			divisor++;
	}
	return 0;
}
