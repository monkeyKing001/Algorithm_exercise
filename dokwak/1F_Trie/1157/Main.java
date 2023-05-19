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
		String word = br.readLine();
		int [] alph = new int [27];
		for (int i = 0; i < 27; i++) {
			alph[i] = 0;
		}
		int temp_max = 0;
		char temp_alph = 'a';
		for (int i = 0; i < word.length(); i++) {
			char chr = Character.toLowerCase(word.charAt(i));
			int index = chr - 'a';
			alph[index]++;
			if (temp_max < alph[index])
			{
				temp_max = alph[index];
				temp_alph = chr;
			}
		}
		for (int i = 0; i < 27; i++) {
			if (alph[i] == temp_max && (i + 'a') != temp_alph)
			{
				System.out.println("?");
				return ;
			}
		}
		System.out.println(Character.toUpperCase(temp_alph));
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
