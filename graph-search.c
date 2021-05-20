#include <stdio.h>
#include <stdlib.h>

typedef struct graphnode {
	int vertex;
	struct graphnode* link;
} GraphNode;

#define MAX_STACK_SIZE		10
GraphNode* stack[MAX_STACK_SIZE];
int top = -1;

GraphNode* pop();
void push(GraphNode* aNode);

#define MAX_QUEUE_SIZE		10
GraphNode* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

GraphNode* deQueue();
void enQueue(GraphNode* aNode);


int initialize(GraphNode** h); 
void freeVERTEX(GraphNode* ptr);  
int insertVertex(GraphNode* h, int v);   
int insertEdge(GraphNode* h, int v, int w);  
void DFS(GraphNode* h, int v);  
void BFS(GraphNode* h, int v);  
void printGraph(GraphNode* h);  


int main()
{
	char command;
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
	
}

void push(GraphNode* aNode)	{	
		
}

void DFS(GraphNode* h, int v) {
	
}


GraphNode* deQueue() {
	
}

void enQueue(GraphNode* aNode) {
	
}

void BFS(GraphNode* h, int v) {
	
}

void printGraph(GraphNode* h) {
	
}