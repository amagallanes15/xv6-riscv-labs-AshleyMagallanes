#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char *argv[] = { "time1", "matmul" , 0 };

int
main(void)
{
  int pid = fork();
  if(pid < 0){
      printf("time1: fork failed\n");
      exit(1);
  }else if(pid == 0){
  //CALLING EXEC
      exec("/bin/time1", argv);
  
      printf("time1: exec time failed\n");
      exit(1);
  //CALLING WAIT
  }else{
  
      //CALLING UPTIME
      printf("Time: %d\n", uptime());
      int wpid = wait((int *) 0);
      
      //CALLING UPTIME
      printf("elapsed time: %d\n", uptime());
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
