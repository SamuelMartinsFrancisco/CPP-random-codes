#include <iostream>

using namespace std;

int main() {
	char number;
	
	cout << "Digite um numero: ";
	cin >> number;
	
	if (number <= 50) {
		for (int i = 0; i < number; i++){
			cout << "a";
		}
	}
	else {
		for (int i = 0; i < number; i++){
			cout << "b";
		}
	}
}
