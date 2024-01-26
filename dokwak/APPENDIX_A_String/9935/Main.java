import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");

		String origin = br.readLine();
		String target = br.readLine();
		ArrayList<Character> arr = new ArrayList<>();
		//input
		for (int i = 0; i < origin.length(); i++) {
			char chr = origin.charAt(i);
//			arr.add(chr);
			sb.append(chr);
			if (chr == target.charAt(target.length() - 1)){//last char hit
				boolean made = false;
				for (int j = 0; j < target.length(); j++) {
					int targetIdx = target.length() - 1 - j;
					int sbIdx = sb.length() - 1 - j;
					if (targetIdx < 0 || sbIdx < 0)
						break;
					if (sb.charAt(sbIdx) != target.charAt(targetIdx))
						break;
					if (targetIdx == 0)
						made = true;
				}
				if (made){
					for (int k = 0; k < target.length(); k++) {
						sb.delete(sb.length() - 1, sb.length());
//						arr.remove(arr.size() - 1);
					}
//					System.out.println("now string : " + sb.toString());
				}
			}
		}
		if (sb.length() == 0)
			sb.append("FRULA");
		System.out.println(sb.toString());
		return ;
	}
}


