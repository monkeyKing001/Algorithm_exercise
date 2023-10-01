import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int info [][];
	static int caseBits[];
	static int maxCase;
	public static int getDiff(int bits){
		int ret = 0;
		int startPower = 0;
		int linkPower = 0;
		int startTeam [] = new int [n];//0
		int linkTeam [] = new int [n];//1
		for (int i = 0; i < n; i++) {
			if (((bits >> (n - i - 1)) & 1) == 1)//hit
			{
//				System.out.println(i + " is linkTeam");
				linkTeam[i] = 1;
				startTeam[i] = 0;
			}
			else{//not his
//				System.out.println(i + " is startTeam");
				linkTeam[i] = 0;
				startTeam[i] = 1;
			}
		}
		//start Power
		for (int i = 0; i < n; i++) {
			if (startTeam[i] == 1)
			{
				for (int j = i + 1; j < n; j++) {
					if (startTeam[j] == 1)
					{
						startPower += info[i][j];
						startPower += info[j][i];
					}
				}
			}
			else{
				for (int j = i + 1; j < n; j++) {
					if (linkTeam[j] == 1)
					{
						linkPower += info[i][j];
						linkPower += info[j][i];
					}
				}
			}
		}
		ret = Math.abs(linkPower - startPower);
		return (ret);
	}

	public static boolean validCase(int bits){
		if (caseBits[bits] == 1 || caseBits[maxCase - bits] == 1)
			return false;
		int countHalf = n / 2;
		int count = 0;
		for (int i = 0; i < n; i++) {
			if ((((bits >> i) & 1)) == 1)//bit hit
				count++;
		}
		caseBits[bits] = 1;
		if (count == countHalf)
			return true;
		else
			return false;
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		info = new int [n][n];
		caseBits = new int[(1 << n)];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < n; j++) {
				info[i][j] = Integer.parseInt(st.nextToken());
			}
		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				System.out.print(info[i][j] + " ");
//			}
//			System.out.println();
//		}
		maxCase = (1 << n) - 1;
		int sol = Integer.MAX_VALUE;
		for (int i = 0; i < maxCase; i++) {
			if (validCase(i))
				sol = Integer.min(sol, getDiff(i));
		}
		System.out.println(sol);
		return ;
	}
}
