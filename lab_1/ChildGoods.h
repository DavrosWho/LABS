#pragma once
#include "Goods1.h"
class ChildGoods :
    public Goods
{
public:
	ChildGoods();
	ChildGoods(char* aName, int aGoodsQuantity, int aWCost, int aRCost, time_t* aDate, int aCategory, int aType);
	char* toString() override;
	int getCategory() { return category; };
	friend std::ostream& operator << (std::ostream& out, ChildGoods& aGoods);
private:
	int category;
	int type;
};

