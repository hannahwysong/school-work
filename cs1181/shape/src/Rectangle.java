public class Rectangle extends Shape {
    int height;
    int width;

    public Rectangle(int x, int y, String color, int height, int width) {
        super(x, y, color);
        // error checking
        this.height = height;
        this.width = width;
    }

    public Rectangle(Rectangle copyMe) {
        super(copyMe.getX(), copyMe.getY(), copyMe.getColor());
        copyMe.height = height;
        copyMe.width = width;
    }

    public void draw() {
        System.out.println("Drawing " + getColor() + "Rectangle at " + getX() + "," + getY());
        System.out.println("  Height: " + height + ", Width: " + width);
    }
}