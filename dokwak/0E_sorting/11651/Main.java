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
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int [] info = new int[2];
			info[0] = x;
			info[1] = y;
			arr.add(info);
		}
		arr.sort(new Comparator<int[]>()
				{
					@Override
					public int compare(int[] e1, int []e2)
					{
						if (e1[1] == e2[1])
							return (Integer.compare(e1[0], e2[0]));
						return (Integer.compare(e1[1], e2[1]));
					}
				});
		for (int i = 0; i < arr.size(); i++) {
			sb.append(arr.get(i)[0]);
			sb.append(" ");
			sb.append(arr.get(i)[1]);
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


