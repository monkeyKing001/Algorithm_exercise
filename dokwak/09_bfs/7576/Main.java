import java.util.*;
import java.awt.Point;

public class Main{
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int max_step = 0;
		int r, c;
		int unrip = 0;
		Queue<Point> q = new LinkedList<Point>();
		int [][]box = new int[1001][1001];
		int []dr = {0, 1, 0, -1};
		int []dc = {1, 0, -1, 0};
		c = sc.nextInt();
		r = sc.nextInt();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				int temp = sc.nextInt();
				box[i][j] = temp;
				if (temp == 0)
					unrip++;
				else if (temp == 1)
				{
					q.add(new Point(i, j));
					max_step = 1;
				}
			}
		}
		while (q.size() != 0)
		{
			int c_r = q.peek().x;
			int c_c = q.peek().y;
			int c_step = box[c_r][c_c];
			q.poll();
			if (c_step > max_step)
				max_step = c_step;
			for (int i = 0; i < 4; i++)
			{
				int n_r = c_r + dr[i];
				int n_c = c_c + dc[i];
				int n_step = c_step + 1;
				if (n_r > -1 && n_r < r && n_c > -1 && n_c < c && box[n_r][n_c] == 0)
				{
					q.add(new Point(n_r, n_c));
					box[n_r][n_c] = n_step;
					unrip--;
				}
			}
		}
		if (unrip != 0)
		{
			System.out.println(-1);
			return ;
		}
		System.out.println(max_step - 1);
		return ;
	}
}
