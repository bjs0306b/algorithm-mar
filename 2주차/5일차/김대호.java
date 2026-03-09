import java.util.*;
import java.io.*;

public class Main {
	static int[] dy = {-1, 1, 0, 0};
	static int[] dx = {0, 0, -1, 1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] readLine = br.readLine().split(" ");
		
		int N, M;
		N = Integer.parseInt(readLine[0]);
		M = Integer.parseInt(readLine[1]);

		char[][] map = new char[N][M];
		int[] sPos = new int[2];
		int[] hPos = new int[2];
		for (int i = 0; i < N; i++) {
			String line = br.readLine();
			for (int j = 0; j < M; j++) {
				map[i][j] = line.charAt(j);
				if (map[i][j] == 'S') {
					sPos = new int[] {i,j};
				} else if (map[i][j] == 'H') {
					hPos = new int[] {i,j};
				}
			}
		}

		Map<List<Integer>, Integer> searchedMap = new HashMap<>();
		boolean[][] visited = new boolean[N][M];
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {sPos[0], sPos[1], 0});
		visited[sPos[0]][sPos[1]] = true;
		
		while (!q.isEmpty()) {
			int[] now = q.poll();
			
			for (int i = 0; i < 4; i++) {
				int ny = now[0] + dy[i];
				int nx = now[1] + dx[i];
				int nd = now[2] + 1;
				
				if (ny < 0 || ny >= N || nx < 0 || nx >= M || 
						visited[ny][nx] || map[ny][nx] == 'D') continue;

				visited[ny][nx] = true;
				if (map[ny][nx] == 'F') {
					List<Integer> list = new ArrayList<>();
					list.add(ny);
					list.add(nx);
					searchedMap.put(list, nd);
				}
				q.offer(new int[] {ny, nx, nd});
			}
		}
		
		if (searchedMap.isEmpty()) {
			System.out.println("-1");
			return;
		}
		
		visited = new boolean[N][M];
		q = new LinkedList<>();
		q.add(new int[] {hPos[0], hPos[1], 0});
		visited[hPos[0]][hPos[1]] = true;
		
		int min = Integer.MAX_VALUE;
		while (!q.isEmpty()) {
			int[] now = q.poll();
			
			for (int i = 0; i < 4; i++) {
				int ny = now[0] + dy[i];
				int nx = now[1] + dx[i];
				int nd = now[2] + 1;
				
				if (ny < 0 || ny >= N || nx < 0 || nx >= M || 
						visited[ny][nx] || map[ny][nx] == 'D') continue;

				visited[ny][nx] = true;
				List<Integer> list = new ArrayList<>();
				list.add(ny);
				list.add(nx);
				if (map[ny][nx] == 'F' && searchedMap.containsKey(list)) {
					int distance = searchedMap.get(list);
					if (distance + nd < min) {
						min = distance + nd;
					}
				}
				
				q.offer(new int[] {ny, nx, nd});
			}
		}

		if (min == Integer.MAX_VALUE) {
			min = -1;
		}
		System.out.println(min);
	}
}
