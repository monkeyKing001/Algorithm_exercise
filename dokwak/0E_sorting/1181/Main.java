import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		sb.append("");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		ArrayList<Integer> jsp = new ArrayList<>();
		ArrayList<Integer> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			arr.add(i + 1);
		}
		int idx = 0;
		while (arr.size() != 0){
			idx += m -1;
			idx %= arr.size();
			jsp.add(arr.get(idx));
			arr.remove(idx);
		}
		sb.append("<");
		for (int i = 0; i < jsp.size(); i++) {
			sb.append(jsp.get(i));
			if (i != jsp.size() - 1){
				sb.append(", ");
			}
			else{
				sb.append(">");
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


