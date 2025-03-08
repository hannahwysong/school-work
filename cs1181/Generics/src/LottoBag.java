import java.util.*;

public class LottoBag<E> {
    private ArrayList<E> contents = new ArrayList<>();
    private Random rng;

    LottoBag() {
        contents = new ArrayList<E>();
        rng = new Random();
    }

    public void add(E item) {
        contents.add(item);
    }

    public E draw() throws RuntimeException {
        if (contents.size() < 1) {
            throw new RuntimeException("Cannot draw from empty bag");
        }
        int index = rng.nextInt(contents.size());
        E selectedObject = contents.remove(index);
        return selectedObject;
    }
}
