#pragma warning (disable: 4996)
#include "MilkGoods.h"
#include <iostream>
using namespace std;

MilkGoods::MilkGoods() {
	char aName[15] = "#100";
	goodsName = new char[15];
	for (int i = 0; i < 15; i++) {
		goodsName[i] = aName[i];
	}
	goodsQuantity = 0;
	wholesaleCost = 100;
	retailCost = 100;
	goodsDate = new time_t(500000000);
	milkDate = new time_t(500000000);
}

MilkGoods::MilkGoods(char* aName, int aGoodsQuantity, int aWCost, int aRCost, time_t* aDate, time_t* aMilkDate) {
	goodsName = new char[15];
	for (int i = 0; i < 15; i++) {
		goodsName[i] = aName[i];
	}
	goodsQuantity = aGoodsQuantity;
	wholesaleCost = aWCost;
	retailCost = aRCost;
	goodsDate = aDate;
	milkDate = aMilkDate;
}

void MilkGoods::recount() {
	int64_t tt1 = 604800;
	time_t aaDate1 = *goodsDate;
	time_t aaDate2 = *milkDate;
	if (static_cast<int64_t>(aaDate2) - static_cast<int64_t>(aaDate1) > tt1) {
		retailCost = retailCost / 2;
	}
}

char* MilkGoods::toString() {
	char* strGoods = new char[250];
	int j = 0;
	char text[38] = "Name, quantity, wCost, rCost, dates: ";
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

	for (int i = 0; i < 38; i++, j++) {
		strGoods[j] = text[i];
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

	for (int i = 0; i < 24; i++) {
		if (ctime(milkDate)[i] == '\0') {
			break;
		}
		else {
			strGoods[j] = ctime(milkDate)[i];
			j++;
		}
	}

	for (j; j < strlen(strGoods); j++) {
		strGoods[j] = ' ';
	}

	return strGoods;
}