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
		int outOfOrder = 0;
		Map<String ,Integer> originOrder = new HashMap<>();
		int order[] = new int[n];
		for (int i = 0; i < n; i++) {
			String car = br.readLine();
			originOrder.put(car, i);
			order[i] = i;
//			System.out.println(i + " " + car);
		}
		for (int i = 0; i < n; i++) {
			String car = br.readLine();
			int originOrd = originOrder.get(car);
			if (order[originOrd] != i){
//				System.out.println(car + " is out of order.");
//				System.out.println("order = " +  order[originOrd]);
//				System.out.println("overtaking order = " +  i);
				for (int j = 0; j < originOrd; j++) {
					order[j]++;
				}
				outOfOrder++;
			}
		}
		System.out.println(outOfOrder);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


