import java.util.ArrayList;
import java.util.Arrays;

public class RemoveTo {

    public static <T> ArrayList<T> removeTwo(ArrayList<T> list) {
        ArrayList<T> newList = new ArrayList<>();

        if (list.size() > 1) {
            newList.add(list.get(0));
            list.remove(0);
        }

        if (list.size() > 1) {
            newList.add(list.get(0));
            list.remove(0);
        }

        return newList;

    }

    public static void main(String[] args) {
        ArrayList<Integer> list1 = new ArrayList<>(Arrays.asList(3, 5, 7, 15));
        ArrayList<Integer> list2;

        list2 = removeTwo(list1);

        System.out.println(list1);
        System.out.println(list2);
    }
}
