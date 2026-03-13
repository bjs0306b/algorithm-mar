import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine().trim());
        int M = Integer.parseInt(br.readLine().trim());

        List<int[]>[] adj = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) adj[i] = new ArrayList<>();

        int[] inDegree = new int[N + 1];
        int[] toOneScore = new int[N + 1];
        Arrays.fill(toOneScore, -1);

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            if (v == 1) {
                toOneScore[u] = Math.max(toOneScore[u], w);
            } else {
                adj[u].add(new int[]{v, w});
                if (u != 1) inDegree[v]++;
            }
        }

        int[] dist = new int[N + 1];
        int[] parent = new int[N + 1];
        Queue<Integer> q = new LinkedList<>();

        for (int[] edge : adj[1]) {
            int target = edge[0];
            int weight = edge[1];
            dist[target] = weight;
            parent[target] = 1;
        }

        for (int i = 2; i <= N; i++) {
            if (inDegree[i] == 0) q.add(i);
        }

        while (!q.isEmpty()) {
            int curr = q.poll();

            for (int[] edge : adj[curr]) {
                int next = edge[0];
                int weight = edge[1];

                if (parent[curr] != 0) {
                    if (dist[next] < dist[curr] + weight) {
                        dist[next] = dist[curr] + weight;
                        parent[next] = curr;
                    }
                }

                if (--inDegree[next] == 0) q.add(next);
            }
        }

        int maxTotal = 0;
        int lastNode = 0;
        for (int i = 2; i <= N; i++) {
            if (toOneScore[i] != -1 && parent[i] != 0) {
                if (maxTotal < dist[i] + toOneScore[i]) {
                    maxTotal = dist[i] + toOneScore[i];
                    lastNode = i;
                }
            }
        }

        System.out.println(maxTotal);

        Stack<Integer> path = new Stack<>();
        path.push(1);
        int curr = lastNode;
        while (curr != 0) {
            path.push(curr);
            curr = parent[curr];
        }

        StringBuilder sb = new StringBuilder();
        while (!path.isEmpty()) {
            sb.append(path.pop()).append(" ");
        }
        System.out.println(sb.toString().trim());
    }
}