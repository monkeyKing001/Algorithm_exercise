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
		ArrayList<int[]> arr = new ArrayList<>();
		n = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int info [] = new int [2];
			info[0] = start;
			info[1] = end;
			arr.add(info);
		}
		arr.sort(new Comparator<int[]>(){
			@Override
			public int compare(int info1[], int info2[]){
				if (info1[0] == info2[0])
					return (Integer.compare(info1[1], info2[1]));
				return (Integer.compare(info1[0], info2[0]));
			}
		});
		int tempStart = arr.get(0)[0];
		int tempEnd = arr.get(0)[1];
		int total = 0;
		for (int i = 1; i < arr.size(); i++) {
			int start = arr.get(i)[0];
			int end = arr.get(i)[1];
			if (start > tempEnd) {
				total += (tempEnd - tempStart);
				tempStart = start;
				tempEnd = end;
			}
			if (end > tempEnd)
				tempEnd = end;
		}
		total += tempEnd - tempStart;
		sb.append(total);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


