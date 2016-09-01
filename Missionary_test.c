#include "semaphore.h"

int missionaries = 0;
int cannibals = 0;

int mflag;
int cflag;
struct mc{
	lock_t lock;
}mc;

int c, m;
struct Semaphore missionary_sem;
struct Semaphore cannibal_sem;

//Void NORowBoat(){ ready }
void DONTRowBoat(){
	printf(1, "\nNOT Ready to row\n");
}

//Void RowBoat(){ ready }
void RowBoat(){
	printf(1, "\nReady to row\n");
}

void MissionaryArrives (void *arg_ptr)
{
	//acquire_mutex();
 
	//lock_acquire(&mc.lock);
 
	//if(missionaries == cannibals == 1){
	if((missionaries == 1) && (cannibals == 1)){
		//Wait_for_missionary_Signal();
		sem_signal(&missionary_sem);
		//Wait_for_cannibal_Signal();
		sem_signal(&missionary_sem);

		RowBoat();
	
	}
	//else if(missionaries == 2){
	else if(missionaries == 2){
		//Wait_for_missionary_Signal();
		sem_signal(&missionary_sem);
		//Wait_for_cannibal_Signal();
		sem_signal(&missionary_sem);

		RowBoat();
	}
	//Else{
	else{
		++missionaries;

		sem_acquire(&missionary_sem);

		--missionaries;
		//lock_release(&mc.lock);
	}
	//release_mutex();
	lock_release(&mc.lock);
texit();
}

void CannibalArrives(void *arg_ptr)
{
	//acquire_mutex();
	lock_acquire(&mc.lock);
	//if(missionaries == 2){
	if(missionaries == 2){
		//Wait_for_missionary_Signal();
		sem_signal(&missionary_sem);
		//Wait_for_missionary_Signal();
		sem_signal(&missionary_sem);
		//RowBoat();
		//lock_acquire(&mc.lock);
		//++c;
		RowBoat();

		//lock_release(&mc.lock);
	}
	//elseif(cannibals == 2){
	else if(cannibals == 2){
		//Wait_for_cannibal_Signal();
		sem_signal(&cannibal_sem);
		//Wait_for_cannibal_Signal();}
		sem_signal(&cannibal_sem);
		//lock_acquire(&mc.lock);
		RowBoat();
		
		//lock_release(&mc.lock);
		
	}
	else{
		cannibals++;

		sem_acquire(&cannibal_sem);
		//lock_release(&mc.lock);
   
		//Decrease_cannibals
    cannibals++;

					
	}
	//release_mutex();
	lock_release(&mc.lock);
texit();
}



int main(){

	sem_start(&cannibal_sem, cannibals);
	sem_start(&missionary_sem, missionaries);
	lock_init(&mc.lock);
	printf(1, "missionary, cannibal, missionary, cannibal, missionary, cannibal");
	void *thread1 = thread_create(MissionaryArrives, (void*) 0);
	void *thread2 = thread_create(CannibalArrives, (void*) 0);
	void *thread3 = thread_create(MissionaryArrives, (void*) 0);
	//void *thread14 = thread_create(MissionaryArrives, (void*) 0);
	//void *thread3 = thread_create(CannibalArrives, (void*) 0);
	//void *thread7 = thread_create(CannibalArrives, (void*) 0);
	//void *thread8 = thread_create(CannibalArrives, (void*) 0);
	//void *thread9 = thread_create(CannibalArrives, (void*) 0);
	//void *thread10 = thread_create(CannibalArrives, (void*) 0);
	//void *thread11 = thread_create(CannibalArrives, (void*) 0);
	//void *thread12 = thread_create(CannibalArrives, (void*) 0);
	void *thread13 = thread_create(CannibalArrives, (void*) 0);
	void *thread14 = thread_create(MissionaryArrives, (void*) 0);
	//void *thread14 = thread_create(CannibalArrives, (void*) 0);
	void *thread15 = thread_create(CannibalArrives, (void*) 0);
	
	if(((thread1 == 0) ||(thread2 == 0) || (thread3 == 0) ||
	//(thread4 == 0) || (thread5 == 0) || (thread6 == 0) ||
	//(thread7 == 0) || (thread8 == 0) || (thread9 == 0) ||
	//(thread10 == 0) || (thread11 == 0) || (thread12 == 0) ||
	(thread13 == 0) || (thread14 == 0) || (thread15 == 0))){exit();}
	
	while(wait()>1);
	exit();
	return 0;







	return 0;
}


