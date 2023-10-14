#include "kernel/param.h"
#include "kernel/types.h"
#include "user/user.h"
#define MAXARGS 16

int 
main(void)
{
    printf("%d\n",getpriority());
    exit(0);
}
    
