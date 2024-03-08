#include "exec.h"
#include "interactive_mode.h"
#include <stdio.h>

void do_interactive_mode() {
  char *input = (char *)malloc(sizeof(char) * MAX_INPUT_SIZE);
  while (1) {
    printf("%% ");
    scanf("%s", input);
    exec(input);
  }
}
