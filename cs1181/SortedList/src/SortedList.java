import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SortedList<E extends Comparable<E>> extends ArrayList<E> {

    public SortedList() {
        super();
    }

    public SortedList(List<E> oldList) {
        super(oldList);
    }

    @Override
    public boolean add(E item) {
        super.add(item);
        Collections.sort(this);
        return true;
    }

    public static void main(String[] args) {
        SortedList<Integer> s = new SortedList<>();
        s.add(5);
        s.add(7);
        s.add(1);
        System.out.println(s);
    }

}
