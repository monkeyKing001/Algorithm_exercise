import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int maxDis = -1;
	static ArrayList<Integer> house = new ArrayList<>();
	static boolean valid(int key){
		int leftHubNum = m - 1;
		int tempMaxDis = Integer.MAX_VALUE;
		int lastHub = house.get(0);
		for (int i = 1; i < house.size(); i++) {
			int end = house.get(i);
			int interval = end - lastHub;
			if (interval >= key) {
				leftHubNum--;
				lastHub = end;
				tempMaxDis = Integer.min(tempMaxDis, interval);
			}
			if (leftHubNum == 0){
				maxDis = Integer.max(tempMaxDis, maxDis);
				return (true);
			}
		}
		return false;
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
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int num = Integer.parseInt(st.nextToken());
			house.add(num);
		}
		house.sort(null);
		int l  = 1;
		int r  = house.get(house.size() - 1) - house.get(0);
		int mid = (l + r) / 2;
		while (l <= r){
			mid = (l + r) / 2;
			if (valid(mid)){
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		System.out.println(maxDis);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
