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
		ArrayList<String> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			String word = br.readLine();
			arr.add(word);
		}
		int sol = 0;
		for (int i = 0; i < arr.size() - 1; i++) {
			String word = arr.get(i);
			for (int j = i + 1; j < arr.size(); j++) {
				String word2 = arr.get(j);
				Map<Character, Character> map = new HashMap<Character, Character>();
				Map<Character, Character> map2 = new HashMap<Character, Character>();
				for (int char_i = 0; char_i < word.length(); char_i++) {
					char word1_chr = word.charAt(char_i);
					char word2_chr = word2.charAt(char_i);
					if ((map.getOrDefault(word1_chr, word2_chr).compareTo(word2_chr) != 0) || (map2.getOrDefault(word2_chr, word1_chr).compareTo(word1_chr) != 0)){
						break;
					}
					map.put(word1_chr, word2_chr);
					map2.put(word2_chr, word1_chr);
					if (char_i == word.length() - 1)
						sol++;
				}
			}
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


