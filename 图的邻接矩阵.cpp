// 顶点类型应由用户定义
typedef char VertexType;
// 边上的权值类型应由用户定义
typedef int EdgeType;
// 最大顶点数，应由用户定义

#define INFINITY 65535
typedef struct{
    // 顶点表
    VertexType vexs[MAXVEX];
    // 邻接矩阵，可看作边表
    EdgeType arc[MAXVEX][MAXVEX];
    // 图中当前的顶点数和边数
    int numVertexes,numEdges;
}MGragh;

void CreateMGragh(MGragh *G){
    int i,j,k,w;
    printf("输入顶点数和边数：\n");
    // 输入顶点数和边数
    scanf("%d,%d",&G->numVertexes,&G->numEdges);
    // 读入顶点信息，建立顶点表
    for(i=0;i<G->numVertexes;i++)
        scanf(&G->vexs[i]);
    for(i=0;i<G->numVertexes;i++)
        for(j=0;j<G->numVertexes;j++)
            // 邻接矩阵初始化
            G->arc[i][j]=INFINITY;
    // 读入numEgdes条边，建立邻接矩阵
    for(k=0;k<G->numEdges;k++)
    {
        printf("输入边(vi,vj)上的下标i，下标j和权w：\n");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j]=w;
        // 因为是无向图，矩阵对称
        G->arc[j][i]=w;
    }
}
