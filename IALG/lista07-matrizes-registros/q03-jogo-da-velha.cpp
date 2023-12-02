#include <iostream>
using namespace std;

int main(){
	char matriz[3][3];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			cin >> matriz[i][j];
	}
	bool seguir = true, x, o;
	for (int i = 0; i < 3; i++){
		x = true, o = true;
		int l = i;
		for (int j = 0; j < 3; j++){
			if (matriz[i][j] != 'X')
				x = false;
			if(matriz[i][j] != 'O')
				o = false;
		}
		if (x){
			seguir = false;
			cout << "X" << endl;
			for (int i = 0; i < 3; i++)
				cout << l << " " << i << endl;
		}
		if (o){
			seguir = false;
			cout << "O" << endl;
			for (int i = 0; i < 3; i++)
				cout << l << " " << i << endl;
		}
	}
	if(seguir){
		for (int i = 0; i < 3; i++){
			o = true, x = true;
			int c = i;
			for (int j = 0; j < 3; j++){
				if (matriz[j][i] != 'O')
					o = false;
				if(matriz[j][i] != 'X')
					x = false;
			}
			if (o){
				seguir = false;
				cout << "O" << endl;
				for (int i = 0; i < 3; i++)
					cout << i << " " << c << endl;
			}
			if (x){
				seguir = false;
				cout << "X" << endl;
				for (int i = 0; i < 3; i++)
					cout << i << " " << c << endl;
			}
		}
	}
	if (seguir){
		x = true, o = true;
		for(int i = 0; i < 3; i++){
			if (matriz[i][i] != 'X')
				x = false;
			if(matriz[i][i] != 'O')
				o = false;
		}
		if(x){
			seguir = false;
			cout << "X" << endl;
			for(int i = 0; i < 3; i++)
				cout << i << " " << i << endl;
		}
		if(o){
			seguir = false;
			cout << "O" << endl;
			for(int i = 0; i < 3; i++)
				cout << i << " " << i << endl;
		}
	}
	if (seguir){
		x = true, o = true;
		for(int i = 0; i < 3; i++){
			for(int j = 2; j >= 0; j--){
				if (matriz[i][j] != 'X')
					x = false;
				if(matriz[i][j] != 'O')
					o = false;
				i++;
			}
		}
		if(x){
			seguir = false;
			cout << "X" << endl << "0 2\n1 1\n2 0";
		}
		if(o){
			seguir = false;
			cout << "O" << endl << "0 2\n1 1\n2 0";
		}
	}
	if (seguir)
		cout << "-1";

	return 0;
}
