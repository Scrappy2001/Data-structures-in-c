// Java program to reverse the num using a stack 
import java.util.Stack; 
import java.util.*;
  
public class StackProgram 
{ 
    // Stack to maintain order of digits 
    static Stack<Integer> st= new Stack<>(); 
  
    // Function to push digits into stack 
    static void push_digits(int num) 
    { 
        while(num != 0) 
        { 
            st.push(num % 10); 
            num = num / 10; 
        } 
    } 
  
    // Function to reverse the num 
    static int reverse_num(int num) 
    { 
        // Function call to push num's 
        // digits to stack 
        push_digits(num); 
        int reverse = 0; 
        int i = 1; 
  
        // Popping the digits and forming 
        // the reversed num 
        while (!st.isEmpty()) 
        { 
            reverse = reverse + (st.peek() * i); 
            st.pop(); 
            i = i * 10; 
        } 
  
        // Return the reversed num formed 
        return reverse; 
    } 
  
    // Driver program to test above function 
    public static void main(String[] args) 
    { 
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt(); 
        System.out.println(reverse_num(num)); 
    } 
} 
