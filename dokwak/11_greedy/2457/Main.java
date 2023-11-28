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
		int info [][] = new int [n][2];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int startMon = Integer.parseInt(st.nextToken());
			int startDay = Integer.parseInt(st.nextToken());
			int endMon = Integer.parseInt(st.nextToken());
			int endDay = Integer.parseInt(st.nextToken());
			info[i][0] = startMon * 100 + startDay; 
			info[i][1] = endMon * 100 + endDay; 
		}
		int lastEndMon = 3;
		int lastEndDay = 1;
		int lastEnd = lastEndMon * 100 + lastEndDay;
		Arrays.sort(info, new Comparator<int[]>(){
			@Override
			public int compare(int []e1, int []e2){
				if (e1[0] == e2[0])
					return Integer.compare(e1[1], e2[1]);
				return Integer.compare(e1[0], e2[0]);
			}
		});
//		for (int i = 0; i < n; i++) {
//			System.out.println(info[i][0] + " ~ " + info[i][1]);
//		}
		ArrayList<int[]> log = new ArrayList<>();
		int l = 0;
		while (l < n){
			//find the longest that starts before lastEnd;
			int r = l;
			while (r < n && info[r][0] <= lastEnd){
				r++;
			}
			ArrayList<int[]> candidates = new ArrayList<>();
			for (int i = l; i < r; i++) {
				candidates.add(info[i]);
			}
			candidates.sort(new Comparator<int[]>(){
				@Override
				public int compare(int[] info1, int[]info2){
					return (Integer.compare(info2[1], info1[1]));
				}
			});
			if (candidates.size() == 0)
				break;
			log.add(candidates.get(0));
//			System.out.println("selected start ~ end : " +candidates.get(0)[0]+ " ~ "+ candidates.get(0)[1]);
			lastEnd = candidates.get(0)[1];
			l = r;
			if (lastEnd >= 1200)
				break;
		}
//		for (int i = 0; i < log.size(); i++) {
//			System.out.println("start~end : " +log.get(i)[0] + " ~ " + log.get(i)[1]);
//		}
		if (log.size() != 0 && log.get(log.size() - 1)[1] <= 1200)
			log.clear();
		System.out.println(log.size());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


