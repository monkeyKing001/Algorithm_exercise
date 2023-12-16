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
		int radixSum = 0;
		String str = st.nextToken();
		ArrayList<Integer> arr = new ArrayList<>();
		for (int i = 0; i < str.length(); i++) {
			int num = str.charAt(i) - '0';
			radixSum += num;
			arr.add(num);
		}
		if (radixSum % 3 != 0 || !arr.contains(Integer.valueOf(0))){
			sb.append(-1);
			bw.write(sb.toString());
			bw.flush();
			return ;
		}
		arr.sort(Comparator.reverseOrder());
		for (int i = 0; i < arr.size(); i++) {
			sb.append(arr.get(i));
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


