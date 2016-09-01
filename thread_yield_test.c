#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"



void first(void * arg_ptr)
{
	printf(1, "first\n");
	printf(1, "1 stopping\n");
	thread_yield();
		
	printf(1, "1 continue\n");
	printf(1, "1 end\n");

	texit();
}

void second(void * arg_ptr)
{
	printf(1, "second\n");
	printf(1, "2 stopping\n");
	thread_yield();
	printf(1, "2 continue\n");
	printf(1, "2 end\n");
	texit();
}

void third(void *arg_ptr)
{
	printf(1, "third\n");
	printf(1, "3 end\n");
	texit();

}
int main()
{
	void *thread1 = thread_create(first, (void*) 0);	
	void *thread2 = thread_create(second, (void*) 0);
	void *thread3 = thread_create(third, (void*) 0);
	
	if((thread1 ==0)||(thread2==0)||(thread3==0)){}
	while(wait()>0);

	exit();
	return 0;
}


