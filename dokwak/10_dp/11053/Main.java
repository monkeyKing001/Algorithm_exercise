import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void update(ArrayList<Integer> bst, int target)
	{
		int start, mid, end;
		int back_up = 0;
		start = 0;
		end = bst.size() - 1;
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (bst.get(mid) < target)
			{
				start = mid + 1;
			}
			else if (bst.get(mid) >= target)
			{
				back_up = mid;
				end = mid - 1;
			}
		}
		bst.set(back_up, target);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		int [] arr = new int [n + 1];
		ArrayList<Integer> bst = new ArrayList<>();
		st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < n; i++) {
			int num = arr[i];
			if (bst.size() != 0 && bst.get(bst.size() - 1) >= num)
				update(bst, num);
			else
				bst.add(num);
		}
		System.out.println(bst.size());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
