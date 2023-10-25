
import java.util.*;
public class GenerateParentheses {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n=3;
		List<String> list=new ArrayList<>();
     generateParentheses(n,0,0,"",list);
     System.out.println(list);
	}
public static void generateParentheses(int n, int open, int close, String ans, List<String> list )
{
	if(open==n&&close==n)
	{
//		System.out.println(ans);
		list.add(ans);
		return;
	}
	if(open<n)
		generateParentheses(n,open+1,close,ans+"(",list);
	if(close<open)
		generateParentheses(n,open,close+1,ans+")",list);
}
}
