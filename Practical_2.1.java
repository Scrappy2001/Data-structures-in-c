import java.util.Stack; 
  
class Solution 
{ 
    static int Hode(char ch) 
    { 
        switch (ch) 
        { 
        case '+': 
        case '-': 
            return 1; 
       
        case '*': 
        case '/': 
            return 2; 
       
        case '^': 
            return 3; 
        } 
        return -1; 
    }   
    static String infToPost(String expr) 
    { 
        String res = new String(""); 
          
        Stack<Character> stk = new Stack<>(); 
          
        for (int i = 0; i<expr.length(); ++i) 
        { 
            char c = expr.charAt(i); 
            if (Character.isLetterOrDigit(c)) 
                res += c; 
            else if (c == '(') 
                stk.push(c); 
              
            else if (c == ')') 
            { 
                while (!stk.isEmpty() && stk.peek() != '(') 
                    res += stk.pop(); 
                  
                if (!stk.isEmpty() && stk.peek() != '(') 
                    return " Expression is not Valid";           
                else
                    stk.pop(); 
            } 
            else 
            { 
                while (!stk.isEmpty() && Hode(c) <= Hode(stk.peek())){ 
                    if(stk.peek() == '(') 
                        return " Expression is not Valid"; 
                    res += stk.pop(); 
             } 
                stk.push(c); 
            } 
       
        } 
        while (!stk.isEmpty()){ 
            if(stk.peek() == '(') 
                return " Expression is not Valid"; 
            res += stk.pop(); 
         } 
        return res; 
    } 
    
    public static void main(String[] args)  
    { 
        String exp = "a+b*(c^d-e)^(f+g*h)-i"; // TEst Case
        System.out.println(infToPost(exp)); 
    } 
} 
