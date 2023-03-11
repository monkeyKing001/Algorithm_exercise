import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
//		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int n = 0;

		//input
		//n = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(br.readLine());
		int good_word = 0;
		for (int i = 0; i < n; i++) {
			Stack <Character> s = new Stack<>();	
			String input = br.readLine();
			for (int j = 0; j < input.length(); j++) {
				if (s.size() != 0 && s.peek() == input.charAt(j))
					s.pop();
				else
					s.push(input.charAt(j));
			}
			if (s.size() == 0)
				good_word++;
		}
		System.out.println(good_word);
		return ;
	}
}

