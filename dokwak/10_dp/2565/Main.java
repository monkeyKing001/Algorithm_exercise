import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static int bstLowerBound(ArrayList<Integer>arr, int key){
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
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
			@Override
			public int compare(int [] e1, int [] e2){
				return (Integer.compare(e1[0], e2[0]));
			}
		});
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int [] info = new int[2];
			info[0] = a;
			info[1] = b;
			pq.add(info);
		}
		ArrayList<Integer> arr = new ArrayList<>();
		while (pq.size() != 0){
			int [] info = pq.poll();
			int target = info[1];
			int idx = bstLowerBound(arr, target);
			if (idx == - 1){
				arr.add(target);
			}
			else{
				arr.set(idx, target);
			}
		}
		int sol = n - arr.size();
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


