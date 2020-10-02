 
import java.util.Stack; 
  
public class Solution  
{ 
    static int EvalPost(String expr) 
    { 
        Stack<Integer> stk=new Stack<>(); 
        for(int i=0;i<expr.length();i++) 
        { 
            char c=expr.charAt(i); 
            if(Character.isDigit(c)) 
            stk.push(c - '0'); 
            else
            { 
                int a = stk.pop(); 
                int b = stk.pop(); 
                  
                switch(c) 
                { 
                    case '+': 
                    stk.push(b+a); 
                    break; 
                      
                    case '-': 
                    stk.push(b- a); 
                    break; 
                      
                    case '/': 
                    stk.push(b/a); 
                    break; 
                      
                    case '*': 
                    stk.push(b*a); 
                    break; 
              } 
            } 
        } 
        return stk.pop();     
    } 
    public static void main(String[] args)  
    { 
        String exp="231*+9-"; //Test Case
        System.out.println("postfix evaluation: "+EvalPost(exp)); 
    } 
} 
