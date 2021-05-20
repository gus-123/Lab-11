#include <stdio.h>
#include <stdlib.h>

//그래프의 노드 구조를 구조체로 정의
typedef struct graphnode {
	int vertex;
	struct graphnode* link;
} GraphNode;

//스택을 위한 요소
#define MAX_STACK_SIZE		10
GraphNode* stack[MAX_STACK_SIZE];
int top = -1;

GraphNode* pop();
void push(GraphNode* aNode);

//큐를 위한 요소
#define MAX_QUEUE_SIZE		10
GraphNode* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

GraphNode* deQueue();
void enQueue(GraphNode* aNode);


int initialize(GraphNode** h); 

//함수 리스트
void freeVERTEX(GraphNode* ptr);  //그래프의 정점 메모리 해제 연산  
int insertVertex(GraphNode* h, int v);  //정점 추가 연산   
int insertEdge(GraphNode* h, int v, int w);  //선 추가 연산  
void DFS(GraphNode* h, int v);  //깊이 우선 탐색 연산  
void BFS(GraphNode* h, int v);  //너비 우선 탐색 연산  
void printGraph(GraphNode* h);  //그래프 출력 연산  


int main()
{
	char command;
    printf("[----- [김현민]  [2018038088] -----]");
	int v;
	int w;
    GraphNode* head = NULL;

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                         Graph Searches                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph       = z                                     \n");
		printf(" Insert Vertex          = v      Insert Edge                = e \n");
		printf(" Depth First Search     = d      Breath First Search        = b \n");
		printf(" Print Graph            = p      Quit                       = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&head);
			break;
			
        case 'q': case 'Q':
			break;
        
        case 'v': case 'V':
            printf("정점 = ");
            scanf("%d", &v);
			insertVertex(head, v);
			break;

        case 'e': case 'E':
            printf("Edge 시작 정점 = ");
            scanf("%d", &v);
            printf("Edge 마지막 정점 = ");
            scanf("%d", &w);
			insertEdge(head, v, w);
			break;

        case 'd': case 'D':
			printf("DFS탐색 시작 정점 = ");
            scanf("%d", &v);
			DFS(head, v);
			break;

        case 'b': case 'B':
			printf("BFS탐색 시작 정점 = ");
            scanf("%d", &v);
			BFS(head, v);
			break;

        case 'p': case 'P':
			printGraph(head);
			break;
		
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initialize(GraphNode** h) {
	//그래프의 정점이 null이 아닌 경우 그래프에 삽입된 모든 정점을 제거
    if (*h != NULL) {
        freeVERTEX(*h);
	}

	//head 노드를 생성
    *h = (GraphNode*)malloc(sizeof(GraphNode)*10);
    for (int i = 0; i < 10; i++) {
        (*h+i)->link = NULL;
        (*h+i)->vertex = -1;	
    }
    top = -1;
    front = rear = -1;

    return 1;
}

void freeVERTEX(GraphNode* ptr) {
    if (ptr) {
        freeVERTEX(ptr->link);
        free(ptr);
    }
}

int insertVertex(GraphNode* h, int v) {
	GraphNode* g = (h+v);  //head 노드가 v에 해당하는 정점과 연결하는 동적 메모리 할당

	if (v >= 10) {  //vertex의 번호가 10이상인 경우 
		printf("\n 그래프 정점의 개수를 초과하였습니다!");

		return 0;
	}
    g->vertex = v;  //g의 vertex에 v의 정점 주소를 저장
}

int insertEdge(GraphNode* h, int v, int w) {
	GraphNode* node1 = (GraphNode*)malloc(sizeof(GraphNode));  //삽입할 새로운 node1의 동적 메모리 할당
	GraphNode* node2 = (GraphNode*)malloc(sizeof(GraphNode));  //삽입할 새로운 node2의 동적 메모리 할당
	GraphNode* g = (h+v); //head 노드가 v에 해당하는 정점과 연결하는 동적 메모리 할당

	node1->vertex = v;  //node1의 vertex에 v의 정점 주소를 저장
	node2->vertex = w;  //node2의 vertex에 w의 정점 주소를 저장
	node1->link = node2->link = NULL;  //node1, node2의 link 초기화

	if ((h+v)->vertex == -1 || (h+w)->vertex == -1) {  //head 노드와 연결된 정점들 중 해당 정점이 없는 경우
		printf("\n 그래프에 없는 정점이 있습니다! \n");

		return 0;
	}

	while (h+v) {  //head 노드가 v에 해당하는 정점과 연결하는 경우
		if (g->link == NULL) {	//연결된 정점이 없는 경우 w의 정점을 가르킴 
			g->link = node2;	
			break;
		}

		if (g->link->vertex > w) {	//w의 정점의 값이 보다 head 노드에 연결된 정점의 값이 큰 경우 작은 정점 값의 순으로 인접리스트 생성
			node2->link = g->link;
			g->link = node2;
			break;
		}
		else {  //다음 정점이 존재 할 경우 다음 정점으로 이동
			g=g->link;	 
		}
	}
	g = (h+w);  //head 노드가 w에 해당하는 정점과 연결하는 동적 메모리 할당
	
	while (h+w) {  //head 노드가 w에 해당하는 정점과 연결하는 경우
		if (g->link == NULL) {  //연결된 정점이 없는 경우 v의 정점을 가르킴
			g->link = node1;
			break;
		}

		if (g->link->vertex > v) {  //v의 정점의 값보다 head 노드에 연결된 정점의 값이 큰 경우 작은 정점 값의 순으로 인접리스트 생성
			node1->link = g->link;
			g->link = node1;
			break;
		}
		else {  //다음 정점이 존재 할 경우 다음 정점으로 이동
			g=g->link;  
		}
	}

	return 0;
}


GraphNode* pop() {
	GraphNode* aNode = NULL;
    if (top == -1) {  //스택의 top의 위치가 -1인 경우

        return aNode;
    }
    aNode = stack[top];  //스택의 top값을 aNode의 위치에 저장
    top--;  //스택 top의 위치를 가르키는 숫자 값을 감소

    return aNode;
}

void push(GraphNode* aNode)	{	
	if (top == MAX_STACK_SIZE - 1) {  //스택의 top에 스택의 최대 사이즈-1을 한 숫자 값을 저장

        return;
    }
	++top;  //스택 top의 위치를 가르키는 숫자 값을 증가
    stack[top] = aNode;  //aNode값을 스택의 top의 위치에 저장	
}

void DFS(GraphNode* h, int v) {
	GraphNode* g = (h+v);  //head 노드가 v에 해당하는 정점과 연결하는 동적 메모리 할당
	GraphNode* node = NULL;	//ptr 노드에 스택의 출력값을 받을 동적 메모리 할당

	if ((h+v)->vertex == -1) {  //head 노드와 연결된 정점들 중 해당 정점이 없는 경우
		printf("\n 그래프에 정점이 없습니다! \n");
	}

	int visited[10] = { 0, };  //도착 여부를 확인하는 배열을 초기화

	printf("\n깊이 우선 탐색 >>");
	
	while ((h+v)->vertex != -1) {
		v = g->vertex;	//head 노드의 vertex를 v에 저장
		
		if (!visited[v]) {	//v에 해당하는 정점에 도착 하지 않은 경우
			printf("%5d", v);

			visited[v] = 1;  //정점 v에 대한 배열 값을 1로 설정
			push(h+v);  //깊이 우선 탐색을 시작하는 정점 v를 스택에 값을 추가
			g = h+v;  //해당 정점을 가진 head 노드로 이동
		}
		else { //해당 정점에 다시 도착 한 경우
			if (g->link == NULL) {	//다음 정점이 존재하지 않을 경우
				node = pop();  //ptr 노드에 스택의 값을 출력
				g = h+(g->vertex);
			}
			g = g->link;  // 다음 정점이 존재 할 경우 다음 정점으로 이동
		}

		if (top == -1) {  //stack의 위치가 -1인 경우
			break;	
		} 
	}
}


GraphNode* deQueue() {
	GraphNode* aNode = NULL;

    if (front == rear) {  //front값과 rear값이 같을 경우
        if (front != -1) {  //큐의 front의 위치가 -1인 경우
            aNode = queue[front];
            front = rear = -1;
        }

        return aNode;
    }
    aNode = queue[front];  //큐의 front값을 aNode의 위치에 저장
    front++;  //큐 front의 위치를 가르키는 숫자 값을 증가

    return aNode;	
}

void enQueue(GraphNode* aNode) {
	if (rear == MAX_QUEUE_SIZE - 1) {  //큐의 rear에 큐의 최대 사이즈-1을 한 숫자 값을 저장

        return;
    }
    if (front == -1) {  //큐의 front의 위치가 -1인 경우
        front++;  //큐 front의 위치를 가르키는 숫자 값을 증가
    }
    rear++;  //큐 rear의 위치를 가르키는 숫자 값을 증가
    queue[rear] = aNode;  //aNode값을 큐의 rear의 위치에 저장
}

void BFS(GraphNode* h, int v) {
	GraphNode* g = (h+v);  //head 노드가 v에 해당하는 정점과 연결하는 동적 메모리 할당
	
	if ((g)->vertex == -1) {  //head 노드와 연결된 정점들 중 해당 정점이 없는 경우
		printf("\n 그래프에 정점이 없습니다! \n");
	}

	int visited[10] = { 0, };	//도착 여부를 확인하는 배열을 초기화

	printf("\n너비 우선 탐색 >>  %3d", v);

	visited[v] = 1;  //정점 v에 대한 배열 값을 1로 설정
	enQueue(g);  //현재 정점 g를 큐에 추가

	while ((g)->vertex != -1) {  //head 노드와 연결된 정점들 중 해당 정점이 있는 경우
		g = deQueue();  //현재 큐에서 삭제하여 g에 추가
		for (; g; g = g->link) {  //인접한 정점이 있는 경우
			v = g->vertex;
			if (!visited[v]) {  //v에 해당하는 정점에 도착 하지 않은 경우
				printf("%5d", g->vertex);

				enQueue(g);  //현재 정점 g를 큐에 추가
				visited[v] = 1;  //정점 v에 대한 배열 값을 1로 설정
			}
		}
		break;
	}
}

void printGraph(GraphNode* h) {
	GraphNode* g;

	for (int i = 0; i < 10; i++) {
		printf("\n\t\t정점%d의 인접 리스트", i);
		
		g = h+i;
		while (g) {
			printf(" -> %d", g->vertex);
			g = g->link;
		}
	}
}