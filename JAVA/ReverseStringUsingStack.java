import java.util.Stack;

public class ReverseStringUsingStack {
    public static String reverseString(String input) {
        Stack<Character> stack = new Stack<>();
        
        // Push each character onto the stack
        for (char c : input.toCharArray()) {
            stack.push(c);
        }
        
        // Pop characters from the stack to reverse the order
        StringBuilder reversedString = new StringBuilder();
        while (!stack.isEmpty()) {
            reversedString.append(stack.pop());
        }
        
        return reversedString.toString();
    }

    public static void main(String[] args) {
        String input = "Hello, World!";
        String reversed = reverseString(input);
        System.out.println("Original string: " + input);
        System.out.println("Reversed string: " + reversed);
    }
}
