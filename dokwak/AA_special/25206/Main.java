import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st;

		//input
		String input = br.readLine();
		int totalCredit = 0;
		double totalScore = 0D;
		Map<String, Double> table = new HashMap<>();
		table.put("A+", 4.5);
		table.put("A0", 4.0);
		table.put("B+", 3.5);
		table.put("B0", 3.0);
		table.put("C+", 2.5);
		table.put("C0", 2.0);
		table.put("D+", 1.5);
		table.put("D0", 1.0);
		table.put("F", 0.0);
		while (input != null){
			st = new StringTokenizer(input," ");
			String name = st.nextToken();
			String credit = st.nextToken();
			String score = st.nextToken();
			if (table.containsKey(score)){
				double curCredit = Double.parseDouble(credit);
				totalCredit += (int)curCredit;
				totalScore += table.get(score) * curCredit;
			}
			input = br.readLine();
		}
		System.out.println(totalScore/totalCredit);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


