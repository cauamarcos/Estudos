#include <iostream>
using namespace std;

int main() {
	int matricula = 1, m1 = 0, m2 = 0, m_aux;
	float nota = 0, primeira = 0, segunda = 0, nota_aux = 0;
	while (matricula != 0){
		cin >> matricula;
		if(matricula != 0){
			cin >> nota;
			if(nota > primeira){
				nota_aux = primeira;
				m_aux = m1;
				primeira = nota;
				m1 = matricula;
			} else if(nota >= segunda){
				segunda = nota;
				m2 = matricula;
			}
			if(nota_aux > segunda and m_aux != m1){
				segunda = nota_aux;
				m2 = m_aux;
			}
		}
	}
	cout << m1 << " " << primeira << endl << m2 << " " << segunda;
	return 0;
}
