#pragma once
#include <time.h>

class Goods
{
	public:
		Goods();
		Goods(char* aName, int aGoodsQuantity, int aWCost, int aRCost, time_t* aDate);
		Goods& operator=(Goods aGoods);
		Goods operator++(int);
		Goods operator--(int);
		friend Goods operator+(int aQuantity, Goods aGoods);
		friend Goods operator+(Goods aGoods, int aQuantity);
		friend Goods operator-(Goods aGoods, int aQuantity);
		operator double();
		static int goodsCount;
		void changeQuantity(int aGoodsQuantity);
		void changeName(char* aName);
		void changeDate(time_t* aDate);
		void toString(char* strGoods);
		void changeWCost(int aWCost);
		void markup(int aMarkup);
		void markdown(int aMarkdown);
		int getMarkup() { return retailCost - wholesaleCost; };
		int getWCost() { return wholesaleCost; };
		int getRCost() { return retailCost; };
		time_t* getDate() { return goodsDate; };
		int getQuantity() { return goodsQuantity; };
	private:
		char* goodsName;
		int goodsQuantity;
		int wholesaleCost;
		int retailCost;
		time_t* goodsDate;
};

