import java.util.*;
import java.io.*;

public class Main{
	static int n, m;

	public static int bstUpperBound(ArrayList<Long>arr, long key){
		int idx = -1;
		int left = 0;
		int right = arr.size() - 1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (arr.get(mid) > key)
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
		ArrayList<Long> arr = new ArrayList<>();
		int max = 2000000;
		long n = Long.parseLong(st.nextToken());
		for (int i = 0; i < max; i++) {
			long num = (long)i * (long)(i + 1) / 2;
			arr.add(num);
		}
		sb.append(bstUpperBound(arr, n));
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


