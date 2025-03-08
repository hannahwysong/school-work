import java.util.LinkedList;
import java.util.List;

public class App {
    public static void main(String[] args) throws Exception {

        List<Integer> ilist = new LinkedList<>();
        // commonly added to the begining: LinkedList
        // 
        
        SingleLinkedList<String> myList = new SingleLinkedList<>();
        myList.addLast("1");
        myList.addLast("2");
        myList.addLast("3");
        myList.addLast("4");
        myList.add(2, "10");
        myList.add(5, "20");
        System.out.println(myList);
    }
}
