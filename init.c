#include "init.h"
#include "cmd.h"

void init_t_shell() {
  char *username = (char *)malloc(sizeof(char) * USERNAME_MAX_SIZE);
  printf("Please enter your username: ");
  scanf("%s", username);
  printf("Logged in as %s.\n", username);
  struct Commands *cmds = create_commands();
  /* Init shell with basic commands. */
  push_new_command(cmds, create_command("ls"));
  push_new_command(cmds, create_command("cd"));
  push_new_command(cmds, create_command("pwd"));
}
