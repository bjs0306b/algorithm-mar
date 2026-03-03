import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] readLine = br.readLine().split(" ");
        int N = Integer.parseInt(readLine[0]);
        int K = Integer.parseInt(readLine[1]);

        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();

        String[] secondLine = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            int pos = Integer.parseInt(secondLine[i]);
            visited.add(pos);
            queue.add(pos);
        }

        long answer = 0;
        int buildCount = 0;
        int distance = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                int currPos = queue.poll();

                int[] nextPositions = {currPos - 1, currPos + 1};

                for (int next : nextPositions) {
                    if (!visited.contains(next)) {
                        visited.add(next);
                        queue.add(next);

                        answer += distance;
                        buildCount++;

                        if (buildCount == K) {
                            System.out.println(answer);
                            return;
                        }
                    }
                }
            }

            distance++;
        }
    }
}