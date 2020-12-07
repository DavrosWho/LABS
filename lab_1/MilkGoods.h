#pragma once
#include "Goods1.h"
class MilkGoods :
    public Goods
{
public:
	MilkGoods();
	MilkGoods(char* aName, int aGoodsQuantity, int aWCost, int aRCost, time_t* aDate, time_t* aMilkDate);
	void recount();
	time_t* getMilkDate() { return milkDate; };
private:
	time_t* milkDate;
};

