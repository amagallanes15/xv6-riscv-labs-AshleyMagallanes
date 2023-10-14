#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"
//#include "kernel/defs.h"

int
main(int argc, char **argv)
{
  struct pstat uproc[NPROC];

  int nprocs;
  int i;
  char *state;
  static char *states[] = {
    [SLEEPING]  "sleeping",
    [RUNNABLE]  "runnable",
    [RUNNING]   "running ",
    [ZOMBIE]    "zombie  "
  };

  nprocs = getprocs(uproc);
  if (nprocs < 0)
    exit(-1);

  printf("pid\tstate\t\tsize\tage\tpriority\tcputime\t\tppid\tname\n");
  for (i=0; i<nprocs; i++) {
    state = states[uproc[i].state];
    //RUNNABLE state so print process age (current time - ready time)
    if(uproc[i].state == RUNNABLE) { 
    	  printf("%d\t%s\t%l\t%d\t%d\t\t%d\t\t%d\t%s\n", uproc[i].pid, state,
                   uproc[i].size, (uptime() - uproc[i].readytime) ,uproc[i].priority, 		uproc[i].cputime,uproc[i].ppid,uproc[i].name);
    //NOT RUNNABLE so don't print age               
    }else{
    	printf("%d\t%s\t%l\t\t%d\t\t%d\t\t%d\t%s\n", uproc[i].pid, state,
                   uproc[i].size, uproc[i].priority,uproc[i].cputime,uproc[i].ppid,uproc[i].name);
    }
                   
  }
  
  exit(0);
}

