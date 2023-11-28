import java.util.*;
import java.io.*;
 
public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
 
		//input
		String str = br.readLine();
		int len = str.length();
//		System.out.println("len : " + len);
		if (len == 1){
			System.out.println(0);
			return;
		}
		int max_sq = 1;
		if (len % 2 == 0) {
			max_sq = len / 2;
		}
		//
		else{
			max_sq = len / 2;
			for (int i = 1; i < len; i++) {
				if (str.charAt(i) == '1')
				{
					max_sq++;
					break;
				}
			}
		}
		System.out.println(max_sq);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
