#pragma warning (disable: 4996)
#include "Goods1.h"
#include <iostream>
using namespace std;

int Goods::goodsCount = 0;

Goods::Goods() {
	goodsCount++;
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

Goods::Goods(char* aName, int aGoodsQuantity, int aWCost, int aRCost, time_t* aDate) {
	goodsCount++;
	goodsName = new char[15];
	for (int i = 0; i < 15; i++) {
		goodsName[i] = aName[i];
	}
	goodsQuantity = aGoodsQuantity;
	wholesaleCost = aWCost;
	retailCost = aRCost;
	goodsDate = aDate;
}

Goods& Goods::operator = (Goods aGoods) {
	for (int i = 0; i < 15; i++) {
		goodsName[i] = aGoods.goodsName[i];
	}

	goodsQuantity = aGoods.goodsQuantity;

	wholesaleCost = aGoods.wholesaleCost;

	retailCost = aGoods.retailCost;

	goodsDate = aGoods.goodsDate;
	return *this;
};

Goods Goods::operator++(int) {
	int64_t t1 = 86400;
	time_t aDate1 = *goodsDate;
	int64_t t = static_cast<int64_t>(aDate1) + t1;
	goodsDate = new time_t(t);
	return *this;
}

Goods Goods::operator--(int) {
	int64_t t1 = 86400;
	time_t aDate1 = *goodsDate;
	int64_t t = static_cast<int64_t>(aDate1) - t1;
	goodsDate = new time_t(t);
	return *this;
}

Goods operator+(int aQuantity, Goods aGoods) {
	aGoods.goodsQuantity += aQuantity;
	return aGoods;
}

Goods operator+(Goods aGoods, int aQuantity) {
	aGoods.goodsQuantity += aQuantity;
	return aGoods;
}

Goods operator-(Goods aGoods, int aQuantity) {
	aGoods.goodsQuantity -= aQuantity;
	return aGoods;
}

Goods::operator double() {
	float aRCost = (float)retailCost;
	return aRCost;
}

void Goods::toString(char* strGoods) {
	int j = 0;
	char text[37] = "Name, quantity, wCost, rCost, date: ";
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

	for (int i = 0; i < 37; i++, j++) {
		strGoods[j] = text[i];
	}
	
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

	for (int i = 0; i < 25; i++) {
		if (ctime(goodsDate)[i] == '\0') {
			break;
		}
		else {
			strGoods[j] = ctime(goodsDate)[i];
			j++;
		}
	}

	for (j; j < 100; j++) {
		strGoods[j] = ' ';
	}
}

void Goods::changeQuantity(int aGoodsQuantity) {
	goodsQuantity = aGoodsQuantity;
}

void Goods::changeName(char* aName) {
	for (int i = 0; i < 15; i++) {
		goodsName[i] = aName[i];
	}
}

void Goods::changeWCost(int aWCost) {
	wholesaleCost = aWCost;
}

void Goods::markup(int aMarkup) {
	retailCost = wholesaleCost + aMarkup;
}

void Goods::markdown(int aMarkdown) {
	retailCost = retailCost - aMarkdown;
}

void Goods::changeDate(time_t* aDate) {
	goodsDate = aDate;
}