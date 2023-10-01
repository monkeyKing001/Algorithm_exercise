import java.util.*;
import java.io.*;

public class Main{
	static ArrayList<Integer> buf = new ArrayList<>();
	static int n, m;

	public static void printBuf(){
		for (int i = 0; i < buf.size(); i++) {
			System.out.print(buf.get(i) + " ");
		}
		System.out.println();
	}
	public static void rec(int cur_idx){
		if (n == cur_idx + 1){
			printBuf();
			return ;
		}
		for (int next_num = 1; next_num < n  + 1; next_num++) {
			if (buf.contains(next_num) == false)
			{
//				System.out.println("index : " + (cur_idx + 1)  + ", adding num : " + next_num);
				buf.add(next_num);
				rec(cur_idx + 1);
				buf.remove(cur_idx + 1);
			}
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		buf = new ArrayList<>();
		for (int i = 1; i < n + 1; i++) {
//			System.out.println("index 0, adding num : " + i);
			buf.add(i);
			rec(0);
			buf.remove(0);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
