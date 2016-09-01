#include "types.h"
#include "queue.h"
#include "user.h"

struct Semaphore 
{
	struct queue sem_q;
	int count;
	lock_t sem_lock;
};
	

void sem_acquire(struct Semaphore *s){
	lock_acquire(&s->sem_lock);
	int flag = 0;	
	
	if (s->count <= 0){
		add_q(&s->sem_q, getpid());
		flag = 1;
	}	
	else{
		s->count--;
		flag = 0;
	}
	
	lock_release(&s->sem_lock);
	if(flag == 1){tsleep();}
}



void sem_signal(struct Semaphore *s){
	lock_acquire(&s->sem_lock);
	
	if(!empty_q(&s->sem_q)){
		int temp;
		temp = pop_q(&s->sem_q);
		twakeup(temp);
	}
	else{
		s->count++;
	}
		
	lock_release(&s->sem_lock);
}

void sem_start(struct Semaphore *s, int start_value){
	s->count = start_value;
	lock_init(&s->sem_lock);
	init_q(&s->sem_q);



}



