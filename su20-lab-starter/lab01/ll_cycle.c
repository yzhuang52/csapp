#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    if(!head){
    	return 0;
    }
    node *walker = head;
    node *runner = head;
    while(runner && runner->next){
    	runner = runner->next->next;
	walker = walker->next;
	if(walker==runner){
		return 1;
	}
    }
    return 0;
}
