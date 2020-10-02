import java.util.*;

public boolean isValid(String s){
        Stack<Character> stack=new Stack<Character>();
        for(char c:s.toCharArray()){
            if(c=='(')
                stack.push(')');
            else if(c=='{')
               stack.push('}');
               else if(c=='[')
               stack.push(']');
               else if(stack.isEmpty()||stack.pop()!=c)
               return false;
        }
               return stack.isEmpty();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            String s = in.next();
                System.out.println(isValid(s) ? "YES":"NO");
        }
    }
