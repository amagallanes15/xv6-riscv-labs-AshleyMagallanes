struct pstat {
  int pid;     // Process ID
  int priority;
  int cputime;
  enum procstate state;  // Process state
  uint64 size;     // Size of process memory (bytes)
  int ppid;        // Parent process ID
  char name[16];   // Parent command name
  //READYTIME FIELD
  uint64 readytime;

};
struct rusage{
   uint cputime;
};
