#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}



void reheap_up(struct queue_t * q)
{

	int pos = q->size - 1;
	
	int parent;
	
	do{
	
	parent = (pos-1)/2;
	
	if(q->proc[parent]->priority < q->proc[pos]->priority)
	{
		 struct pcb_t * temp = q->proc[parent];
                q->proc[parent] = q->proc[pos];
                q->proc[pos] = temp;
		 pos = parent;
	}
	else break;
	
	}while(pos >0);

}



void reheap_down(struct queue_t * q, int current_pos)
{

	int left = 2*current_pos + 1;
	
	int right = 2*current_pos + 2;
	
	if(left >= q->size)return;

	int pos = (right >= q->size)?left:(q->proc[right]->priority > q->proc[left]->priority)?right:left;
	
	if(q->proc[current_pos]->priority < q->proc[pos]->priority)
	{
	
	struct pcb_t * temp = q->proc[current_pos];
	
	q->proc[current_pos] = q->proc[pos];
	
	q->proc[pos] = temp;
	
	reheap_down(q,pos);
	
	}
	
	
}




void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	
	
   if(q->size == MAX_QUEUE_SIZE)
   {    
 	puts("Queue is full");   
     
 	return;
    }
	     	
  if (q->size == 0)
  {
	q->proc[0] = proc;
	    
        q->size += 1;
  }
  
  else
  {
       q->proc[q->size++] = proc;         
      					
       reheap_up(q);
  }
	
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	 
	 if(empty(q))return NULL; 

	 struct pcb_t* highest_prior = q->proc[0];

        // replace the first item with the last item
         q->proc[0] = q->proc[--q->size];
        
      
        // maintain the heap property by heapifying the 
        // first item
       
       
         reheap_down(q,0);
         
         
         return highest_prior;
	
}

