import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int sol = Integer.MIN_VALUE;
	static Set<Character> alphabetCombinations = new HashSet<>();
	static Set<Character> words[];
	public static void rec(Set<Character> s, int nextCharIdx){
		if (s.size() == m){
			//hit check
//			System.out.println("let's check : " + s.toString());
			int tempCount = 0;
			for (int i = 0; i < n; i++) {
				Iterator <Character> it = words[i].iterator();
				while (it.hasNext()){
					char chr = it.next(); 
					if (!s.contains(chr)){
//						System.out.println("cannot make word : " + words[i].toString());
						break;
					}
					if (!it.hasNext())
						tempCount++;
				}
			}
			sol = Integer.max(sol, tempCount);
//			System.out.println("count : " + tempCount);
//			System.out.println("sol : " + sol);
			return;
		}
		for (int i = nextCharIdx; i < 26; i++) {
			char chr = (char)(i + 'a');
			if (!s.contains(chr)){
				s.add(chr);
				rec(s, i + 1);
				s.remove(chr);
			}
		}
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int k = m;
		if (k < 5) {
			sol = 0;
			System.out.println(sol);
			return;
		}
		if (k == 26) {
			sol = n;
			System.out.println(sol);
			return;
		}
		words = new Set[n];
		for (int i = 0; i < n; i++) {
			String word = br.readLine();
			words[i] = new HashSet<Character>();
			for (int w_i = 0; w_i < word.length(); w_i++) {
				char chr = word.charAt(w_i);
				words[i].add(chr);
			}
//			System.out.println(s[i].toString());
		}
		alphabetCombinations.add('a');
		alphabetCombinations.add('n');
		alphabetCombinations.add('t');
		alphabetCombinations.add('i');
		alphabetCombinations.add('c');
		rec(alphabetCombinations, 1);
		System.out.println(sol);
		return ;
	}
}


