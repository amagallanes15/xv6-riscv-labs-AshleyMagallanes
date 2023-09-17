#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  //calling the uptime method provided in the user file
  unsigned int numTicks = uptime();
  //format required for when the process is called 
  printf("up %d clock ticks\n", numTicks);
    
  exit(0);
}
