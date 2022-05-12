package SalesTaxes.product;

public class Product {

    private static final double ROUND_UP_FACTOR = 0.05;
    private static final double SALES_TAX = 0.10;
    private static final double IMPORT_DUTY = 0.05;

    public static enum Type {
        FOOD, MEDICINE, BOOK, OTHER;
    }

    public static enum Origin {
        DOMESTIC, IMPORT;
    }

    private static double roundUpToNearest_0_05(double value) {
        return Math.ceil(value / ROUND_UP_FACTOR) * ROUND_UP_FACTOR;
    }

    //Pseudobarcode for demonstration purposes only.
    private final int barcode = (int) (Math.random() * Integer.MAX_VALUE);
    private final String description;
    private final double price;
    private final Type type;
    private final Origin origin;

    public Product(String description, double price, Type type, Origin origin) {
        this.description = description;
        this.price = price;
        this.type = type;
        this.origin = origin;
    }

    public double getSalesTax() {
        return (type == Type.OTHER) ? roundUpToNearest_0_05(price * SALES_TAX) : 0;
    }

    public double getImportDuty() {
        return (origin == Origin.IMPORT) ? roundUpToNearest_0_05(price * IMPORT_DUTY) : 0;
    }

    public int getBarcode() {
        return barcode;
    }

    public String getDescription() {
        return description;
    }

    public double getPrice() {
        return price;
    }

    public Type getType() {
        return type;
    }

    public Origin getOrigin() {
        return origin;
    }
}
