import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] wards = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            wards[i] = Integer.parseInt(st.nextToken());
        }

        List<int[]>[] adj = new ArrayList[N];
        for (int i = 0; i < N; i++) adj[i] = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            if ((wards[u] == 1 && u != N - 1) || (wards[v] == 1 && v != N - 1)) continue;

            adj[u].add(new int[]{v, t});
            adj[v].add(new int[]{u, t});
        }

        long[] dist = new long[N];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;

        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(o -> o[1]));
        pq.add(new long[]{0, 0});

        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            int u = (int) curr[0];
            long d = curr[1];

            if (d > dist[u]) continue;

            for (int[] edge : adj[u]) {
                int v = edge[0];
                int weight = edge[1];

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.add(new long[]{v, dist[v]});
                }
            }
        }

        if (dist[N - 1] == Long.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(dist[N - 1]);
        }
    }
}