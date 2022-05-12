#include <random>
#include <string>

using namespace std;

enum class Type { FOOD, MEDICINE, BOOK, OTHER };
enum class Origin { DOMESTIC, IMPORT };

class Product {

public:
	Product(string description, double price, Type type, Origin origin) :
		description{ description }, price{ price }, type{ type }, origin{ origin }{}

	Product(const Product& product) :
		description{ product.description }, price{ product.price }, type{ product.type },
		origin{ product.origin }, barcode{ product.barcode }{}

	Product(Product&& product) noexcept :
		description{ move(product.description) }, price{ move(product.price) }, type{ move(product.type) },
		origin{ move(product.origin) }, barcode{ move(product.barcode) }{}

	Product& operator=(const Product& product) {
		description = product.description;
		price = product.price;
		type = product.type;
		origin = product.origin;
		barcode = product.barcode;
		return *this;
	}

	Product& operator=(Product&& product) noexcept {
		description = move(product.description);
		price = move(product.price);
		type = move(product.type);
		origin = move(product.origin);
		barcode = move(product.barcode);
		return *this;
	}

	Product() = default;
	virtual ~Product() = default;

private:
	inline static const double ROUND_UP_FACTOR = 0.05;
	inline static const double SALES_TAX = 0.10;
	inline static const double IMPORT_DUTY = 0.05;

	string description;
	double price;
	Type type;
	Origin origin;

	//Pseudobarcode for demonstration purposes only.
	int barcode = rand();

	static double roundUpToNearest_0_05(double value) {
		return ceil(value / ROUND_UP_FACTOR) * ROUND_UP_FACTOR;
	}

public:
	const double getSalesTax() const {
		return (type == Type::OTHER) ? roundUpToNearest_0_05(price * SALES_TAX) : 0;
	}

	const double getImportDuty() const {
		return (origin == Origin::IMPORT) ? roundUpToNearest_0_05(price * IMPORT_DUTY) : 0;
	}

	const int getBarcode() const {
		return barcode;
	}

	const string getDescription() const {
		return description;
	}

	const double getPrice() const {
		return price;
	}

	const Type getType() const {
		return type;
	}

	const Origin getOrigin() const {
		return origin;
	}
};