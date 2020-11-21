#include <iostream>
#include "Goods1.h"
using namespace std;

bool testAssignment(Goods aGoods1, Goods aGoods2) {
	if (aGoods1.getDate() == aGoods2.getDate() && aGoods1.getQuantity() == aGoods2.getQuantity() && 
		aGoods1.getMarkup() == aGoods2.getMarkup() && aGoods1.getWCost() == aGoods2.getWCost() && 
		aGoods1.getRCost() == aGoods2.getRCost()) {
		return true;
	}
	else {
		return false;
	}
}

bool testIncrementDecrement(time_t* prevDate, Goods aGoods) {
	time_t aDate1 = *aGoods.getDate();
	int64_t t1 = static_cast<int64_t>(aDate1);
	time_t aDate2 = *prevDate;
	int64_t t2 = static_cast<int64_t>(aDate2);
	if (t1 + 86400 == t2 || t1 - 86400 == t2) {
		return true;
	}
	else {
		return false;
	}
}

bool testAddition(int answer, Goods aGoods, int add) {
	if (answer == aGoods.getQuantity() + add) {
		return true;
	}
	else {
		return false;
	}
}

bool testSubtraction(int subtrahend, Goods aGoods) {
	if (subtrahend <= aGoods.getQuantity()) {
		return true;
	}
	else {
		return false;
	}
}

bool testDouble(Goods aGoods, double aRCost) {
	if (double(aGoods.getRCost()) == aRCost) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	char* strGoods1 = new char[100];

	Goods GoodsTest;
	char aName1[15] = "Mushrooms";
	char* name1 = new char[15];
	name1 = aName1;
	time_t* date1 = new time_t(1000000000);
	Goods GoodsTest2(name1, 200, 201, 202, date1);
	GoodsTest = GoodsTest2;
	if (testAssignment(GoodsTest, GoodsTest2)) {
		cout << "Assignment-test was successul\nOur Goods: ";
		GoodsTest.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		GoodsTest2.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "\n\n";
	}
	else {
		cout << "Assignment-test was failed\n\n";
	}

	Goods Goods1;
	time_t* aDate1 = Goods1.getDate();
	cout << "Our goods before the change: ";
	Goods1.toString(strGoods1);
	for (int i = 0; i < 100; i++) {
		cout << strGoods1[i];
	}
	cout << ".........................................................\n";
	//Goods1--;
	--Goods1;
	if (testIncrementDecrement(aDate1, Goods1)) {
		cout << "Increment-Decrement-test was successul\nOur Goods after the change: ";
		Goods1.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "\n\n";
	}
	else {
		Goods1.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "Increment-Decrement-test was failed\n\n";
	}

	Goods Goods2;
	int add = 150;
	int answer = Goods2.getQuantity() + add;
	if (testAddition(answer, Goods2, add)) {
		cout << "Addition-test was successul\n" << add << " + " << Goods2.getQuantity() << " = " << answer;
		cout << "\n\n";
	}
	else {
		cout << "Addition-test was failed\n\n";
	}

	int subtrahend = 20;
	if (testSubtraction(subtrahend, Goods2)) {
		cout << "Subtration-test was successul\n" << Goods2.getQuantity() << " - " << subtrahend << " = " << answer;
		cout << "\n\n";
	}
	else {
		cout << "Subtration-test was failed. You can't subtract " << subtrahend << " from " << Goods2.getQuantity() << "\n\n";
	}
	
	double aRCost = 100;
	if (testDouble(Goods2, aRCost)) {
		cout << "Double-type-test was successul\n" << double(Goods2.getRCost()) << " = " << aRCost;
		cout << "\n\n";
	}
	else {
		cout << "Double-type-test was failed\n\n";
	}

	time_t time1 = 5000000000;
	time_t* timeptr1 = &time1;
	Goods Goods3;
	Goods3.changeDate(timeptr1);
	Goods3.toString(strGoods1);
	for (int i = 0; i < 100; i++) {
		cout << strGoods1[i];
	}
	cout << "\n\n";

	cout << Goods::goodsCount << " unique goods are stored in the warehouse.";
}
