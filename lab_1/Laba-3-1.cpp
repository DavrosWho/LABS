#include <iostream>
#include "Goods1.h"
using namespace std;

//Тест на возможность смены наименования товара
bool testName(int nameLength) {
	if (nameLength > 15 || nameLength < 0) {
		return false;
	}
	else {
		return true;
	}
}

//Тест на возможность смены количества единиц товара
bool testQuantity(int aQuantity) {
	if (aQuantity < 0 || aQuantity > 9999999) {
		return false;
	}
	else {
		return true;
	}
}

//Тест на возможность смены оптовой стоимости товара
bool testWCost(Goods aGoods, int aWCost) {
	if (aGoods.getRCost() < aWCost) {
		return false;
	}
	else {
		return true;
	}
}

//Тест на возможность смены наценки товара
bool testMarkup(Goods aGoods, int aMarkup) {
	if (aGoods.getWCost() + aMarkup > 9999999 || aMarkup < 0) {
		return false;
	}
	else {
		return true;
	}
}

//Тест на возможность смены уценки товара
bool testMarkdown(Goods aGoods, int aMarkdown) {
	if (aGoods.getMarkup() < 0 || aMarkdown < 0) {
		return false;
	}
	else {
		return true;
	}
}

int main()
{
	Goods Goods1;
	char* strGoods1 = new char[100];
	const int nameLength1 = 25;
	char name1[nameLength1] = "Raxacoricofallapatorians";
	cout << name1 << " goods ";
	if (testName(nameLength1)) {
		cout << "can be registered.\nChange-name-test was successfully\nOur goods: ";
		Goods1.changeName(name1);
		Goods1.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "\n\n";
	}
	else {
		cout << "can't be registered. There cannot be more than 15 symbols\nCange-name-test failed\n\n";
	}
	
	const int nameLength2 = 15;
	char name2[nameLength2] = "Milk";
	cout << name2 << " goods ";
	if (testName(nameLength2)) {
		cout << "can be registered.\nChange-name-test was successfully\nOur goods: ";
		Goods1.changeName(name2);
		Goods1.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "\n\n";
	}
	else {
		cout << "can't be registered. There cannot be more than 15 symbols\nCange-name-test failed\n\n";
	}

	int quantity1 = -100;
	if (testQuantity(quantity1)) {
		cout << "We can store " << quantity1 << " units of goods.\nChange-quantity-test was successfully\nOur goods:";
		Goods1.changeQuantity(quantity1);
		Goods1.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "\n\n";
	}
	else {
		cout << "We can't store" << quantity1 << " units of goods. Our warehouse accommodates from 0 to 9999999 units of one goods\nChange-quantity-test failed\n\n";
	}

	quantity1 = 215;
	if (testQuantity(quantity1)) {
		cout << "We can store " << quantity1 << " units of goods.\nChange-quantity-test was successfully\nOur goods:";
		Goods1.changeQuantity(quantity1);
		Goods1.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "\n\n";
	}
	else {
		cout << "We can't store" << quantity1 << " units of goods. Our warehouse accommodates from 0 to 9999999 units of one goods\nChange-quantity-test failed\n\n";
	}

	int wCost1 = 200;
	if (testWCost(Goods1, wCost1)) {
		cout << "Now wholesale cost is " << wCost1 << ".\nChange-WCost-test was successfully\nOur goods:";
		Goods1.changeWCost(wCost1);
		Goods1.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "\n\n";
	}
	else {
		cout << "Wholesale cost can't be " << wCost1 << ". It's bigger than retail cost\nChange-WCost-test failed\n\n";
	}

	int markup1 = 101;
	if (testMarkup(Goods1, markup1)) {
		cout << "Change the value of the markup by " << markup1 << " coins.\nChange-Markup-test was successfulled\nOur goods:";
		Goods1.markup(markup1);
		Goods1.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "\n\n";
	}
	else {
		cout << "Markup can't be " << wCost1 << "coins. It's always > 0\nChange-Markup-test failed\n\n";
	}

	int markdown1 = 32;
	if (testMarkdown(Goods1, markdown1)) {
		cout << "We can add markdown of " << markdown1 << " coins.\nChange-Markdown-test was successfulled\nOur goods:";
		Goods1.markdown(markdown1);
		Goods1.toString(strGoods1);
		for (int i = 0; i < 100; i++) {
			cout << strGoods1[i];
		}
		cout << "\n\n";
	}
	else {
		cout << "We can't add markdown of " << markdown1 << " coins. Wholesale cost can't be less than retail cost.\nChange-Markdown-test failed\n\n";
	}

	cout << Goods::goodsCount << " unique goods are stored in the warehouse.";
}
