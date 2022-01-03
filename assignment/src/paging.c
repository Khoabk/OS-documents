
#include "mem.h"
#include "cpu.h"
#include "loader.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	if (argc < 2) {
		printf("Cannot find input process\n");
		exit(1);
	}
	struct pcb_t * proc = load(argv[1]);
	unsigned int i;
	
	
	//readlog = fopen(argv[2],"w");
	
	
	
	
	for (i = 0; i < proc->code->size; i++) {
		run(proc);
	}
	

	dump();
	
	
	//fclose(readlog);
	
	
	return 0;
}

