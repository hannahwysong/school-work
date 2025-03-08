import java.util.Iterator;

public class SingleLinkedList<E> implements Iterable{
    // methods to add:
    // removeFirst()
    //removeLast()
    
    private Node<E> head;
    private Node<E> tail;
    private int count;

    public SingleLinkedList() {
        head = null;
        tail = null;
    }

    public boolean addFirst(E item) {
        // add to an empty list
        if (head == null) {
            head = new Node<E>(item);
            tail = head;
        }
        // add to a non-empty list
        else {
            Node<E> newNode = new Node<E>(item);
            newNode.next = head;
            head = newNode;
        }
        count++;
        return true;
    }

    public boolean addLast(E item) {
        // add to an empty list
        if (head == null) {
            head = new Node<E>(item);
            tail = head;
        }
        else {
            // find the last list element
            tail.next = new Node<E>(item);
            tail = tail.next;
        }
        count++;
        return true;
    }
    
    public void add(int index, E value) {
        if ((index <0) || (index > count)) {
            throw new IndexOutOfBoundsException("Index out of bounds in ");
        }

        // special case 1: first item
        if (index == 0) {
            this.addFirst(value);
            return;
        }

        // special case 2: last item
        if (index == count) {
            this.addLast(value);
            return;
        }

        // general case: before insertion point
        Node<E> current = head;
        for (int i = 0; i < index; i++){
            current = current.next;
        }

        // insert new node
        Node<E> newNode = new Node<E>(value);
        newNode.next = current.next;
        current.next = newNode;
        count++;
    }

    public String toString() {
        String result = "[";
        Node<E> current = head;
        while (current != null) {
            result += current.item.toString();
            current = current.next;
            if (current != null) {
                result += ", ";
            }
        }
        result += "]";
        return result; 
    }
    class Node<E> {
        public E item;
        public Node<E> next;
        public Node(E newItem) {
            item = newItem; 
            next = null;
        }
        

    }
    @Override
    public Iterator iterator() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'iterator'");
    }
}
