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
		m = Integer.parseInt(st.nextToken());
		ArrayList<String> teamInfo[] = new ArrayList[n];
		Map<String, Integer> teamNameToTeamNumber = new HashMap<String, Integer>();
		Map<Integer, String> teamNumberToTeamName = new HashMap<Integer, String>();
		Map<String, Integer> memberNameToTeamNumber = new HashMap<String, Integer>();
		for (int i = 0; i < n; i++) {
			teamInfo[i] = new ArrayList<>();
			String teamName = br.readLine();
			teamNameToTeamNumber.put(teamName, teamNameToTeamNumber.size());
			int teamNumber = teamNameToTeamNumber.get(teamName);
			teamNumberToTeamName.put(teamNumber, teamName);
			st = new StringTokenizer(br.readLine()," ");
			int memberNum = Integer.parseInt(st.nextToken());
			for (int j = 0; j < memberNum; j++) {
				String memberName = br.readLine();
				memberNameToTeamNumber.put(memberName, teamNumber);
				teamInfo[teamNumber].add(memberName);
			}
			teamInfo[teamNumber].sort(null);
		}
		for (int i = 0; i < m; i++) {
			String hint = br.readLine();
			st = new StringTokenizer(br.readLine()," ");
			int type = Integer.parseInt(st.nextToken());
			if (type == 0) {
				//member print
				int teamNumber = teamNameToTeamNumber.get(hint);
				for (int j = 0; j < teamInfo[teamNumber].size(); j++) {
					System.out.println(teamInfo[teamNumber].get(j));
				}
			}
			else if (type == 1) {
				//team name print
				int teamNumber = memberNameToTeamNumber.get(hint);
				System.out.println(teamNumberToTeamName.get(teamNumber));
			}
		}
		return ;
	}
}


