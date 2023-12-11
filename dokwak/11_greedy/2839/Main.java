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
		int maxFive = n / 5;
		int three = 0;
		while (maxFive > -1){
			if ((n - (5 * maxFive)) % 3 == 0){
				three = (n - (5 * maxFive)) / 3;
				break;
			}
			maxFive--;
		}
		sb.append(maxFive + three);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


