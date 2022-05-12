

class Basket {

    constructor() {
        this.data = null;
        this.content = [];
    }

    addProduct(product, quantity) {
        let totalPrice = quantity * product.price;
        let totalTaxes = quantity * product.getSalesTax() + quantity * product.getImportDuty();
        this.content.push(new Data(quantity, product, totalPrice, totalTaxes));
    }

    removeProduct(product) {
        for (let i = 0; i < this.content.length; ++i) {
            if (this.content[i].product.barcode === product.barcode) {
                this.content.splice(i, 1);
            }
        }
    }

    printReceipt() {
        let totalSalesTaxes = 0;
        let totalSalesPrices = 0;

        for (let data of this.content) {
            totalSalesTaxes += data.totalTaxes;
            totalSalesPrices += data.totalPrice;

            let line = [];
            line.push("> ");
            line.push(data.quantity);
            line.push(" ");
            line.push(data.product.description);
            line.push(": ");
            line.push((data.totalPrice + data.totalTaxes).toFixed(2));

            console.log(line.join(''));
        }

        console.log("> " + "Sales Taxes: " + (totalSalesTaxes).toFixed(2));
        console.log("> " + "Total: " + (totalSalesPrices + totalSalesTaxes).toFixed(2));
        console.log();
    }
}

class Data {
    constructor(quantity, product, totalPrice, totalTaxes) {
        this.quantity = quantity;
        this.product = product;
        this.totalPrice = totalPrice;
        this.totalTaxes = totalTaxes;
    }
}


class Product {

    constructor(description, price, type, origin) {

        this.ROUND_UP_FACTOR = 0.05;
        this.SALES_TAX = 0.10;
        this.IMPORT_DUTY = 0.05;
        this.Type = {FOOD: false, MEDICINE: false, BOOK: false, OTHER: false};
        this.Origin = {DOMESTIC: false, IMPORT: false};

        //Pseudobarcode for demonstration purposes only.
        this.barcode = Math.random() * Number.MAX_SAFE_INTEGER;
        this.description = description;
        this.price = price;
        this.type = type;
        this.origin = origin;
        this.Type[this.type] = true;
        this.Origin [this.origin] = true;
    }

    roundUpToNearest_0_05(value) {
        return Math.ceil(value / this.ROUND_UP_FACTOR) * this.ROUND_UP_FACTOR;
    }

    getSalesTax() {
        return (this.Type[this.type] === this.Type.OTHER) ? this.roundUpToNearest_0_05(this.price * this.SALES_TAX) : 0;
    }

    getImportDuty() {
        return (this.Origin[this.origin] === this.Origin.IMPORT) ? this.roundUpToNearest_0_05(this.price * this.IMPORT_DUTY) : 0;
    }
}

//////////////////////////
////// Demonstration //////
//////////////////////////

//////////////////////////
////// First Basket //////
//////////////////////////

const basket_01 = new Basket();

let product = new Product("book", 12.49, 'BOOK', 'DOMESTIC');
let quantity = 1;
basket_01.addProduct(product, quantity);

product = new Product("music CD", 14.99, 'OTHER', 'DOMESTIC');
quantity = 1;
basket_01.addProduct(product, quantity);

product = new Product("chocolate bar", 0.85, 'FOOD', 'DOMESTIC');
quantity = 1;
basket_01.addProduct(product, quantity);

basket_01.printReceipt();

//////////////////////////
////// Second Basket //////
//////////////////////////

const basket_02 = new Basket();

product = new Product("imported box of chocolates", 10.00, 'FOOD', 'IMPORT');
quantity = 1;
basket_02.addProduct(product, quantity);

product = new Product("imported bottle of perfume", 47.50, 'OTHER', 'IMPORT');
quantity = 1;
basket_02.addProduct(product, quantity);

basket_02.printReceipt();

//////////////////////////
////// Third Basket //////
//////////////////////////

const basket_03 = new Basket();

product = new Product("imported bottle of perfume", 27.99, 'OTHER', 'IMPORT');
quantity = 1;
basket_03.addProduct(product, quantity);

product = new Product("bottle of perfume", 18.99, 'OTHER', 'DOMESTIC');
quantity = 1;
basket_03.addProduct(product, quantity);

product = new Product("packet of headache pills", 9.75, 'MEDICINE', 'DOMESTIC');
quantity = 1;
basket_03.addProduct(product, quantity);
let storeProductToCheckRemoval = product;

product = new Product("box of imported chocolates", 11.25, 'FOOD', 'IMPORT');
quantity = 1;
basket_03.addProduct(product, quantity);

basket_03.printReceipt();


basket_03.removeProduct(storeProductToCheckRemoval);

console.log("After removing product: " + storeProductToCheckRemoval.description);
basket_03.printReceipt();