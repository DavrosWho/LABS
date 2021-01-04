#include <iostream>
#include <fstream>
#include "Goods1.h"
#include "ChildGoods.h"
#include "MilkGoods.h"
#include "Deque.h"
using namespace std;

bool testQuantity(Goods& aGoods, int aQuantity) {
	try {
		cout << "Trying to change the quantity to: " << aQuantity << endl;
		aGoods.changeQuantity(aQuantity);
		return true;
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return false;
	}
}

bool testName(Goods& aGoods, char* aName) {
	try {
		cout << "Trying to change the name to: " << aName<< endl;
		aGoods.changeName(aName);
		return true;
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return false;
	}
}

bool testWCost(Goods& aGoods, int aWCost) {
	try {
		cout << "Trying to change the wholesale cost to: " << aWCost << endl;
		aGoods.changeWCost(aWCost);
		return true;
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return false;
	}
}

bool testMarkup(Goods& aGoods, int aMarkup) {
	try {
		cout << "Trying to change the markup to: " << aMarkup << endl;
		aGoods.markup(aMarkup);
		return true;
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return false;
	}
}

bool testMarkdown(Goods& aGoods, int aMarkdown) {
	try {
		cout << "Trying to change the markdown to: " << aMarkdown << endl;
		aGoods.markdown(aMarkdown);
		return true;
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return false;
	}
}

int main()
{
	Goods goods1;

	if (testQuantity(goods1, -5)) {
		cout << "Change-quantity-test was successful" << endl;
	}
	else {
		cout << "Change-quantity-test was unsuccessful" << endl;
	}
	cout << goods1 << endl;


	if (testQuantity(goods1, 5)) {
		cout << "Change-quantity-test was successful" << endl;
	}
	else {
		cout << "Change-quantity-test was unsuccessful" << endl;
	}
	cout << goods1 << endl;


	char name1[251] = "Name (251 symbol)";
	char* aName1 = new char[251];
	for (int i = 0; i < 251; i++) {
		aName1[i] = name1[i];
	}
	if (testName(goods1, aName1)) {
		cout << "Change-name-test was successful" << endl;
	}
	else {
		cout << "Change-name-test was unsuccessful" << endl;
	}
	cout << goods1 << endl;


	char name2[5] = "Name";
	char* aName2 = new char[5];
	for (int i = 0; i < 5; i++) {
		aName2[i] = name2[i];
	}
	if (testName(goods1, aName2)) {
		cout << "Change-name-test was successful" << endl;
	}
	else {
		cout << "Change-name-test was unsuccessful" << endl;
	}
	cout << goods1 << endl;

	if (testWCost(goods1, -50)) {
		cout << "Change-wcost-test was successful" << endl;
	}
	else {
		cout << "Change-wcost-test was unsuccessful" << endl;
	}
	cout << goods1 << endl;


	if (testWCost(goods1, 50)) {
		cout << "Change-wcost-test was successful" << endl;
	}
	else {
		cout << "Change-wcost-test was unsuccessful" << endl;
	}
	cout << goods1 << endl;


	if (testWCost(goods1, 150)) {
		cout << "Change-wcost-test was successful" << endl;
	}
	else {
		cout << "Change-wcost-test was unsuccessful" << endl;
	}
	cout << goods1 << endl;


	if (testMarkup(goods1, -20)) {
		cout << "Change-markup-test was successful" << endl;
	}
	else {
		cout << "Change-markup-test was unsuccessful" << endl;
	}
	cout << goods1 << endl;


	if (testMarkup(goods1, 20)) {
		cout << "Change-markup-test was successful" << endl;
	}
	else {
		cout << "Change-markup-test was unsuccessful" << endl;
	}
	cout << goods1 << endl;


	if (testMarkdown(goods1, -30)) {
		cout << "Change-markdown-test was successful" << endl;
	}
	else {
		cout << "Change-markdown-test was unsuccessful" << endl;
	}
	cout << goods1 << endl;


	if (testMarkdown(goods1, 30)) {
		cout << "Change-markdown-test was successful" << endl;
	}
	else {
		cout << "Change-markdown-test was unsuccessful" << endl;
	}
	cout << goods1 << endl;


	if (testMarkdown(goods1, 10)) {
		cout << "Change-markdown-test was successful" << endl;
	}
	else {
		cout << "Change-markdown-test was unsuccessful" << endl;
	}
	cout << goods1 << endl;
}
