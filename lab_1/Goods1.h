#pragma once

class Goods
{
		char* goodsName;
		int goodsQuantity;
		int wholesaleCost;
		int retailCost;
		char* goodsDate;
	public:
		Goods();
		Goods(char* aName, int aWCost, int aRCost, int aGoodsQuantity, char* aDate);
		static int goodsCount;
		void ChangeQuantity(int aGoodsQuantity);
		void ChangeName(char* aName);
		void ChangeDate(char* aDate);
		void ToString(char* strGoods);
		void ChangeWCost(int aWCost);
		void Markup(int aMarkup);
		void Markdown(int aMarkdown);
		int GetMarkup() { return retailCost - wholesaleCost; };
		int GetWCost() { return wholesaleCost; };
		int GetRCost() { return retailCost; };
};

