#include "ek.h"
#include "algo.h"

#include <stdlib.h>
#include <ctype.h>

void parse(FILE *fd,Graph *g) {
  char c ;
  int src, dst;
  while ((c = getc (fd)) != EOF ) {
	fscanf(fd,"%d :", &src);
	while (c != '\n') {
	  	if (fscanf(fd,"%d%c", &dst, &c) != 2) {
			c = '\n';
			break;
		  }
	  	addEdge (g,src,dst,10);
	  	fprintf(stderr,"Edge %d %d created\n", src, dst);
	}
  }
}

int main(int argc, char *argv[])
{
  	int size;
    Graph *gr;
  	FILE *fd;
  	if(argc != 3){
		return 1;	
	  }
	size = atoi (argv[1]);
  	printf("%d\n", size);
    gr = create(size);
  	printf("Created\n");
  	fd = fopen(argv[2],"r");
	parse(fd,gr);
  	fclose (fd);
  	edmondsKarp (gr,0,size);
    destructGraph(gr);
    return EXIT_SUCCESS;
}
