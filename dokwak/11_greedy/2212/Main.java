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
		PriorityQueue<int[]>distance = new PriorityQueue<>(new Comparator<int[]>(){
			@Override
			public int compare(int [] d1, int d2[]){
				return (Integer.compare(d2[1] - d2[0] , d1[1] - d1[0]));
			}
		});
		n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		m = Integer.parseInt(st.nextToken());
		int arr[] = new int[n];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			arr[i] =  Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		for (int i = 0; i < n - 1; i++) {
			int p1 = arr[i];
			int p2 = arr[i + 1];
			int []d  = new int[2];
			d[0] = p1;
			d[1] = p2;
			distance.add(d);
		}
		int sol = arr[n - 1] - arr[0];
		while(distance.size() > 0 && m > 1){
			int [] d = distance.poll();
//			System.out.println("minus : " +d[0]+" ~ "+d[1]);
			sol -= (d[1] - d[0]);
			m--;
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


