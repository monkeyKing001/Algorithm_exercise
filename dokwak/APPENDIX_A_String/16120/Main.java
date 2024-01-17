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
		String origin = br.readLine();
		String ppap = "PPAP";
		ArrayList<Character> stck = new ArrayList<>();
		for (int i = 0; i < origin.length(); i++) {
			char chr = origin.charAt(i);
			stck.add(chr);
//			System.out.println(stck.toString());
			if (stck.size() >= 4 && chr == 'P'){
				for (int j = 0; j < 4; j++) {
					if (stck.get(stck.size() - 1 - j) != ppap.charAt(3 - j))
						break;
					if (j == 3){
						for (int k = 0; k < 4; k++) {
							stck.remove(stck.size() - 1);
						}
						stck.add('P');
					}
				}
			}
//			System.out.println(stck.toString());
		}
		String sol = (stck.size() == 1 && stck.get(0) == 'P' )? "PPAP" : "NP";
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


