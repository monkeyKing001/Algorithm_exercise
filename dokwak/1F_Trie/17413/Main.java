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
		String strLine = br.readLine();
		char [] str = strLine.toCharArray();
		int l = 0;
		while (l < str.length){
			int r = l;
			while (r < str.length && str[r] != '<' && str[r] != ' '){
				r++;
			}
			int temp_r = r - 1;
			int temp_l = l;
			while (temp_l <= temp_r){
				char temp = str[temp_l];
				str[temp_l] = str[temp_r];
				str[temp_r] = temp;
				temp_l++;
				temp_r--;
			}
			if (r < str.length && str[r] == '<'){
				while (r < str.length && str[r] != '>'){
					r++;
				}
			}
			l = r + 1;
		}
		sb.append(str);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


