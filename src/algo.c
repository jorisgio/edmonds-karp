#include <math.h>

#include "ek.h"
#include "graph.h"


/* FIFO */
struct stack {
  int size;
  int *cur;
  int *stack;
};

static void push(struct stack *s, int elt) {
  if ( s->cur - s->stack ==  s->size )
    if ( (s->stack = (struct stack *) realloc(s->stack, s->size *= 2)) == NULL )
      ERROR(EMSG);
  *(++s->cur)= elt;
    
}

static int pop(struct stack *s) {

  if ( s->cur == s->stack) 
    ERROR("Stack is empty, can't pop");

  if (s->cur - s->stack <= s->size / 2 )
    if( (s->stack = (struct stack *) realloc(s->stack, (s->size = (s->size - s->size / 4) ))) == NULL)
      ERROR(EMSG);

  return *(s->cur--);

}
    

/* parcours en profondeur depuis s */

int *dfs(Graph *g, int s, int t) {
  int p[g->vertex_nb],u, *v;
  memset(p,(-1), g->vertex_nb * sizeof(int));

  struct stack fifo;
  
  if ( ( fifo.stack = (int *) malloc(g->edge_nb * sizeof(int) / 2)) == NULL)
    ERROR(EMSG);
  fifo.size = g->edge_nb / 2 ;

  while ( ( u = pop(&fifo)) != NULL) {
    for ( v = g->vertices[u]; v != NULL; v = v->next ) {

      if ( (p[v->dst] = (-1)) &&  (v->cap > 0 ) ){
	p[v->dst] = u;
      }
      if ( t == v->dst)  {
	free(fifo.stack);
	return END;
      }
      push(&fifo, v->dst);
    }
  }
  free(fifo.stack);
  return CONTINUE;	
} 


void edmondsKarp(Graph *g, int s, int t) {
  int m, u;
  Edge *p;
  while (dfs(g, s,t) == 0 ) {
    m = INFTY;
    for (u = t,; u != s ; u = p[u]) {
      p = findEdge(g, p[u], u);
      m = min(
     
