import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> arr;
	static int find_smallest_bigger_index(int number){
		int ret = -1;
		int l = 0;
		int r = arr.size() - 1;
		int mid = (l + r) / 2;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if (arr.get(mid) < number)
				l = mid + 1;
			else{
				r = mid - 1;
				ret = mid;
			}
		}
		return(ret);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		arr = new ArrayList<>();
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			int find_index = find_smallest_bigger_index(num);
			if (find_index == -1)
				arr.add(num);
			else
				arr.set(find_index, num);
		}
		System.out.println(arr.size());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


