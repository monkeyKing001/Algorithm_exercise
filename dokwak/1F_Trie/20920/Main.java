import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static Map<String, Integer> freq;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		freq = new HashMap<>();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		PriorityQueue<String> wordBook = new PriorityQueue<>(new Comparator<String>(){
			@Override
			public int compare(String word1, String word2){
				if (freq.get(word1) == freq.get(word2)){
					if (word1.length() == word2.length()){
						return (word1.compareTo(word2));
					}
					else{
						return Integer.compare(word2.length(), word1.length());
					}
				}
				else{
					return Integer.compare(freq.get(word2), freq.get(word1));
				}
			}
		});

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			String word = br.readLine();
//			System.out.println("word : " + word);
			if (word.length() < m)
				continue;
			if (freq.containsKey(word))
				freq.put(word, freq.get(word) + 1);
			else{
				freq.put(word, 1);
			}
		}
		Iterator<Map.Entry<String, Integer>> it = freq.entrySet().iterator();
		while (it.hasNext()){
			wordBook.add(it.next().getKey());
		}
		while(wordBook.size() != 0){
			sb.append(wordBook.poll() + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


