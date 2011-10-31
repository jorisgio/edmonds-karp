#include "graph.h"

/* renvoit un pointeur vers un graphe sans branche */
Graph *create(int size) {
    Graph *g;
    int i;

    if ((g = ALLOC(Graph)) == NULL)
      ERROR(EMSG);

    /* On alloue 1.5 fois la taille nécessaire */

    if ( (g->vertices = (Edge **) malloc(size * sizeof(Edge *)) ) == NULL )
      ERROR(EMSG);

    g->vertex_nb = size ;
    g->edge_nb = 0;
    g->size = size * 1.5;

    for (i = 0; i < size; ++i)
        g->vertices[i] = NULL;

    return g;
}

/* détruit récursivement la liste d'adjacence*/
static void destructAdj(Edge *elt){
    if (elt != NULL) {
        Edge *p;
        p = elt->next;
        free(elt);
        destructAdj(p);
        }
}

/* détruit un graphe */
void destructGraph(Graph *g) {
    int i;

    for (i = 0; i < g->size; ++i)
        destructAdj( g->vertices[i] );

    free(g->vertices);
    free(g);
}

/* ajoute une branche au graphe, (Work around : Trier la liste ?) */
void addEdge(Graph *g, int src, int dst, int c) {
  Edge *p;
  if ( (p = ALLOC(Edge)) == NULL)
    ERROR(EMSG);

  p->cap = c;
  p->flow = 0;
  p->next = g->vertices[src];
  p->dst = dst;
  g->vertices[src] = p;
}
/* recherche elt dans la liste d'adjacence */
static Edge *searchList(Edge *start, int elt) {
  if (elt ==  start->dst) 
    return start;
  searchList(start->next, elt);
}

/* renvoit la branche entre src et dst */
inline Edge *findEdge(Graph *g, int src, int dst) {
  searchList(g->vertices[src],dst);
}

void incrAttr(Graph *g, int src, int dst, int flow, int cap) {
  Edge *p;
  p = findEdge(g, src, dst);
  p->flow += flow;
  p->cap += cap;
}

void incrCap(Graph *g, int src, int dst, int cap) {
  Edge *p;
  p = findEdge(g, src, dst);
  p->cap += cap;
}

/* applique la fonction f sur toutes les branches du graphe, 
parce que Ocaml, c'est bien, et l'ordre supèrieur aussi. */
void iterEdges(void (*f)(Edge *), Graph *g) {
  int i;
  Edge *cur;

  for (i = 0; i < g->vertex_nb; ++i)
    for (cur = g->vertices[i]; cur != NULL; cur = g->vertices[i]->next) 
      (*f)(cur);
}


/* 
 ** Code mort **

ajoute un noeud au graphe 
void addVertex(Graph *g) {
    ++g->vertex_nb;
    if ( g->vertex_nb == g->size)
        if ( g->vertices = (Edge **) realloc((void *) g->vertices, g->size *= 2, NULL)
            ERROR;

    g->vertices[g->vertex_nb] = NULL;

}

 supprime un noeud du graphe, ouai c'est plutôt horrible comme implémentation ça…
 Une table de hashage serait plus adaptée mais on s'en fou parce qu'on ne veut pas
 enlever de noeuds de manière générale 
void removeVertex(Graph *g, int index)
*/

