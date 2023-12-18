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
		char [][] map = new char[n][n];
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			for (int j = 0; j < n ; j++){
				map[i][j] = str.charAt(j);
			}
		}
		int rowZone = 0;
		int colZone = 0;
		for (int i = 0; i < n; i++) {
			//row check
			String rowStr = "";
			for (int j = 0; j < n; j++) {
				rowStr += map[i][j];
			}
			String [] zone = rowStr.split("X");
			for (int j = 0; j < zone.length; j++) {
				if (zone[j].length() >= 2){
					rowZone++;
				}
			}
			//col check
			String colStr = "";
			for (int j = 0; j < n; j++) {
				colStr += map[j][i];
			}
			zone = colStr.split("X");
			for (int j = 0; j < zone.length; j++) {
				if (zone[j].length() >= 2){
					colZone++;
				}
			}
		}
		sb.append(rowZone + " " + colZone);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


