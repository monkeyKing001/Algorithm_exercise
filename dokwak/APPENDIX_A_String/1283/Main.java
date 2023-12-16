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
		ArrayList<String> sol = new ArrayList<>();
		Set<Character> shortCut = new HashSet<>();
		for (int i = 0; i < n; i++) {
			String originalString = br.readLine();
			String newString = originalString;
			String words[] = originalString.split(" ");
			boolean made = false;
			for (int j = 0; j < words.length; j++) {
				//found possible shortCut
				if (!shortCut.contains(Character.toLowerCase(words[j].charAt(0)))){
					newString = "";
					shortCut.add(Character.toLowerCase(words[j].charAt(0)));
					made = true;
					words[j] = words[j].replaceFirst(words[j].charAt(0) + "","[" + words[j].charAt(0) +  "]");
//					sb.append("new word : " + words[j]);
//					sb.append("\n");
					for (int k = 0; k < words.length; k++) {
						newString += words[k];
						if (k != words.length - 1)
							newString += " ";
					}
					break;
				}
			}
			//couldn't find
			if (!made){
				for (int j = 0; j < originalString.length(); j++) {
					//found possible shortCut
					if (originalString.charAt(j) != ' ' && !shortCut.contains(Character.toLowerCase(originalString.charAt(j)))){
						newString = "";
						shortCut.add(Character.toLowerCase(originalString.charAt(j)));
						newString = originalString.replaceFirst(originalString.charAt(j) + "", "[" + originalString.charAt(j) +"]");
//						sb.append("new word : " + newString);
//						sb.append("\n");
						break;
					}
				}
			}
			sol.add(newString);
		}
		for (int i = 0; i < sol.size(); i++) {
			sb.append(sol.get(i) + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
