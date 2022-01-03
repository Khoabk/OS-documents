#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>



void* aligned_malloc(unsigned int size, unsigned int align)
{
	void *p;
 	sbrk(0);
	p= sbrk(0);

	long unsigned offset = (long unsigned)(p)%align;

if(offset==0){if(sbrk(size) == (void*)-1)return NULL;
	return p; }


if(sbrk(size + align - offset)== (void*)-1)return NULL;

p+=(align - offset);

return p;

}

void * aligned_free(void *ptr)
{
	brk(ptr);
	ptr= NULL;
	return ptr;
}

