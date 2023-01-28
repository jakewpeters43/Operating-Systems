#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[]) {
	
	printf("Jake Peters \n");
	int status = 0;
	int wpid;
	int pida;
	int pidb;
	
	pidb = fork();
	if(pidb ==0) {
	   printf("Child Process B is running");
	   char *args[] = {"childb", "c","programming",NULL};
	   execv("./childb",args);
	}
	if(pidb > 0) {
	   pida = fork();
	   
	      if(pida ==0){
	        printf("Child Process A is running");
	        char *args[] = {"childa", "c", "programming", NULL};
	        execv("./childa",args);
	        }
	        else if(pida > 0) {
	   while ((wpid = wait(&status)) > 0); //father waits for children
	   printf("Children Have Terminated\n");
	      printf("\nI am Parent Process:\npid:%d\nppid :%d\n", getpid(), getppid());
	      }
	  }
	  	  
	  return 0;
}


