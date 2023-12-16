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
		ArrayList<Integer> arr = new ArrayList<>();
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			arr.add(num);
		}
		st = new StringTokenizer(br.readLine()," ");
		m = Integer.parseInt(st.nextToken());
		for (int i = 0; i < arr.size(); i++) {
			int cur_num = arr.get(i);
			int findMax = cur_num;
			int l = i;
			int findIdx = -1;
			while (l - i <= m && l < arr.size()){
				if (arr.get(l) > findMax) {
					findMax = arr.get(l);
					findIdx = l;
				}
				l++;
			}
			if (findIdx != -1){
				arr.remove(findIdx);
				arr.add(i, findMax);
				m -= findIdx - i; 
			}
		}
		for (int i = 0; i < arr.size(); i++) {
			sb.append(arr.get(i) + " ");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


