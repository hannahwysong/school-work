import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

/**
 * TileGame class that creates a game from a stack and a queue. Changes the 
 * value based on the top of the stack.
 * 
 * @author Hannah Wysong
 */
public class TileGame {

    /**
     * Game method. Checks stack, if empty returns zero, if not it goes through
     * the stack until there is nothing left. If the top of the stack is a 1 it
     * pops another item from the stack. If the top is a 2 it pops two items from
     * the stack. If the top of the stack is 3 it pops the top of the stack and 
     * adds 3 items from the queue. 
     * 
     * @param stack stack of ints 1 to 3
     * @param q queue of ints 1 to 3
     * @return number of turns
     */
    public static int tileGame(ArrayDeque<Integer> stack, Queue<Integer> q) {
        int count = 0; 
        // base case
        while (!stack.isEmpty()) {
            if (stack.size() == 0) {
                // if list is empty retuns 0
               break; 
            }
            else {
                // pops the top of the stack
                int top = stack.pop();
            if (top == 1) {
                // pops another off the stack if one exists
                if (stack.size() >= 1){
                    stack.pop();
                    count++;
                }
                else {
                    // otherwise increases the turn count
                    count++;
                    break;
                }
                
            }

            else if (top == 2) {
                if (stack.size() >= 2) {
                    // pops two off the stack if it exists
                    stack.pop();
                    stack.pop();
                    count++;
                }
                else {
                    // increses the count if not
                    count++;
                    break;
                }
            }
            else if (top == 3) {
                if (q.size() >= 1) {
                    // pops one off the stack and pushes 3 items from the queue
                    stack.pop();
                    stack.push(q.remove());
                    stack.push(q.remove());
                    stack.push(q.remove());
                    count++;
                }
                else {
                    //increases the count if nothing exists
                    count++;
                    break;
                }
            }
        }
    }
        return count;
        
    }

    /**
     * Main method for TileGame class. Creates a queue with 10 items. 
     * As well as a stack with four elements. All of the elements are in 
     * a range of 1 to 3.
     * @param args
     */
    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();
        ArrayDeque<Integer> stack = new ArrayDeque<>();

        // fills queue
        for (int i = 0; i < 10; i++) {
            // picks value between 3 and 1
            int num = (int) ((Math.random() * (4 - 1)) + 1);
            q.offer(num);
        }
        // fills stack 
        for (int i = 0; i < 4; i++) {
            int num = (int) ((Math.random() * (4 - 1)) + 1);
            stack.add(num);
        }

        // returns number of turns
        int turnCount = tileGame(stack, q);
        System.out.println("Amount of turns: " + turnCount);
    }
}
