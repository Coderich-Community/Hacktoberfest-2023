

public class NQueens {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n=4;
     boolean[][] board=new boolean[n][n];
     System.out.println(queens(board,0,0));
	}
 public static int queens(boolean[][] board, int row, int col)
 {
	 if(row==board.length)
	 {
//		 display(board);
//		 System.out.println();
		 return 1;
	 }
	 int count=0;
	 //placing the queen and checking for every row and column
	 for(col=0;col<board[0].length;col++)
	 {
		if(isSafe(board,row,col)) 
		{
			board[row][col]=true;
			count+=queens(board,row+1,col);
			board[row][col]=false; //backtracking when the function is over
		}	
	 }
	 return count;
 }
 public static boolean isSafe(boolean[][] board, int row, int col)
 {
	 //for vertical column
	 for(int i=0;i<row;i++)
	 {
		 if(board[i][col])
			 return false;
	 }
	 //for left diagonal
	 int maxLeft=Math.min(row, col);
	 for(int i=1;i<=maxLeft;i++)
	 {
		 if(board[row-i][col-i])
			 return false;
	 }
	 //for right diagonal
	 int maxRight=Math.min(row,board.length-col-1);
	 for(int i=1;i<=maxRight;i++)
	 {
		 if(board[row-i][col+i])
			 return false;
	 }
	 return true;
 }
 public static void display(boolean[][] board)
 {
	 for(boolean[] row: board)
	 {
		 for(boolean element: row)
		 {
			 if(element)
				 System.out.print("Q"+" ");
			 else
				 System.out.print("X"+" ");
		 }
		 System.out.println();
	 }
 }
}
