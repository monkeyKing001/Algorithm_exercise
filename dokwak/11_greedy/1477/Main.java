import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> position = new ArrayList<>();

	public static boolean validCheck(int interval){
		int stationNum = m;
//		System.out.println("try : " + interval);
		for (int i = 1; i < position.size(); i++) {
			int start = position.get(i - 1);
			int end = position.get(i);
			int curInterval = end - start;
//			System.out.println("start, end, curInterval : " + start + ", "+ end + ", " + curInterval);
			stationNum -= (curInterval  - 1)/ interval;
//			System.out.println("subtracting : " + (curInterval  - 1)/ interval);
			if (stationNum < 0)
				return false;
		}
		return true;
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int l = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		position.add(0);
		for (int i = 0; i < n; i++) {
			int pos = Integer.parseInt(st.nextToken());
			position.add(pos);
		}
		position.add(l);
		int r = l - 1;
		l = 1;
		int mid = (l + r) / 2;
		int sol = 0;
		position.sort(null);
		while (l <= r){
			mid = (l + r) / 2;
			if (validCheck(mid)) {
				r = mid - 1;
				sol = mid;
			}
			else
				l = mid + 1;
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


