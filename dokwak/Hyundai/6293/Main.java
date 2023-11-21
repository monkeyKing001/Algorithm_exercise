import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static int bstUpperBound(ArrayList<Integer>arr, int key){
		int idx = -1;
		int left = 0;
		int right = arr.size() - 1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (arr.get(mid) < key)
				left = mid + 1;
			else{
				idx = mid;
				right = mid - 1;
			}
		}
		return idx;
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		ArrayList<Integer> sol = new ArrayList<>();
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			int idx = bstUpperBound(sol, num);
			if (sol.size() == 0 || idx < 0){
				sol.add(num);
			}
			else{
				sol.set(idx, num);
			}
		}
		sb.append(sol.size());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
