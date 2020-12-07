#include <iostream>
#include <fstream>
#include "Goods1.h"
#include "ChildGoods.h"
#include "MilkGoods.h"
using namespace std;

int main()
{
	ChildGoods Pony;
	char name[8] = "Koumiss";
	char* aName = new char[8];
	for (int i = 0; i < 8; i++) {
		aName[i] = name[i];
	}

	time_t* date1 = new time_t(1);
	time_t* date2 = new time_t(1000000);
	MilkGoods Koumiss(aName, 100, 100, 200, date1, date2);

	cout << endl << Pony << endl << Koumiss << endl;
	Koumiss.recount();
	cout << Koumiss << endl;

	if (Pony.getCategory() == 1) {
		cout << "Age category of " << Pony.getName() << " is 0-3 y.o" << endl;
	} 
	else if (Pony.getCategory() == 2) {
		cout << "Age category of " << Pony.getName() << " is 3-5 y.o" << endl;
	}
	else if (Pony.getCategory() == 3) {
		cout << "Age category of " << Pony.getName() << " is 7-9 y.o" << endl;
	}
	else if (Pony.getCategory() == 4) {
		cout << "Age category of " << Pony.getName() << " is 10+ y.o" << endl;
	}
	else {
		cout << "Age category of " << Pony.getName() << " is unknown" << endl;
	}

	cout << Goods::goodsCount << " unique goods are stored in the warehouse.";
}
