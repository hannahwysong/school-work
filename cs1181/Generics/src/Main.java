import java.util.*;

public class Main {

    public static void main(String[] args) {

        int i = 9;
        Integer j = i;
        String s = j.toString();

        LottoBag<Integer> myBag = new LottoBag<>();
        myBag.add(9);
        myBag.add(7);
        myBag.add(11);
        myBag.add(15);

        System.out.println(myBag.draw());
        System.out.println(myBag.draw());
        System.out.println(myBag.draw());
        System.out.println(myBag.draw());

        ArrayList<Integer> myList = new ArrayList<>();
        myList.add(7);
        myList.add(i);
        System.out.println(myList.get(0).getClass());
        System.out.println(myList.get(0) + myList.get(1));

        ArrayList<Integer> list = new ArrayList(Arrays.asList(3, 5, 8, 9, 15));

        Collections.sort(list);
        System.out.println(list);

        printMe("Dick Shit");
        printMe(6.9);
        printMe(420);
        printMe(true);

        Integer smallest = min3(12, 3, 22);
        Double smallestDouble = min3(22.5, 5.7, 0.1);
        System.out.println(smallest);
        System.out.println(smallestDouble);

        Integer values[] = { 1, 2, 3 };
        printArray(values);

        String strings[] = { "One", "Two", "Three" };
        printArray(strings);

        ArrayList<Integer> list2 = new ArrayList<>();
        list2.add(1);
        list2.add(3);
        list2.add(5);
        list2.add(7);

        removeTwo(list2);
        System.out.println(list2);
    }

    public static int foo(int value1, double double2) {
        return value1 + (int) double2;
    }

    // generic method
    public static <T> void printMe(T item) {

        System.out.println("Item to print is: " + item);
    }

    public static <T extends Comparable<T>> T min3(T first, T second, T third) {
        T minval = first;
        if (minval.compareTo(second) > 0) {
            minval = second;
        }
        if (minval.compareTo(third) > 0) {
            minval = third;
        }
        return minval;
    }

    public static <T> void printArray(T theArray[]) {
        System.out.print("[");
        for (int i = 0; i < theArray.length; i++) {
            System.out.print(theArray[i]);
            if (i < theArray.length - 1) {
                System.out.print(" , ");
            }
        }
        System.out.println("]");
    }

    public static <T> void removeTwo(ArrayList<T> list) {

        if (list.size() > 1) {
            list.remove(0);
        }

        if (list.size() > 1) {
            list.remove(0);
        }
    }
}
