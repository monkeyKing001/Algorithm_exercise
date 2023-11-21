import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		int arr[] = new int[n];
		Map<Integer, Integer> m = new HashMap<>();
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			arr[i] = num;
			m.put(num, m.getOrDefault(num, 0));
		}
		Arrays.sort(arr);
		int sol = 0;
		for (int i = 0; i < n; i++) {
			int cur_num = arr[i];
			int l = 0;
			int r = n - 1;
			while (l < r){
				if (l == i) {
					l++;
					continue ;
				}
				if (r == i) {
					r--;
					continue ;
				}
				if (arr[l] + arr[r] > cur_num)
					r--;
				else if (arr[l] + arr[r] < cur_num)
					l++;
				else if (arr[l] + arr[r] == cur_num){
					if (l != i && r != i) {
						sol++;
						break;
					}
				}
			}
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


