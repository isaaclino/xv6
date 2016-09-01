#include "semaphore.h"

struct H2O 
{
	lock_t lock;
}H2O;

int water_molecules;
int oxygen_atoms;
int hydrogen_atoms; 

struct Semaphore hydrogen_sem;
struct Semaphore oxygen_sem;



void oready(void *arg_ptr){
++oxygen_atoms;
//h.wait();
sem_acquire(&hydrogen_sem);
//h.wait();
sem_acquire(&hydrogen_sem);
//o.signal();
sem_signal(&oxygen_sem);
//o.signal();
sem_signal(&oxygen_sem);

//mutex.acquire();
lock_acquire(&H2O.lock);

//water_molecules++;
++water_molecules;
oxygen_atoms -= 1;
hydrogen_atoms -= 2;
printf(1, "\n making water molecule number %d\n", water_molecules);
printf(1, "left with this many hydrogen atoms %d\n", hydrogen_atoms);
printf(1, "left with this many oxygen atoms  %d\n", oxygen_atoms);
//mutex.release();
lock_release(&H2O.lock);
texit();
}

void hready(void *arg_ptr){
++hydrogen_atoms;
 //h.signal();
sem_signal(&hydrogen_sem);
//o.wait();
sem_acquire(&oxygen_sem);
texit();
}
int main()
{
	sem_start(&hydrogen_sem, hydrogen_atoms);	
	sem_start(&oxygen_sem, oxygen_atoms);	
	lock_init(&H2O.lock);

	/*void *thread1 = thread_create(hready, (void*) 0);
	void *thread2 = thread_create(hready, (void*) 0);
 	void *thread3 = thread_create(hready, (void*) 0);
	void *thread4 = thread_create(hready, (void*) 0);
 	void *thread5 = thread_create(hready, (void*) 0);
 	void *thread6 = thread_create(hready, (void*) 0);
 	void *thread7 = thread_create(hready, (void*) 0);
 	void *thread8 = thread_create(hready, (void*) 0);
 	void *thread9 = thread_create(hready, (void*) 0);
 	void *thread10 = thread_create(hready, (void*) 0);
 	void *thread11 = thread_create(oready, (void*) 0);
 	void *thread12 = thread_create(oready, (void*) 0);*/
 	void *thread13 = thread_create(hready, (void*) 0);
 	void *thread14 = thread_create(hready, (void*) 0);
 	void *thread15 = thread_create(oready, (void*) 0);
	
//	if(((thread1 == 0) ||(thread2 == 0) || (thread3 == 0) ||
//	(thread4 == 0) || (thread5 == 0) || (thread6 == 0) ||
//	(thread7 == 0) || (thread8 == 0) || (thread9 == 0) || 
//	(thread10 == 0) || (thread11 == 0) || (thread12 == 0) ||
        if(((thread13 == 0) || (thread14 == 0) || (thread15 == 0))){exit();}
	
	while(wait()>1);	
	exit();
	return 0;
}
