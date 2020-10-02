import java.util.*; 
  
public class Solution  
{  
static class Queue  
{  
    static Stack<Integer> stk1 = new Stack<Integer>();  
    static Stack<Integer> stk2 = new Stack<Integer>();  
  
    public void enQueue(int x) {
        while (!stk1.isEmpty()) {
            stk2.push(stk1.pop());
        }

        stk1.push(x);

        while (!stk2.isEmpty()) {
            stk1.push(stk2.pop());
        }
    }

    int deQueue() {
        if (stk1.isEmpty()) {
            System.out.println("Queue is Empty");
            System.exit(0);
        }

        int x = stk1.peek();
        stk1.pop();
        return x;
    }
};

public static void main(String[] args) {
    Queue q = new Queue();
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    System.out.println(q.deQueue());
    System.out.println(q.deQueue()); 
    System.out.println(q.deQueue()); 
}  
}  
