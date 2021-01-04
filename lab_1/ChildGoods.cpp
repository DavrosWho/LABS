#pragma warning (disable: 4996)
#include "ChildGoods.h"
#include <iostream>
using namespace std;

ChildGoods::ChildGoods() {
	category = 0;
	type = 0;
	char aName[15] = "#100";
	goodsName = new char[15];
	for (int i = 0; i < 15; i++) {
		goodsName[i] = aName[i];
	}
	goodsQuantity = 0;
	wholesaleCost = 100;
	retailCost = 100;
	goodsDate = new time_t(500000000);
}

ChildGoods::ChildGoods(char* aName, int aGoodsQuantity, int aWCost, int aRCost, time_t* aDate, int aCategory, int aType) {
	category = aCategory;
	type = aType;
	goodsName = new char[15];
	for (int i = 0; i < 15; i++) {
		goodsName[i] = aName[i];
	}
	goodsQuantity = aGoodsQuantity;
	wholesaleCost = aWCost;
	retailCost = aRCost;
	goodsDate = aDate;
}

std::ostream& operator << (std::ostream& out, ChildGoods& aGoods) {
	char* str = new char[242];
	str = aGoods.toString();
	out << str;
	return out;
	delete[] str;
}

char* ChildGoods::toString() {
	char* strGoods = new char[250];
	int j = 0;
	char age1[9] = "0-3y.o. ";
	char age2[9] = "3-5y.o. ";
	char age3[9] = "5-9y.o. ";
	char age4[9] = "10+y.o. ";
	char age5[9] = "unknown ";
	char aType1[6] = "soft ";
	char aType2[13] = "constructor ";
	char aType3[7] = "sport ";
	char aType4[5] = "car ";
	char aType5[9] = "unknown ";
	char text[59] = "Age category, type, name, quantity, wCost, rCost, date: ";
	char strQuantity[7];
	int container1 = goodsQuantity;
	for (int i = 0; i < 7; i++)
	{
		if (goodsQuantity == 0) {
			strQuantity[0] = '0';
			for (int j = 1; j < 7; j++) {
				strQuantity[j] = ' ';
			}
			break;
		}
		else if (container1 == 0) {
			strQuantity[6 - i] = ' ';
		}
		else {
			strQuantity[6 - i] = (container1 % 10) + '0';
			container1 /= 10;
		}
	}

	char strWCost[7];
	int container2 = wholesaleCost;
	for (int i = 0; i < 7; i++)
	{
		if (wholesaleCost == 0) {
			strWCost[0] = '0';
			for (int j = 1; j < 7; j++) {
				strWCost[j] = ' ';
			}
			break;
		}
		else if (container2 == 0) {
			strWCost[6 - i] = ' ';
		}
		else {
			strWCost[6 - i] = (container2 % 10) + '0';
			container2 /= 10;
		}
	}

	char strRCost[7];
	int container3 = retailCost;
	for (int i = 0; i < 7; i++)
	{
		if (retailCost == 0) {
			strRCost[0] = '0';
			for (int j = 1; j < 7; j++) {
				strRCost[j] = ' ';
			}
			break;
		}
		else if (container3 == 0) {
			strRCost[6 - i] = ' ';
		}
		else {
			strRCost[6 - i] = (container3 % 10) + '0';
			container3 /= 10;
		}
	}

	for (int i = 0; i < 57; i++, j++) {
		strGoods[j] = text[i];
	}
	j--;

	if (category == 1) {
		for (int i = 0; i < 9; i++, j++) {
			strGoods[j] = age1[i];
		}
	}
	else if (category == 2) {
		for (int i = 0; i < 9; i++, j++) {
			strGoods[j] = age2[i];
		}
	}
	else if (category == 3) {
		for (int i = 0; i < 9; i++, j++) {
			strGoods[j] = age3[i];
		}
	}
	else if (category == 4) {
		for (int i = 0; i < 9; i++, j++) {
			strGoods[j] = age4[i];
		}
	}
	else if (category < 1 || category > 4) {
		for (int i = 0; i < 9; i++, j++) {
			strGoods[j] = age5[i];
		}
	}
	j--;

	if (type == 1) {
		for (int i = 0; i < 6; i++, j++) {
			strGoods[j] = aType1[i];
		}
	}
	else if (type == 2) {
		for (int i = 0; i < 13; i++, j++) {
			strGoods[j] = aType2[i];
		}
	}
	else if (type == 3) {
		for (int i = 0; i < 7; i++, j++) {
			strGoods[j] = aType3[i];
		}
	}
	else if (type == 4) {
		for (int i = 0; i < 5; i++, j++) {
			strGoods[j] = aType4[i];
		}
	}
	else if (type < 1 || type > 4) {
		for (int i = 0; i < 9; i++, j++) {
			strGoods[j] = aType5[i];
		}
	}
	j--;

	for (int i = 0; i < 15; i++, j++) {
		if (goodsName[i] == '\0') {
			break;
		}
		else {
			strGoods[j] = goodsName[i];
		}
	}
	strGoods[j] = ' ';
	j++;

	for (int i = 0; i < 7; i++) {
		if (strQuantity[i] == '\0') {
			break;
		}
		else if (strQuantity[i] == ' ') {

		}
		else {
			strGoods[j] = strQuantity[i];
			j++;
		}
	}
	strGoods[j] = ' ';
	j++;

	for (int i = 0; i < 7; i++) {
		if (strWCost[i] == '\0') {
			break;
		}
		else if (strWCost[i] == ' ') {

		}
		else {
			strGoods[j] = strWCost[i];
			j++;
		}
	}
	strGoods[j] = ' ';
	j++;

	for (int i = 0; i < 7; i++) {
		if (strRCost[i] == '\0') {
			break;
		}
		else if (strRCost[i] == ' ') {

		}
		else {
			strGoods[j] = strRCost[i];
			j++;
		}
	}
	strGoods[j] = ' ';
	j++;

	for (int i = 0; i < 24; i++) {
		if (ctime(goodsDate)[i] == '\0') {
			break;
		}
		else {
			strGoods[j] = ctime(goodsDate)[i];
			j++;
		}
	}

	for (j; j < strlen(strGoods); j++) {
		strGoods[j] = ' ';
	}

	return strGoods;
}
