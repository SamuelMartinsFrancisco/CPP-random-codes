#include <iostream>

using namespace std;

int main(){
	int number1;
	int number2;
	
	cout << "Digite o primeiro numero: ";
	cin >> number1;
	cout << "Digite o segundo numero: ";
	cin >> number2;

	int sum = number1 + number2;
	int sub = number1 - number2;
	int mul = number1 * number2;
	float div = number1 / number2;
	int rest = number1 % number2;

	cout << "\nValores: " << number1 << " e " << number2 << endl;
	cout << "Soma: " << sum << endl;
	cout << "Subtracao: " << sub << endl;
	cout << "Multiplicacao: " << mul << endl;
	cout << "Divisao: " << div << endl;
	cout << "Resto da divisao: " << rest << endl;
	
	return 0;
}
