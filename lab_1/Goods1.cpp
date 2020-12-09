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
}

Goods& Goods::operator = (const char* strGoods) {
	int counter = 0, j = 0, intDate = 0;
	char strQuantity[7] = "1";
	char strRCost[7] = "1";
	char strWCost[7] = "1";
	char strDate[20] = "1";
	for (int i = 0; i < strlen(strGoods); i++) {
		if (strGoods[i] == '/') {
			if (counter == 0) {
				goodsName[i] = '\0';
			}
			counter++;
			j = 0;
		}
		else if (strGoods[i] == '\0') {
			break;
		}
		else if (counter == 0) {
			goodsName[i] = strGoods[i];
		}
		else if (counter == 1) {
			strQuantity[j] = strGoods[i];
			j++;
		}
		else if (counter == 2) {
			strWCost[j] = strGoods[i];
			j++;
		}
		else if (counter == 3) {
			strRCost[j] = strGoods[i];
			j++;
		}
		else if (counter == 4) {
			strDate[j] = strGoods[i];
			j++;
		}
	}

	int n = 1; 
	goodsQuantity = 0;
	for (int i = 6; i >= 0; i--) {
		if (strQuantity[i] >= '0' && strQuantity[i] <= '9') {
			goodsQuantity += (strQuantity[i] - '0') * n;
			n *= 10;
		} else {

		}
	}

	n = 1;
	wholesaleCost = 0;
	for (int i = 6; i >= 0; i--) {
		if (strWCost[i] >= '0' && strWCost[i] <= '9') {
			wholesaleCost += (strWCost[i] - '0') * n;
			n *= 10;
		}
		else {

		}
	}

	n = 1;
	retailCost = 0;
	for (int i = 6; i >= 0; i--) {
		if (strRCost[i] >= '0' && strRCost[i] <= '9') {
			retailCost += (strRCost[i] - '0') * n;
			n *= 10;
		}
		else {

		}
	}

	n = 1;
	for (int i = 19; i >= 0; i--) {
		if (strDate[i] >= '0' && strDate[i] <= '9') {
			intDate += (strDate[i] - '0') * n;
			n *= 10;
		}
		else {

		}
	}
	goodsDate = new time_t(intDate);

	return *this;
}

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

Goods Goods::operator++() {
	(*this)++;
	return *this;
}

Goods Goods::operator--() {
	(*this)--;
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
	return (double)retailCost;
}

char* Goods::toString() {
	char* strGoods = new char[250];
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

std::ofstream& operator << (std::ofstream& fout, Goods aGoods) {
	fout << aGoods.getName() << '/' << aGoods.getQuantity() << '/' << aGoods.getWCost() << '/'
		<< aGoods.getRCost() << '/' << *(int64_t*)aGoods.getDate();
	return fout;
}

std::ifstream& operator >> (std::ifstream& fin, Goods& aGoods) {
	char* strGoods = new char[100];
	fin >> strGoods;
	aGoods = strGoods;
	return fin;
}

std::ostream& operator << (std::ostream& out, Goods aGoods) {
	char* str = new char[242];
	str = aGoods.toString();
	out << str;
	return out;
}

std::istream& operator >> (std::istream& in, Goods& aGoods) {
	char* strGoods = new char[100];
	in >> strGoods;
	aGoods = strGoods;
	return in;
}

void Goods::write(std::ofstream& fout) {
	fout.write((char*)&goodsName, sizeof(goodsName));
	fout.write((char*)&goodsQuantity, sizeof(goodsQuantity));
	fout.write((char*)&wholesaleCost, sizeof(wholesaleCost));
	fout.write((char*)&retailCost, sizeof(retailCost));
	fout.write((char*)&goodsDate, sizeof(goodsDate));
}

void Goods::read(std::ifstream& fin) {
	char* strGoods = new char;
	fin.read((char*)&strGoods, sizeof(strGoods));
	goodsName = strGoods;
	fin.read((char*)&strGoods, sizeof(strGoods));
	goodsQuantity = (int)strGoods;
	fin.read((char*)&strGoods, sizeof(strGoods));
	wholesaleCost = (int)strGoods;
	fin.read((char*)&strGoods, sizeof(strGoods));
	retailCost = (int)strGoods;
	fin.read((char*)&strGoods, sizeof(strGoods));
	goodsDate = (time_t*)strGoods;
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