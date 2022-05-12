package SalesTaxes.basket;

import SalesTaxes.product.Product;
import java.util.LinkedList;
import java.util.List;

public class Basket {

    private static record Data(int quantity, Product product, double totalPrice, double totalTaxes) {}
    private final List<Data> content = new LinkedList<>();

    public void addProduct(Product product, int quantity) {
        double totalPrice = quantity * product.getPrice();
        double totalTaxes = quantity * product.getSalesTax() + quantity * product.getImportDuty();
        content.add(new Data(quantity, product, totalPrice, totalTaxes));
    }

    public void removeProduct(Product product) {
        for (Data data : content) {
            if (data.product.getBarcode() == product.getBarcode()) {
                content.remove(data);
            }
        }
    }

    public void printReceipt() {
        double totalSalesTaxes = 0;
        double totalSalesPrices = 0;

        for (Data data : content) {
            totalSalesTaxes += data.totalTaxes;
            totalSalesPrices += data.totalPrice;

            StringBuilder line = new StringBuilder()
                    .append("> ")
                    .append(data.quantity)
                    .append(" ")
                    .append(data.product.getDescription())
                    .append(": ")
                    .append(String.format("%.2f", (data.totalPrice + data.totalTaxes)));

            System.out.println(line);
        }

        System.out.println("> " + "Sales Taxes: " + String.format("%.2f", totalSalesTaxes));
        System.out.println("> " + "Total: " + String.format("%.2f", totalSalesPrices + totalSalesTaxes));
        System.out.println();
    }
}
