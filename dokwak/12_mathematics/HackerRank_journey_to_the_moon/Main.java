import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'journeyToMoon' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. 2D_INTEGER_ARRAY astronaut
     */
	static int[] p;
	static long [] rank;
	static int total_g;

	public static int find (int v)
	{
		if (p[v] == -1)
			return (v);
		p[v] = find(p[v]);
		return (p[v]);
	}

	public static void union(int v1, int v2)
	{
		int v1_g = find(v1);
		int v2_g = find(v2);
		if (v1_g > v2_g)
		{
			int temp = v1_g;
			v1_g = v2_g;
			v2_g = temp;
		}
		p[v2_g] = v1_g;
		rank[v1_g] += rank[v2_g];
		rank[v2_g] = 0;
	}

    public static long journeyToMoon(int n, List<List<Integer>> astronaut) {
    // Write your code here
		long sol = (long) n * (long) (n - 1) / 2;
//		System.out.println("init sol : " + sol);
		p = new int[n];
		rank = new long[n];
		for (int i = 0; i < n; i++) {
			p[i] = -1;
			rank[i] = (long)1;
		}
		for (int i = 0; i < astronaut.size(); i++) {
			List<Integer> pair = astronaut.get(i);
			int v1 = pair.get(0);
			int v2 = pair.get(1);
			if (find(v1) != find(v2))
				union(v1, v2);
		}
		int history = 0;
//		for (int i = 0; i < n; i++) {
//			find(i);
//			System.out.println("parent of " + i + " : " + find(i));
//			System.out.println("rank of " + i + " : " + rank[i]);
//		}
		while (history < n)
		{
			if (find(history) == history && rank[history] != 1)
			{
				long pop = rank[history]; 
				System.out.println("pop of " + history + " : " + pop);
				sol -= (pop * (pop - 1)) / 2;
			}
			history++;
		}
		return (sol);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int p = Integer.parseInt(firstMultipleInput[1]);

        List<List<Integer>> astronaut = new ArrayList<>();

        IntStream.range(0, p).forEach(i -> {
            try {
                astronaut.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        long result = Result.journeyToMoon(n, astronaut);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}

