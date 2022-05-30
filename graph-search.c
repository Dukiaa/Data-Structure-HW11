#include<stdio.h>
#include<stdlib.h>

#define max_Vertex 10

//필요한 헤더파일 추가
typedef struct graphNode {
	int vertex;
	struct graphNode* link;
} GraphNode;

typedef struct headNode {
	int n;
	GraphNode* headNode[max_Vertex];
} HeadNode;


//함수선언
void initialize(HeadNode** );
void insertVertex(HeadNode* Graph);
void printGraph(HeadNode* Graph);
int freeGraph(HeadNode* graph);


int main()
{
	char command;
	int v1, v2;
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

void insertVertex(HeadNode* Graph)
{
	//Graph의 개수가 10보다 많을 경우 오류 출력
	if(((Graph->n)+1)>max_Vertex)
		printf("AAAAAA!!! Error!!!!\n");

	else{
		Graph->n++;
		printf("Vertax %d insert perfect!!", Graph->n);
	}	
}

void printGraph(HeadNode* Graph) //그래프 출력 함수
{
	GraphNode* p;
	for (int i = 0; i < Graph->n; i++)
		{
			printf("\nVertex number: %d", i); 
			p = Graph->headNode[i];
			while (p)
			{
				printf(" -> %d", p->vertex);
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











