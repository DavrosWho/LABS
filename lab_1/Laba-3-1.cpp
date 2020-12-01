#include <iostream>
#include <fstream>
#include "Goods1.h"
using namespace std;

bool testFileTXT(Goods aGoods, Goods bGoods) {
	cout << "Text file:" << endl;
	cout << "Added to file" << endl;
	ofstream fout("data.txt", ios::app);
	if (!fout) {
		return false;
	}
	else {
		fout << aGoods;
		cout << aGoods << endl;
	}
	fout.close();
	cout << endl;

	cout << "Loaded from file" << endl;
	ifstream fin("data.txt");
	if (!fin) {
		return false;
	}
	else {
		fin >> bGoods;
		cout << bGoods << endl;
	}
	fin.close();

	bool error = false;
	if (aGoods.getQuantity() != bGoods.getQuantity()) {
		error = true;
	}
	
	cout << endl;

	if (error) {
		return false;
	}
	else {
		return true;
	}
}

bool testFileDAT(Goods aGoods, Goods bGoods) {
	cout << "Binary file:" << endl;
	cout << "Added to file" << endl;

	ofstream fout("data.dat", ios::binary);
	if (!fout) {
		return false;
	}
	else {
		aGoods.write(fout);
		cout << aGoods << endl;
	}
	fout.close();
	cout << endl;

	cout << "Loaded from file" << endl;
	ifstream fin("data.dat");
	if (!fin) {
		return false;
	}
	else {
		bGoods.read(fin);
		cout << bGoods << endl;
	}
	fin.close();

	bool error = false;
	if (aGoods.getQuantity() != bGoods.getQuantity()) {
		bool error = true;
	}

	cout << endl;

	if (error == true) {
		return false;
	}
	else {
		return true;
	}
}

int main()
{

	ofstream fout("data.txt");
	fout << "";
	fout.close();
	ofstream fout2("data.dat");
	fout2 << "";
	fout2.close();
	char* strGoods = new char[100];
	Goods Goods1;
	Goods Goods2;
	Goods Goods3;

	cout << "Enter goods: ";
	cin >> Goods1;
	cout << "First goods: " << Goods1 << '\n';
	cout << "Second goods: " << Goods2 << "\n\n";
	
	if (testFileTXT(Goods1, Goods2)) {
		cout << "Adding and loading objects from a text file test completed successfully" << endl;
	}
	else {
		cout << "Adding and loading objects from a text file test completed failed" << endl;
	}

	cout << "\n\n";

	if (testFileDAT(Goods1, Goods2)) {
		cout << "Adding and loading objects from a text file test completed successfully" << '\n';
	}
	else {
		cout << "Adding and loading objects from a text file test completed failed" << '\n';
	}

	cout << '\n';

	cout << "Text-output-test. Third goods: " << Goods3 << '\n'; 

	cout << Goods::goodsCount << " unique goods are stored in the warehouse.";
}
