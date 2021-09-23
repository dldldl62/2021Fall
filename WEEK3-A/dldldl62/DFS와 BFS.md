# DFS와 BFS

### 0. 그래프란?

- 노드(node)와 그 노드를 연결하는 간선(edge)을 하나로 모아 놓은 자료구조

  - 방향 그래프, 무방향 그래프
  - 루트노드 및 부모자식 개념 없음
  - 순회방법 : DFS, BFS
  - 예시 : 지하철노선도, SNS에서 사람들간의 관계 등

  *트리 : **방향성이 있는 비순환 그래프**



### 1. DFS

> 깊이 우선 탐색, Depth-First Search

- 시작점부터 다음 분기로 넘어가기 전에 해당 분기를 완벽하게 탐색하고 넘어가는 방법

  - 구현 : 재귀함수 또는 스택

  - 현재 노드에서 갈 수 있는 점들을 들어가면서 **모든 노드** 탐색

  - **경로의 특징**을 기억해야할 때 유리

    👍 BFS에 비해 구현 간단, 현재 branch에 대한 정보만 갖고 있어도 돼서 메모리공간 효율적

    👎 BFS에 비해 검색 속도가 느림



### 2. BFS

> 너비 우선 탐색, Breadth-First Search

- 시작점에서 인접한 노드를 먼저 탐색하는 방법
  - 구현 : 큐

  - 두 노드 사이 **최단 경로** / 임의의 경로 찾을 때 유리

    👍 최단 경로를 찾을 때 DFS에 비해 효율적

    👎 DFS에 비해 메모리 공간을 많이 차지



🕐 DFS와 BFS의 시간복잡도

- 두 방식 모두 모든 노드를 검색하므로 시간 복잡도는 동일
  - N : 노드, E : 간선

$$
인접 리스트 : O(N+E)\\
인접행렬 : O(N^2)
$$



### 3. 구현

- DFS (재귀)

```c++
void DFS(int index){
  check_dfs[index] = true; //해당 정점을 방문했는지 확인
  printf("%d ",index); //방문한 정점 출력
  
  for(int i=0; i<v[index].size(); ++i){ 
    int next = v[index][i];
    
    if(!check_dfs[next]){ //방문하지 않았다면 DFS() 호출
      DFS(next);
    }
  }
}
```



- BFS

```c++
void BFS(){
  queue<int> q;
  q.push(0); //시작점 저장
  check_bfs[0] = true;
  
  while(!q.empty()){
    int current = q.front();
    q.pop();
    printf("%d ",current);
    
    for(int i=0; i<v[current].size(); i++){
      int next = v[current][i];
      
      if(!check_bfs[next]){
        check_bfs[next] = true;
        q.push(next);
      }
    }
  }
}
```

