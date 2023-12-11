import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static boolean devilNum(int num){
		String str = Integer.toString(num);
		for (int i = 0; i < str.length() - 2; i++) {
			if (str.charAt(i) != '6')
				continue;
			if (str.charAt(i + 1) == '6' && str.charAt(i + 2) == '6')
			{
//				System.out.println("dev : "+ str);
				return true;
			}
		}
		return (false);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		int num = 666;
		while (n > 0){
			if (devilNum(num))
				n--;
			if (n == 0)
				break;
			num++;
		}
		sb.append(num);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


