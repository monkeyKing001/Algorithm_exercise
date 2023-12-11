import java.util.*; import java.io.*;

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
		int [] rate = new int [n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int [] info = new int[3];
			info[0] = Integer.parseInt(st.nextToken());
			info[1] = Integer.parseInt(st.nextToken());
			info[2] = i;
			arr.add(info);
		}
		for (int i = 0; i < arr.size(); i++) {
			int winner = 0;
			int my_w = arr.get(i)[0];
			int my_h = arr.get(i)[1];
			int my_idx = arr.get(i)[2];
			for (int j = 0; j < arr.size(); j++) {
				if (i != j && (arr.get(j)[0] > my_w && arr.get(j)[1] > my_h))
					winner++;
			}
			rate[my_idx] = winner + 1;
		}
		for (int i = 0; i < rate.length; i++) {
			System.out.print(rate[i] + " ");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


