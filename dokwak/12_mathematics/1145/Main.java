import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static boolean visited[] = new boolean[5];
	public static void rec(int choice, int idx){
		if (choice == 3)
			return;

	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		ArrayList<Integer> arr = new ArrayList<>();
		for (int i = 0; i < 5; i++) {
			n = Integer.parseInt(st.nextToken());
			arr.add(n);
		}
		arr.sort(null);
		int min = arr.get(2) - 1;
		int count = 0;
		while (count < 3 && min++ <= Integer.MAX_VALUE){
			count = 0;
			for (int i = 0; i < 5 && count < 3; i++) {
				if (min % arr.get(i) == 0)
					count++;
			}
		}
		System.out.println(min);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


