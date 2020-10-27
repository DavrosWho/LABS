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

	char aDate[11] = "01.01.2001";
	goodsDate = new char[11];
	for (int i = 0; i < 11; i++) {
		goodsDate[i] = aDate[i];
	}
}

Goods::Goods(char* aName, int aWCost, int aRCost, int aGoodsQuantity, char* aDate) {
	goodsCount++;
	goodsName = new char[15];
	for (int i = 0; i < 5; i++) {
		goodsName[i] = aName[i];
	}
	goodsQuantity = aGoodsQuantity;
	wholesaleCost = aWCost;
	retailCost = aRCost;

	goodsDate = new char[11];
	for (int i = 0; i < 11; i++) {
		goodsDate[i] = aDate[i];
	}
}

Goods &Goods::operator = (const char* aGoods) {
	goodsQuantity = 0;
	wholesaleCost = 0;
	retailCost = 0;
	int check1 = 0, factor = 1, j = 0;
	char* strQuantity = new char[7]; 
	char* strWCost = new char[7];
	char* strRCost = new char[7];
	for (int i = 0; i < 100; i++) {
		if (aGoods[i] == ' ') {
			j = 0;
			check1++;
			if (check1 == 5) {
				for (int k = 6; k >= 0; k--) {
					if (strQuantity[k] > '9' || strQuantity[k] < '0') {

					}
					else {
						goodsQuantity += (strQuantity[k] - '0') * factor;
						factor *= 10;
					}
				}
				factor = 1;
				for (int k = 6; k >= 0; k--) {
					if (strWCost[k] > '9' || strWCost[k] < '0') {

					}
					else {
						wholesaleCost += (strWCost[k] - '0') * factor;
						factor *= 10;
					}
				}
				factor = 1;
				for (int k = 6; k >= 0; k--) {
					if (strRCost[k] > '9' || strRCost[k] < '0') {

					} else {
					retailCost += (strRCost[k] - '0') * factor;
					factor *= 10;
					}
				}
			}
		}
		else if (check1 == 0) {
			goodsName[j] = aGoods[i];
			j++;
		}
		else if (check1 == 1) {
			strQuantity[j] = aGoods[i];
			j++;
		}
		else if (check1 == 2) {
			strWCost[j] = aGoods[i];
			j++;
		}
		else if (check1 == 3) {
			strRCost[j] = aGoods[i];
			j++;
		}
		else if (check1 == 4) {
			goodsDate[j] = aGoods[i];
			j++;
		}
	}
	return *this;
}

Goods  Goods::operator++(int) {
	int check = 0, factor = 1, j = 0, day1 = 0, month1 = 0, year1  = 0;
	char* day = new char[3];
	char* month = new char[3];
	char* year = new char[5];
	for (int i = 0; i < 10; i++) {
		if (goodsDate[i] == '.') {
			j = 0;
			check++;
		}
		else if (check == 0) {
			day[j] = goodsDate[i];
			j++;
		}
		else if (check == 1) {
			month[j] = goodsDate[i];
			j++;
		}
		else if (check == 2 && i == 9) {
			year[j] = goodsDate[i];
			j++;
			for (int k = 1; k >= 0; k--) {
				day1 += (day[k] - '0') * factor;
				factor *= 10;
			}
			factor = 1;
			for (int k = 1; k >= 0; k--) {
				month1 += (month[k] - '0') * factor;
				factor *= 10;
			}
			factor = 1;
			for (int k = 3; k >= 0; k--) {
				year1 += (year[k] - '0') * factor;
				factor *= 10;
			}
		}
		else if (check == 2) {
			year[j] = goodsDate[i];
			j++;
		}
	}

	if (day1 == 31 && month1 == 12) {
		year1++;
		goodsDate[0] = '0';
		goodsDate[1] = '1';
		goodsDate[2] = '.';
		goodsDate[3] = '0';
		goodsDate[4] = '1';
		goodsDate[5] = '.';
		for (int j = 9; j >= 6; j--) {
			goodsDate[j] = year1 % 10 + '0';
			year1 = year1 / 10;
		}
	}
	else if (day1 == 31 && month1 < 12) {
		month1++;
		goodsDate[0] = '0';
		goodsDate[1] = '1';
		goodsDate[2] = '.';
		goodsDate[5] = '.';
		if (month1 < 10) {
			goodsDate[3] = '0';
			goodsDate[4] = month1 + '0';
		}
		else {
			for (int j = 4; j >= 3; j--) {
				goodsDate[j] = month1 % 10 + '0';
				month1 = month1 / 10;
			}
		}
		for (int j = 9; j >= 6; j--) {
			goodsDate[j] = year1 % 10 + '0';
			year1 = year1 / 10;
		}
	}
	else {
		day1++;
		if (day1 < 10) {
			goodsDate[0] = '0';
			goodsDate[1] = day1 + '0';
		}
		else {
			for (int j = 1; j >= 0; j--) {
				goodsDate[j] = day1 % 10 + '0';
				day1 = day1 / 10;
			}
		}
		goodsDate[2] = '.';
		goodsDate[5] = '.';
		if (month1 < 10) {
			goodsDate[3] = '0';
			goodsDate[4] = month1 + '0';
		}
		else {
			for (int j = 4; j >= 3; j--) {
				goodsDate[j] = month1 % 10 + '0';
				month1 = month1 / 10;
			}
		}
		for (int j = 9; j >= 6; j--) {
			goodsDate[j] = year1 % 10 + '0';
			year1 = year1 / 10;
		}
	}

	return *this;
}

Goods  Goods::operator--(int) {
	int check = 0, factor = 1, j = 0, day1 = 0, month1 = 0, year1 = 0;
	char* day = new char[3];
	char* month = new char[3];
	char* year = new char[5];
	for (int i = 0; i < 10; i++) {
		if (goodsDate[i] == '.') {
			j = 0;
			check++;
		}
		else if (check == 0) {
			day[j] = goodsDate[i];
			j++;
		}
		else if (check == 1) {
			month[j] = goodsDate[i];
			j++;
		}
		else if (check == 2 && i == 9) {
			year[j] = goodsDate[i];
			j++;
			for (int k = 1; k >= 0; k--) {
				day1 += (day[k] - '0') * factor;
				factor *= 10;
			}
			factor = 1;
			for (int k = 1; k >= 0; k--) {
				month1 += (month[k] - '0') * factor;
				factor *= 10;
			}
			factor = 1;
			for (int k = 3; k >= 0; k--) {
				year1 += (year[k] - '0') * factor;
				factor *= 10;
			}
		}
		else if (check == 2) {
			year[j] = goodsDate[i];
			j++;
		}
	}

	if (day1 == 1 && month1 == 1) {
		year1--;
		goodsDate[0] = '3';
		goodsDate[1] = '1';
		goodsDate[2] = '.';
		goodsDate[3] = '1';
		goodsDate[4] = '2';
		goodsDate[5] = '.';
		for (int j = 9; j >= 6; j--) {
			goodsDate[j] = year1 % 10 + '0';
			year1 = year1 / 10;
		}
	}
	else if (day1 == 1 && month1 > 1) {
		month1--;
		goodsDate[0] = '3';
		goodsDate[1] = '1';
		goodsDate[2] = '.';
		goodsDate[5] = '.';
		if (month1 < 10) {
			goodsDate[3] = '0';
			goodsDate[4] = month1 + '0';
		}
		else {
			for (int j = 4; j >= 3; j--) {
				goodsDate[j] = month1 % 10 + '0';
				month1 = month1 / 10;
			}
		}
		for (int j = 9; j >= 6; j--) {
			goodsDate[j] = year1 % 10 + '0';
			year1 = year1 / 10;
		}
	}
	else {
		day1--;
		if (day1 < 10) {
			goodsDate[0] = '0';
			goodsDate[1] = day1 + '0';
		}
		else {
			for (int j = 1; j >= 0; j--) {
				goodsDate[j] = day1 % 10 + '0';
				day1 = day1 / 10;
			}
		}
		goodsDate[2] = '.';
		goodsDate[5] = '.';
		if (month1 < 10) {
			goodsDate[3] = '0';
			goodsDate[4] = month1 + '0';
		}
		else {
			for (int j = 4; j >= 3; j--) {
				goodsDate[j] = month1 % 10 + '0';
				month1 = month1 / 10;
			}
		}
		for (int j = 9; j >= 6; j--) {
			goodsDate[j] = year1 % 10 + '0';
			year1 = year1 / 10;
		}
	}

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

	for (int i = 0; i < 11; i++) {
		if (goodsDate[i] == '\0') {
			break;
		}
		else {
			strGoods[j] = goodsDate[i];
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

void Goods::changeDate(char* aDate) {
	for (int i = 0; i < 15; i++) {
		goodsDate[i] = aDate[i];
	}
}