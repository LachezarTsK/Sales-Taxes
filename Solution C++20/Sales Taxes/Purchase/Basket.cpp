#include <list>
#include <iterator>
#include <string>
using namespace std;

class Basket {

private:
	struct Data {
		int quantity;
		Product product;
		double totalPrice;
		double totalTaxes;

		Data(int quantity, Product product, double totalPrice, double totalTaxes) :
			quantity{ quantity }, product{ product }, totalPrice{ totalPrice }, totalTaxes{ totalTaxes }{}

		Data() = default;
		virtual ~Data() = default;
	};

public:
	Basket() = default;
	virtual ~Basket() = default;
	list<Data> content;

	void addProduct(Product product, int quantity) {
		double totalPrice = quantity * product.getPrice();
		double totalTaxes = quantity * product.getSalesTax() + quantity * product.getImportDuty();
		content.emplace_back(Data(quantity, product, totalPrice, totalTaxes));
	}

	void removeProduct(Product& product) {
		auto toRemoveCondition = [&](Data data) {return data.product.getBarcode() == product.getBarcode(); };
		content.remove_if(toRemoveCondition);
	}

	void printReceipt() {
		double totalSalesTaxes = 0;
		double totalSalesPrices = 0;

		for (const auto& data : content) {
			totalSalesTaxes += data.totalTaxes;
			totalSalesPrices += data.totalPrice;

			string line;
			line.append("> ")
				.append(to_string(data.quantity))
				.append(" ")
				.append(data.product.getDescription())
				.append(": ")
				.append(format("{2:{0}.{1}f}", 0, 2, (data.totalPrice + data.totalTaxes)));
			cout << line << endl;
		}

		cout << "> " << "Sales Taxes: " << format("{2:{0}.{1}f}", 0, 2, totalSalesTaxes) << endl;
		cout << "> " << "Total: " << format("{2:{0}.{1}f}", 0, 2, (totalSalesPrices + totalSalesTaxes)) << endl;
		cout << endl;
	}
};