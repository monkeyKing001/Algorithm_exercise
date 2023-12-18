import java.util.*;
import java.io.*;

public class Main{
	static int n, m;

	public enum monIdx{
		January("January", 0), 
		February("February", 1), 
		March("March", 2), 
		April("April", 3), 
		May("May", 4), 
		June("June", 5), 
		July("July", 6), 
		August("August", 7), 
		September("September", 8), 
		October("October", 9), 
		November("November", 10), 
		December("December", 11);
		final private int idx;
		final private String str;

		monIdx(String str, int idx){
			this.str = str;
			this.idx = idx;
		}

		public int getIdx(){
			return this.idx;
		}
		public String getStr(){
			return this.str;
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int [] dayForMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int minutesPerDay = 24 * 60;
		int totalMinutes = 0;
		int sumMinutes = 0;
		String mon = st.nextToken();
		String dayStr = st.nextToken();
		int day = Integer.parseInt(dayStr.substring(0, dayStr.length() - 1));
		int year = Integer.parseInt(st.nextToken());
		String time[] = st.nextToken().split(":");
		int hour = Integer.parseInt(time[0]);
		int minutes = Integer.parseInt(time[1]);
//		sb.append(mon);
//		sb.append("\n");
//		sb.append(day);
//		sb.append("\n");
//		sb.append(year);
//		sb.append("\n");
//		sb.append(hour);
//		sb.append("\n");
//		sb.append(minutes);
//		sb.append("\n");
		//leap year
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			dayForMonth[1] = 29;
		for (int i = 0; i <= monIdx.December.getIdx(); i++) {
			totalMinutes += dayForMonth[i] * minutesPerDay;
		}
		for (int i = 0; i < monIdx.valueOf(mon).getIdx(); i++) {
			sumMinutes += dayForMonth[i] * minutesPerDay;
		}
		sumMinutes += (day - 1) * minutesPerDay;
		sumMinutes += 60 * hour;
		sumMinutes += minutes;
		double sol = (double) sumMinutes / (double) totalMinutes * 100;
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


