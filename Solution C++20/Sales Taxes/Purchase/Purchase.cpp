#include <iostream>
#include <iterator>
#include <iomanip>
#include <format>
#include <sstream>
#include "HeaderFile.h"

using namespace std;

int main()
{

	//////////////////////////
	////// First Basket //////
	//////////////////////////
	Basket basket_01;

	Product product("book", 12.49, Type::BOOK, Origin::DOMESTIC);
	int quantity = 1;
	basket_01.addProduct(product, quantity);

	product = Product("music CD", 14.99, Type::OTHER, Origin::DOMESTIC);
	quantity = 1;
	basket_01.addProduct(product, quantity);

	product = Product("chocolate bar", 0.85, Type::FOOD, Origin::DOMESTIC);
	quantity = 1;
	basket_01.addProduct(product, quantity);

	basket_01.printReceipt();

	//////////////////////////
	////// Second Basket //////
	//////////////////////////
	Basket basket_02;

	product = Product("imported box of chocolates", 10.00, Type::FOOD, Origin::IMPORT);
	quantity = 1;
	basket_02.addProduct(product, quantity);

	product = Product("imported bottle of perfume", 47.50, Type::OTHER, Origin::IMPORT);
	quantity = 1;
	basket_02.addProduct(product, quantity);

	basket_02.printReceipt();

	//////////////////////////
	////// Third Basket //////
	//////////////////////////
	Basket basket_03;

	product = Product("imported bottle of perfume", 27.99, Type::OTHER, Origin::IMPORT);
	quantity = 1;
	basket_03.addProduct(product, quantity);

	product = Product("bottle of perfume", 18.99, Type::OTHER, Origin::DOMESTIC);
	quantity = 1;
	basket_03.addProduct(product, quantity);

	product = Product("packet of headache pills", 9.75, Type::MEDICINE, Origin::DOMESTIC);
	quantity = 1;
	basket_03.addProduct(product, quantity);
	Product storeProductToCheckRemoval = product;

	product = Product("box of imported chocolates", 11.25, Type::FOOD, Origin::IMPORT);
	quantity = 1;
	basket_03.addProduct(product, quantity);

	basket_03.printReceipt();

	basket_03.removeProduct(storeProductToCheckRemoval);

	cout << "After removing product: " << storeProductToCheckRemoval.getDescription() << endl;
	basket_03.printReceipt();
}
