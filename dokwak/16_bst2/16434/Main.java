import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int n = Integer.parseInt(st.nextToken());
		int atk = Integer.parseInt(st.nextToken());
		long [][]rooms = new long[n][3];

		//input
		//n = Integer.parseInt(st.nextToken());
		long dragon_total_atc = 0L;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			rooms[i][0] = Integer.parseInt(st.nextToken());
			rooms[i][1] = Integer.parseInt(st.nextToken());
			rooms[i][2] = Integer.parseInt(st.nextToken());
			if (rooms[i][0] == 1)
				dragon_total_atc += rooms[i][1] * rooms[i][2];
		}
		long cur_atk = atk;
		long min_hp = 1; 
		long max_hp = dragon_total_atc;
		long mid_hp = (max_hp + min_hp) / 2;
		long limit_hp = mid_hp;
		long cur_hp = limit_hp;
		long sol = max_hp;
		while (min_hp <= max_hp)
		{
			//room travel
			boolean win = true;
			//init
//			System.out.println("binary search. max, min, mid : " + max_hp + ", " + min_hp +", " + mid_hp);
			limit_hp = mid_hp;
			cur_hp = limit_hp;
			cur_atk = atk;
			for (int i = 0; i < n; i++) {
				long room_type = rooms[i][0];
				//fight
				if (room_type == 1)
				{
					long dragon_hp = rooms[i][2];
					long dragon_atk = rooms[i][1];
					double my_atk_time = Math.ceil((double)dragon_hp / cur_atk);
					double dragon_atk_time = Math.ceil((double)cur_hp / dragon_atk);
					if (my_atk_time > dragon_atk_time)
					{
//						System.out.println("cannot win: hp, atk :" + cur_hp + ", " + cur_atk);
						win = false;
						break;
						//lose
					}
					else
					{
//						System.out.println("dragon_hp : " + dragon_hp);
//						System.out.println("my cur_atck : " + cur_atk);
//						System.out.println("my atck time : " + Math.ceil((double)dragon_hp/cur_atk));
						cur_hp -= (my_atk_time - 1) * dragon_atk;
						//win
					}
				}
				//potion
				else
				{
					cur_atk += rooms[i][1];
					if (cur_hp + rooms[i][2] > limit_hp)
						cur_hp = limit_hp;
					else
						cur_hp += rooms[i][2];
				}
			}
			if (win)
			{
//				System.out.println("win: hp, atk :" + cur_hp + ", " + cur_atk);
				if (mid_hp < sol)
					sol = mid_hp;
				max_hp = mid_hp - 1;
				mid_hp = (max_hp + min_hp) / 2;
			}
			else
			{
				min_hp = mid_hp + 1;
				mid_hp = (max_hp + min_hp) / 2;
//				System.out.println("moving hp to " + mid_hp);
			}
//			System.out.println("moving binary search. max, min, mid : " + max_hp + ", " + min_hp +", " + mid_hp);
		}
		System.out.print(sol);
		return ;
	}
}
