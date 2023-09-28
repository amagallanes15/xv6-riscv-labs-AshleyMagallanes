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
      int wpid = wait2((int *) 0, ???????????????);
      
      //CALLING UPTIME --after wait()
      int time2 = uptime();
      printf("elapsed time: %d ticks, cpu time: %d ticks, %d CPU\n", time2-time1, ???, ??);
      
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
