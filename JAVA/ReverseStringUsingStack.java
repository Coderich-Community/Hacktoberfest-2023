import java.util.*;
public class code
{
    public static void main(String[] args) {
        System.out.println(reverseString("hacktoberfest"));
    }
    
    public static String reverseString(String str){
        
        // Initialize an empty stack.
        Stack<Character> st = new Stack<>();
        
        // Traverse the given string from left to right
        for(char ch : str.toCharArray()){
            
            // Push the current character to the stack.
            st.push(ch);
        }
        
        // Initialize an empty StringBuilder
        StringBuilder reverseStr = new StringBuilder();
        
        // Pop from the stack one by one.
        while(!st.isEmpty()){
            
            // Append the current character at the last.
            reverseStr.append(st.pop());
        }
        
        return reverseStr.toString();
    }
}