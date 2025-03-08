/**
 * Creates a list of specified items.
 */
public class LinkedList {

	private Node head;
	private Node tail;
	
	/**
	 * Adds a new item to the list.
	 * 
	 * @param item String item being item
	 */
	public void add(String item) {
		
		Node newItem = new Node(item);
		
		// handles the case where the new item 
		// is the only thing in the list
		if (head == null) {
			head = newItem;
			tail = newItem;
			return;
		}
		
		tail.next = newItem;
		tail = newItem;
	}
	
	
	/**
	 * Prints the items in the list.
	 */
	public void print() {
		Node current = head;
		while (current != null) {
			System.out.println(current.item);
			current = current.next;
		}
	}
	
	
	/**
	 * Iterates through list and returns the item before the end 
	 * of the list.
	 * 
	 * @return String item before last
	 */
	public String getPenultimate() {
		Node current = head;

		// goes through list
		while (current != null) {
			// checks to see if the next item is last
			if (current.next == tail) {
				// returns item if true
				return current.item;
			}
			// else continues to go through list
			current = current.next;
		}

		// if list is null returns null
		return null;

	}

	
	/**
	 * Node class being used to iterate through items in list
	 */
	class Node {
		String item;
		Node next;
		
		public Node(String item) {
			this.item = item;
			this.next = null;
		}
	}
}
