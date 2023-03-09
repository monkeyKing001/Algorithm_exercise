import java.util.*;

public class Main{
	public static void main (String[] args) {
		int n;
		int sol = 0;
		Stack<Integer> s = new Stack<>();
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			int temp;
			temp = sc.nextInt();
			if (temp == 0 && !s.empty())
			{
//				System.out.println("poping "+ s.peek());
				sol -= s.peek();
//				System.out.println("sum : "+ sol);
				s.pop();
			}
			else if (temp != 0)
			{
//				System.out.println("pushing "+ temp);
				sol += temp;
//				System.out.println("sum : "+ sol);
				s.push(temp);
			}
		}
		sc.close();
		System.out.print(sol);
		return ;
	}
}
