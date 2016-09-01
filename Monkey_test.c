#include "semaphore.h"

int monkeys;
int doms;


struct monkey{
	lock_t lock;
}monkey;


struct Semaphore Mon;
struct Semaphore Dom;


void Monkey(void * arg_ptr){




texit();
}

void dom(void *arg_ptr){



texit();
}









int main(){

	sem_start(&Mon, 3);
	sem_start(&Dom, 1);
	lock_init(&monkey.lock);

	void *thread1 = thread_create(Monkey, (void*) 0);
	void *thread2 = thread_create(Monkey, (void*) 0);
	void *thread3 = thread_create(Monkey, (void*) 0);
	void *thread4 = thread_create(Monkey, (void*) 0);
	void *thread5 = thread_create(Monkey, (void*) 0);
	void *thread6 = thread_create(Monkey, (void*) 0);
	/*void *thread7 = thread_create(M, (void*) 0);
	void *thread8 = thread_create(M, (void*) 0);
	void *thread9 = thread_create(M, (void*) 0);
	void *thread10 = thread_create(M, (void*) 0);
	void *thread11 = thread_create(M, (void*) 0);
	void *thread12 = thread_create(M, (void*) 0);*/
	void *thread13 = thread_create(dom, (void*) 0);
	void *thread14 = thread_create(Monkey, (void*) 0);
	void *thread15 = thread_create(dom, (void*) 0);
	
	if(((thread1 == 0) ||(thread2 == 0) || (thread3 == 0) ||
	(thread4 == 0) || (thread5 == 0) || (thread6 == 0) ||
	//(thread7 == 0) || (thread8 == 0) || (thread9 == 0) ||
	//(thread10 == 0) || (thread11 == 0) || (thread12 == 0) ||
	(thread13 == 0) || (thread14 == 0) || (thread15 == 0))){exit();}
	
	while(wait()>2);
	exit();
	return 0;







	return 0;
}


