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
     * Complete the 'findMinimumTime' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. UNWEIGHTED_INTEGER_GRAPH centre
     *  2. INTEGER_ARRAY status
     */

    /*
     * For the unweighted graph, <name>:
     *
     * 1. The number of nodes is <name>Nodes.
     * 2. The number of edges is <name>Edges.
     * 3. An edge exists between <name>From[i] and <name>To[i].
     *
     */

    public static int findMinimumTime(int centreNodes, List<Integer> centreFrom, List<Integer> centreTo, List<Integer> status) {

        int sol = 0;
        int total_defi = 0;
        int []visited = new int [centreNodes + 1];
        Queue<int[]> q = new LinkedList<>(); 
        ArrayList<Integer> s = new ArrayList<>();
        ArrayList<Integer>[] arr = new ArrayList[centreNodes + 1];
        for (int i = 0; i < centreNodes+1; i++) {
            visited[i] = 0;
            arr[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < centreFrom.size(); i++) {
            int u = centreFrom.get(i);
            int v = centreTo.get(i);
            arr[u].add(v);
            arr[v].add(u);
        }
        
        for (int index = 0; index < status.size(); index++) {
            if (status.get(index) == 1)
                total_defi++;
            else if (status.get(index) == 3)
            {
                int [] start = {index + 1, 0};
                q.add(start);
                visited[index + 1] = 1;
            }
        }
        sol = 0;
        while (q.size() != 0)
        {
           int cur = q.peek()[0]; 
           int cur_step = q.peek()[1];
           //System.out.println("cur : " + cur);
           q.poll();
           if (status.get(cur - 1) == 1)//trans as index
                total_defi--;
            if (total_defi == 0)
            {
                sol = cur_step;
                break;
            }
           for (int index = 0; index < arr[cur].size(); index++) {
               int next = arr[cur].get(index);
               int next_step = cur_step + 1;
               if (visited[next] == 0)
               {
                   int [] next_move = new int[2];
                   next_move[0] = next;
                   next_move[1] = next_step;
                   visited[next] = next_step;
                   q.add(next_move);
               }
           }
        }
        return (sol);
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] centreNodesEdges = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int centreNodes = Integer.parseInt(centreNodesEdges[0]);
        int centreEdges = Integer.parseInt(centreNodesEdges[1]);

        List<Integer> centreFrom = new ArrayList<>();
        List<Integer> centreTo = new ArrayList<>();

        IntStream.range(0, centreEdges).forEach(i -> {
            try {
                String[] centreFromTo = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

                centreFrom.add(Integer.parseInt(centreFromTo[0]));
                centreTo.add(Integer.parseInt(centreFromTo[1]));
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        int statusCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> status = IntStream.range(0, statusCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.findMinimumTime(centreNodes, centreFrom, centreTo, status);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
