#pragma once
#include <time.h>
#include <iostream>
#include <fstream>

class Goods
{
	public:
		Goods();
		Goods(char* aName, int aGoodsQuantity, int aWCost, int aRCost, time_t* aDate);
		Goods& operator=(Goods aGoods);
		Goods& operator=(const char* strGoods);
		Goods operator++(int);
		Goods operator--(int);
		Goods operator++();
		Goods operator--();
		friend Goods operator+(int aQuantity, Goods aGoods);
		friend Goods operator+(Goods aGoods, int aQuantity);
		friend Goods operator-(Goods aGoods, int aQuantity);
		operator double();
		friend std::ofstream& operator << (std::ofstream& fout, Goods aGoods);
		friend std::ifstream& operator >> (std::ifstream& fin, Goods& aGoods);
		friend std::ostream& operator << (std::ostream& out, Goods& aGoods);
		friend std::istream& operator >> (std::istream& in, Goods& aGoods);
		void write(std::ofstream& fout);
		void read(std::ifstream& fin);
		static int goodsCount;
		void changeQuantity(int aGoodsQuantity);
		void changeName(char* aName);
		void changeDate(time_t* aDate);
		char* toString();
		void changeWCost(int aWCost);
		void markup(int aMarkup);
		void markdown(int aMarkdown);
		char* getName() { return goodsName; };
		int getMarkup() { return retailCost - wholesaleCost; };
		int getWCost() { return wholesaleCost; };
		int getRCost() { return retailCost; };
		time_t* getDate() { return goodsDate; };
		int getQuantity() { return goodsQuantity; };
		~Goods();
	protected:
		char* goodsName;
		int goodsQuantity;
		int wholesaleCost;
		int retailCost;
		time_t* goodsDate;
};

