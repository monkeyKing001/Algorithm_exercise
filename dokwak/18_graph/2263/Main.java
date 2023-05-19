import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static StringBuilder sb = new StringBuilder();
	static int []inorder;
	static int []postorder;
	static int [][]arr;
	static int []index;
	public static void rec(int start_inorder, int end_inorder, int start_post, int end_post)
	{
		int mid_idx = index[arr[1][end_post]];
		int left_size = mid_idx - start_inorder;
		int right_size = (end_inorder - mid_idx);
		sb.append(Integer.toString(arr[1][end_post]) + " ");
//		System.out.println("root : " + Integer.toString(arr[1][end_post]));
		if (start_inorder >= end_inorder || start_post >= end_post)
			return ;
//		System.out.println("spliting left tree from " + start_inorder + " to " + (mid_idx - 1));
//		System.out.println("spliting left post_order tree from " + start_post + " to " + (start_post + left_size - 1));
		if (left_size >= 1)
			rec(start_inorder, mid_idx - 1, start_post, start_post + left_size - 1);
//		System.out.println("spliting right tree from " + (mid_idx + 1) + " to " + end_inorder);
//		System.out.println("spliting right post_order tree from " + (start_post + left_size) + " to " + (end_post - 1));
			if (right_size >= 1)
		rec(mid_idx + 1, end_inorder, start_post + left_size, end_post - 1);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		inorder = new int[n + 1];
		postorder = new int[n + 1];
		arr = new int[2][n + 1];
		index = new int[n + 1];
		arr[0] = inorder;
		arr[1] = postorder;
		for (int i = 0; i < 2; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < n; j++) {
				int num;
				num = Integer.parseInt(st.nextToken());
				arr[i][j] = num;
			}
			if (i == 1)
				continue ;
			for (int j = 0; j < n; j++) {
				index[arr[0][j]] = j;
			}
		}
		int root = arr[1][n - 1];
		rec(0, n - 1, 0, n - 1);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
