#include "ek.h"
#include "graph.h"
#include <stdlib.h>

int main()
{
    Graph *g;
    errno = ENOMEM;
    ERROR(EMSG);
    g = create(100);
    destructGraph(g);
    return EXIT_SUCCESS;
}
