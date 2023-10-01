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
		m = Integer.parseInt(st.nextToken());
		int k = m;
		int max_length = 0;
		int temp_length = 0;
		int last_update = -1;
		ArrayList<Integer> arr[] = new ArrayList[100001];
		for (int i = 0; i < 100001; i++) {
			arr[i] = new ArrayList<>();
		}
		st = new StringTokenizer(br.readLine()," ");
		ArrayList<Integer> seq = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			arr[num].add(i);
			seq.add(num);
			temp_length++;
			if (arr[num].size() > k){
//				System.out.println("num crash : " + num);
//				System.out.println("index : " + arr[num].get(0));
				temp_length -= (arr[num].get(0) - last_update);
				int next_update = arr[num].get(0);
				for (int rm_i = last_update + 1; rm_i <= next_update; rm_i++) {
					int remove_count_num = seq.get(rm_i);
//					System.out.println("updating idx : " + rm_i);
//					System.out.println("updating remove_count_num : " + remove_count_num);
					int idx = arr[remove_count_num].lastIndexOf(rm_i);
//					System.out.println("removing elm is : " + rm_i);
//					System.out.println("elm is in arr index : " + idx);
					arr[remove_count_num].remove(idx);
				}
				last_update = next_update;
			}
			max_length = Integer.max(max_length, temp_length);
		}
		System.out.println(max_length);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
