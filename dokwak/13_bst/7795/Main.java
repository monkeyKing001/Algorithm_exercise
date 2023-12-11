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
			if (arr.get(mid) >= key)
				right = mid - 1;
			else{
				idx = mid;
				left = mid + 1;
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
		int T = n;
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			int a_num = Integer.parseInt(st.nextToken());
			int b_num = Integer.parseInt(st.nextToken());
			ArrayList<Integer> a = new ArrayList<>();
			ArrayList<Integer> b = new ArrayList<>();
			st = new StringTokenizer(br.readLine()," ");
			for (int i = 0; i < a_num; i++) {
				int num = Integer.parseInt(st.nextToken());
				a.add(num);
			}
			st = new StringTokenizer(br.readLine()," ");
			for (int i = 0; i < b_num; i++) {
				int num = Integer.parseInt(st.nextToken());
				b.add(num);
			}
			a.sort(Comparator.naturalOrder());
			b.sort(Comparator.naturalOrder());
			int count = 0;
			for (int i = 0; i < a.size(); i++) {
				int aFishSize = a.get(i);
				count += bstUpperBound(b, aFishSize) + 1;
			}
			sb.append(count + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


