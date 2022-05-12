package SalesTaxes.purchase;

import SalesTaxes.basket.Basket;
import SalesTaxes.product.Product;

public class Purchase {

    public static void main(String[] args) {

        //////////////////////////
        ////// First Basket //////
        //////////////////////////
        Basket basket_01 = new Basket();

        Product product = new Product("book", 12.49, Product.Type.BOOK, Product.Origin.DOMESTIC);
        int quantity = 1;
        basket_01.addProduct(product, quantity);

        product = new Product("music CD", 14.99, Product.Type.OTHER, Product.Origin.DOMESTIC);
        quantity = 1;
        basket_01.addProduct(product, quantity);

        product = new Product("chocolate bar", 0.85, Product.Type.FOOD, Product.Origin.DOMESTIC);
        quantity = 1;
        basket_01.addProduct(product, quantity);

        basket_01.printReceipt();

        //////////////////////////
        ////// Second Basket //////
        //////////////////////////
        Basket basket_02 = new Basket();

        product = new Product("imported box of chocolates", 10.00, Product.Type.FOOD, Product.Origin.IMPORT);
        quantity = 1;
        basket_02.addProduct(product, quantity);

        product = new Product("imported bottle of perfume", 47.50, Product.Type.OTHER, Product.Origin.IMPORT);
        quantity = 1;
        basket_02.addProduct(product, quantity);

        basket_02.printReceipt();

        //////////////////////////
        ////// Third Basket //////
        //////////////////////////
        Basket basket_03 = new Basket();

        product = new Product("imported bottle of perfume", 27.99, Product.Type.OTHER, Product.Origin.IMPORT);
        quantity = 1;
        basket_03.addProduct(product, quantity);

        product = new Product("bottle of perfume", 18.99, Product.Type.OTHER, Product.Origin.DOMESTIC);
        quantity = 1;
        basket_03.addProduct(product, quantity);

        product = new Product("packet of headache pills", 9.75, Product.Type.MEDICINE, Product.Origin.DOMESTIC);
        quantity = 1;
        basket_03.addProduct(product, quantity);
        Product storeProductToCheckRemoval = product;

        product = new Product("box of imported chocolates", 11.25, Product.Type.FOOD, Product.Origin.IMPORT);
        quantity = 1;
        basket_03.addProduct(product, quantity);

        basket_03.printReceipt();

        basket_03.removeProduct(storeProductToCheckRemoval);

        System.out.println("After removing product: " + storeProductToCheckRemoval.getDescription());
        basket_03.printReceipt();
    }
}
