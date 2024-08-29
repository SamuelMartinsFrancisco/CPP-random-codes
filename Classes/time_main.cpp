#include <iostream>
#include "time.h"

using namespace std;

int main() {
	// creating
	Time t1(23, 20, 20);

	t1.print();

	// getting
	cout << "Sao " << t1.getHour() << " horas, " << t1.getMinute() << " minutos e " << t1.getSecond() << " segundos! :D" << endl;  

	// setting
	t1.setHour(15);
	t1.setMinute(55);
	t1.setSecond(22);

	t1.print();
	
	// other methods
	t1.nextSecond();
	t1.print();
}
