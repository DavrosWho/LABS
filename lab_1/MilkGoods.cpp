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
	toString(getStr());
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
	toString(getStr());
}

void MilkGoods::recount() {
	int64_t tt1 = 604800;
	time_t aaDate1 = *goodsDate;
	time_t aaDate2 = *milkDate;
	if (static_cast<int64_t>(aaDate2) - static_cast<int64_t>(aaDate1) > tt1) {
		retailCost = retailCost / 2;
	}
}