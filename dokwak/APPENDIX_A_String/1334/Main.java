import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		String numStr = st.nextToken();
		String halfStr = numStr.substring(0, (numStr.length() + 1) / 2);
		BigInteger bigNum = new BigInteger(numStr);
		BigInteger halfNum = new BigInteger(halfStr);
		int len = numStr.length();
		char buf[] = new char[len];
		int mid = (numStr.length() + 1) / 2;
		for (int i = 0; i < mid; i++) {
			buf[i] = halfStr.charAt(i);
		}
		for (int i = len - 1; i >= mid; i--) {
			buf[i] = buf[len - 1 - i];
		}
		String palind = new String(buf);
		//wrong palind
//		sb.append(palind);
//		sb.append("\n");
		if (palind.compareTo(numStr) > 0){
			sb.append(palind);
			bw.write(sb.toString());
			bw.flush();
			return ;
		}
		halfNum = halfNum.add(BigInteger.valueOf(1));
		String nextHalfStr = halfNum.toString();
//		sb.append(nextHalfStr + " is next\n");
		if (nextHalfStr.length() > halfStr.length()){
			len++;
		}
		char nextBuf[] = new char[len];
		mid = (len + 1) / 2;
		for (int i = 0; i < mid; i++) {
			nextBuf[i] = nextHalfStr.charAt(i);
		}
		for (int i = len - 1; i >= mid; i--) {
			nextBuf[i] = nextBuf[len - 1 - i];
		}
		palind = new String(nextBuf);
		sb.append(palind);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


