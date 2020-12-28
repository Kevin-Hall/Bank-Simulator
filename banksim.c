#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "hw.h"


// This is the main driver file for the bank simulation.
// The `main` function takes one argument, the name of a
// trace file to use.  The test directory contains a
// short sample trace that exercises at least one interesting
// case.

int main (int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: %s trace_file\n", argv[0]);
    exit(1);
  }

  int result        = 0;
  int atm_count     = 0;
  int account_count = 0;

  // open the trace file
  result = trace_open(argv[1]);
  if (result == -1) {
    printf("%s: could not open file %s\n", argv[0], argv[1]);
    exit (1);
  }

  // Get the number of ATMs and accounts:
  atm_count     = trace_atm_count();
  printf("trace atm count : %d\n", atm_count);
  account_count = trace_account_count();
  printf("trace account count : %d\n", account_count);
  trace_close();

  // This is a table of atm_out file descriptors. It will be used by
  // the bank process to communicate to each of the ATM processes.
  int atm_out_fd[atm_count];

  // This is a table of bank_in file descriptors. It will be used by
  // the bank process to receive communication from each of the ATM processes.
  int bank_in_fd[atm_count];

  // TODO: ATM PROCESS FORKING
  // create atm processes
  for (int i=0; i <= atm_count-1; i++){
    int to_atmfd[2];
    int to_bankfd[2];

    // atm_out_fd[i] = pipe(to_atmfd);
    // bank_in_fd[i] = pipe(to_bankfd[0]);
  }

  pid_t pid;
  if ((pid = fork()) < 0) {
    close(atm_out_fd[1]);
  } else {
    //child ATM process

  }

  // TODO: BANK PROCESS FORKING


  // Wait for each of the child processes to complete. We include
  // atm_count to include the bank process (i.e., this is not a
  // fence post error!)
  for (int i = 0; i <= atm_count; i++) {
    wait(NULL);
  }

  return 0;
}
