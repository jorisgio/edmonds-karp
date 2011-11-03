#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "ek.h"

/* type des branches, liste d'adjacence */
typedef struct edge { /* workaround : un tableau à la place d'une liste chainée ?*/
  int cap;            /*capacité de la bracnhe */
  int flow;           /* flux courant de la branche */
  int dst;          /* Noeud destination de la branche */
  struct edge *next;  /* Branche suivante dans la liste d'adjacence */ 
} Edge ;

typedef struct graph {
    int vertex_nb;      /* nombre de noeuds dans le graphe */
    int edge_nb;        /* nombre de branches */
    Edge **vertices;    /* table des noeuds, contenant des pointeurs vers des sutructures Edge*/
    } Graph;

Graph *create(int size);

void destructGraph(Graph *g) ;
int addEdge(Graph *g, int src, int dst, int c);
int addVertex(Graph *g);
Edge *findEdge(Graph *g, int src, int dst);
void incrAttr(Graph *g, int src, int dst, int flow, int cap);
void incrCap(Graph *g, int src, int dst, int cap);

#endif // GRAPH_H_INCLUDED
