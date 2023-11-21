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
		ArrayList<int[]> arr = new ArrayList<>();
		int last_start = -1;
		int last_end = -1;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int info[] = new int[2];
			info[0] = start;
			info[1] = end;
			arr.add(info);
		}
		arr.sort(new Comparator<int[]>(){
			@Override
			public int compare(int[] info1, int[] info2){
				return (Integer.compare(info1[0], info2[0]));
			}
		});
		int sol = 0;
		for (int i = 0; i < arr.size(); i++) {
			int cur_info[] = arr.get(i);
			int cur_start = cur_info[0];
			int cur_end = cur_info[1];
			if (cur_start >= last_start && cur_end <= last_end)
			{
				last_start = cur_start;
				last_end = cur_end;
			}
			else if (cur_start >= last_end){
//				System.out.println("add new");
//				System.out.println(cur_start);
//				System.out.println(cur_end);
				sol++;
				last_start = cur_start;
				last_end = cur_end;
			}
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
