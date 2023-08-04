import java.util.*;
import java.io.*;

public class Main{
	static int n, m, n_len;
	public static class Case{
		private
			int _step = 0;
			char [] _nums;
			int _sorted_radix = 0;

		public Case(int step, char []nums){
			this._step = step;
			this._sorted_radix = 0;
			this._nums = new char[n_len];
			for (int i = 0; i < n_len; i++) {
				this._nums[i] = nums[i];
			}
		}

		public int getNum(){
			int ret = 0;
			String temp_str = new String(this._nums);
			ret = Integer.parseInt(temp_str);
			return (ret);
		}

		public char[] getArr(){
			char [] cp = new char[n_len];
			for (int i = 0; i < n_len; i++) {
				cp[i] = this._nums[i];
			}
			return (cp);
		}

		public int getStep(){
			return (this._step);
		}

	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		//input
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		String n_str = st.nextToken();
		n = Integer.parseInt(n_str);
		n_len = n_str.length();
		m = Integer.parseInt(st.nextToken());
		int []dp = new int[m + 2];
		boolean [][]visited = new boolean [11][1000001];
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 1000001; j++) {
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < m + 2; i++) {
			dp[i] = -1;
		}
		char [] temp = n_str.toCharArray();
		ArrayList<Character> max = new ArrayList<>();
		for (int i = 0; i < n_len; i++) {
			max.add(temp[i]);
		}
		max.sort(Comparator.reverseOrder());
		String max_str = "";
		for (int i = 0; i < max.size(); i++) {
			max_str += max.get(i).toString();
		}
		int max_int = Integer.parseInt(max_str);
		Queue<Case> q = new LinkedList<>();
		Case init = new Case(0, temp);
		q.add(init);
		while (q.size() != 0){
			Case cur = q.poll();
			int cur_num = cur.getNum();
			int cur_step = cur.getStep();
			if (visited[cur_step][cur_num] != false)
				continue;
			if (cur_num > dp[cur_step])
			{
				dp[cur_step] = cur_num;
//				System.out.println("updating step, num : " + cur_step + ", " + dp[cur_step]);
			}
			if (cur_step == m)
				continue ;
			visited[cur_step][cur_num] = true;
			//search next_num
			char [] num_arr = cur.getArr();
			//searching need
			for (int i = 0; i < n_len; i++) {
				for (int j = i + 1; j < n_len; j++) {
					if (i == 0 && num_arr[j] == '0')
						continue;
					char []next_num_arr = cur.getArr();
					char swap = next_num_arr[i];
					int next_step = cur_step + 1;
					next_num_arr[i] = next_num_arr[j];
					next_num_arr[j] = swap;
					Case next = new Case(cur_step + 1, next_num_arr);
					if (visited[next_step][next.getNum()] == true)
						continue ;
//					System.out.println("next step, num : " + next_step +", "+ next.getNum());
					q.add(next);
				}
			}
		}
		System.out.println(dp[m]);
		return ;
	}
}
