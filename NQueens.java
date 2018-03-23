import java.util.*;

class NQueens {
    
    static boolean isAttacked(int board[][], int N, int i, int j) {
        
        int p, q;
        //check column
        for(p = 0; p < N; p++) {
            if(board[p][j] == 1)
                return true;
        }
        //check row
        for(q = 0; q < N; q++) {
            if(board[i][q] == 1)
                return true;
        }
        //check diagonal
        for (p = 0; p < N; p++) {
			for (q = 0; q < N; q++) {
				if ( ((i + j) == (p + q)) || ((i - j) == (p - q)) ) {
					if (((i != p) || (j != q)) && (board[p][q] == 1)) {
						return true;
					}
				}
			}
        }
        return false;
    }
    
    static boolean N_Queens(int[][] board, int level, int N) {
        if(N == level)
            return true;
            
        for(int j = 0; j < N; j++) {
            if(isAttacked(board, N, level, j))
                continue;
            board[level][j] = 1;
            if(N_Queens(board, level+1, N))
                return true;
            board[level][j] = 0;
        }
        return false;
    }
    
    public static void main(String args[] ) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] board = new int[N][N];
        if(N_Queens(board, 0, N)) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }
        }
        else
            System.out.println("Not possible");
    }
}
