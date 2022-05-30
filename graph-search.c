#include<stdio.h>
#include<stdlib.h>

#define max_Vertex 10
int visited_Depth[max_Vertex]; //Depth First Search의 방문여부를 저장할 배열

//필요한 헤더파일 추가
typedef struct graphNode {
	int vertex;
	struct graphNode* link;
} GraphNode;

typedef struct headNode {
	int n;
	GraphNode* headNode[max_Vertex];
	 GraphNode* Vlist[max_Vertex];
} HeadNode;


//함수선언
void initialize(HeadNode** );
int insertVertex(HeadNode* Graph);
void printGraph(HeadNode* Graph);
int freeGraph(HeadNode* graph);
int insertEdge(HeadNode* Graph, int v, int u);
void Depth(HeadNode *Graph, int v);

int main()
{
	char command;
	int u, v;
	int vertex;
    HeadNode* Graph = NULL;

	printf("[----- [조정동] [2017015041] -----]\n");
	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                     	 Graph Searches	                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph     = z                                       \n");
		printf(" Insert Vertex        = v      Insert Edge                  = e \n");
		printf(" Depth First Search   = d      Breath First Search          = b \n");
		printf(" Print Graph          = p      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&Graph);
			break;
		case 'q': case 'Q':
			freeGraph(Graph);
			break;
		case 'v': case 'V':
			insertVertex(Graph);
			break;
		case 'e' : case 'E':
			printf("Enter two vertices\n\n");
			printf("u: ");
			scanf("%d", &u); //vertex u 입력
			printf("v: ");
			scanf("%d", &v); //vertex v 입력
			insertEdge(Graph, u, v);
			insertEdge(Graph, v, u);
		break;
		case 'd' : case 'D':
		printf("Enter the vertex you want to explore: ");
			scanf("%d", &vertex); //탐색하고자 하는 vertex 입력
			Depth(Graph, vertex); 
		break;

		case 'p': case 'P':
			printGraph(Graph);
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}




void initialize(HeadNode** Graph) //그래프 초기화 함수
{
	if (*Graph != NULL)
		freeGraph(*Graph);

	else{	
		*Graph = (HeadNode*)malloc(sizeof(HeadNode));
		(*Graph)->n =0;
		for(int v=0; v<max_Vertex; v++){
			(*Graph)->headNode[v] = NULL; //헤드노드 초기화
		}
	}
}

int insertVertex(HeadNode* Graph)
{	
	//Graph가 초기화 되지 않을 경우 오류 출력
	if(Graph == NULL){
        printf("AAAAAA!!! Error!!!! initialize it!!\n");
        return 1;
    }

	//Graph의 개수가 10보다 많을 경우 오류 출력
	if(((Graph->n)+1)>max_Vertex){
		printf("AAAAAA!!! Error!!!! Too many vertices!! \n");
		return 1;
	}

	else{
		Graph->n++;
		printf("\nTotal of %d vertices were entered perfectly!! ", Graph->n);
		return 0;
	}	
}

void printGraph(HeadNode* Graph) //그래프 출력 함수
{
	GraphNode* p;
	for (int i = 0; i < Graph->n; i++)
		{
			printf("\nVertex number: %d  ", i); 
			p = Graph->headNode[i];
			while (p)
			{
				printf(" [%d]", p->vertex);
				p = p->link;
			}
			printf("\n");
		}
}

int freeGraph(HeadNode* graph) //그래프 초기화 함수
{
	free(graph);
	return 1;
}

int insertEdge(HeadNode* Graph, int u, int v)
{
	//Graph가 초기화 되지 않을 경우 오류 출력
	if(Graph == NULL){
        printf("AAAAAA!!! Error!!!! initialize it!!\n");
        return 1;
    }

	//존재하지 않는 Vertex를 선택한 경우 오류 출력
	if (u >= Graph->n || v >= Graph->n || u < 0 || v < 0)
	{
		printf("\nAAAAAA!!! Error!!!! Entered vertex is not in the graph!!\n");
		return 1;
	}

	//node 생성
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));

	node->vertex = v; //node를 정점에 연결
	node->link = Graph->headNode[u];
	Graph->headNode[u] = node;
	return 0;

	
}

void Depth(HeadNode* Graph,int v)
{
	GraphNode* w;
	visited_Depth[v]=1; //vertex를 방문했음을 표시
	printf("%d ",v); //방문한 vertex 출력

	for(w=Graph->headNode[v];w;w=w->link)
	{
		if(!visited_Depth[w->vertex]) //방문한적이 없으면 재귀함수 발동
			Depth(Graph,w->vertex);
	}
}





