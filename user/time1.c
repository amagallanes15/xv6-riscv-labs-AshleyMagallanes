#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
char *argv1[] = {}; 

int
main(int argc, char **argv)
//main(void)
{
  //SHIFTING
  for(int i=1; i<sizeof(argv); i++){
  	argv1[i-1] = argv[i];
  } 
  //adding 0 to the end
  argv1[sizeof(argv)]=0;
  //CALLING UPTIME --before fork()
  int time1=uptime();
  printf("Time: %d\n", time1);
  int pid = fork();
  
  //error
  if(pid < 0){
      printf("time1: fork failed\n");
      exit(1);
      
  //child
  }else if(pid == 0){
  //CALLING EXEC
      exec( argv1[0] , argv1);
      printf("time1: exec time failed\n");
      exit(1);

  //parent
  }else{
      //CALLING WAIT--waiting for child process
      int wpid = wait((int *) 0);
      
      //CALLING UPTIME --after wait()
      printf("elapsed time: %d\n", uptime()-time1);
      
      if(wpid == pid){
        // the shell exited; restart it.
        exit(0);
      } else if(wpid < 0){
        printf("time1: wait returned an error\n");
        exit(1);
      } else {
        // it was a parentless process; do nothing.
      }
    
  }
  
  exit(0);
}
