import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] abilities = new int[N][M];
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]); // {능력치, 학급번호, 학생번호}

        int currentMax = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                abilities[i][j] = Integer.parseInt(st.nextToken());
            }
            
            Arrays.sort(abilities[i]);
            
            pq.add(new int[]{abilities[i][0], i, 0});
            
            currentMax = Math.max(currentMax, abilities[i][0]);
        }

        int minDiff = Integer.MAX_VALUE;

        while (true) {
            int[] curr = pq.poll();
            int minVal = curr[0];
            int classIdx = curr[1];
            int studentIdx = curr[2];

            minDiff = Math.min(minDiff, currentMax - minVal);

            if (studentIdx + 1 < M) {
                int nextVal = abilities[classIdx][studentIdx + 1];
                
                pq.add(new int[]{nextVal, classIdx, studentIdx + 1});
                currentMax = Math.max(currentMax, nextVal);
            } else {
                break;
            }
        }

        System.out.println(minDiff);
    }
}