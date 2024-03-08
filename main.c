#include "init.h"
#include "interactive_mode.h"

int main(void) {
  init_t_shell();
  while (1) {
    do_interactive_mode();
  }
}
