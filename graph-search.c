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
	
}

int insertEdge(GraphNode* h, int v, int w) {
	
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