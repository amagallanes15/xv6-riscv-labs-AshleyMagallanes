#include "kernel/param.h"
#include "kernel/types.h"
#include "user/user.h"
#define MAXARGS 1

int 
main(int argc, char *argv[])
{
    int newpriority;
    
    if(argc < 1){
        printf("Usage: pexec <priority>\n");
        exit(-1);
    }

    newpriority = atoi(argv[1]);
    //printf("%d\n", newpriority);
    setpriority(newpriority);
    
    wait(0);
    exit(0);
}  
