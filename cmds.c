#include "cmd.h"

struct Commands {
  int length;
  struct Command *head;
  struct Command *tail;
};

struct Command {
  const char *cmd_name;
  struct Command *next;
  struct Command *prev;
};

int get_length(struct Commands *cmds) { return cmds->length; }
struct Command *get_next_cmd(struct Command *cmd) { return cmd->next; }
struct Command *get_prev_cmd(struct Command *cmd) { return cmd->prev; }
const char *get_cmd_name(struct Command *cmd) { return cmd->cmd_name; }
void set_length(struct Commands *cmds, int new_length) {
  cmds->length = new_length;
}
void set_next_cmd(struct Command *cmd, struct Command *next_cmd) {
  cmd->next = next_cmd;
}
void set_prev_cmd(struct Command *cmd, struct Command *prev_cmd) {
  cmd->prev = prev_cmd;
}
void set_cmd_name(struct Command *cmd, const char *cmd_name) {
  cmd->cmd_name = cmd_name;
}

struct Command *create_command(const char *cmd_name) {
  struct Command *new_cmd =
      (struct Command *)malloc(sizeof(struct Command) * 1);
  set_cmd_name(new_cmd, cmd_name);
  set_next_cmd(new_cmd, NULL);
  set_prev_cmd(new_cmd, NULL);
  return new_cmd;
}

struct Command *get_cmds_head(struct Commands *cmds) { return cmds->head; }
struct Command *get_cmds_tail(struct Commands *cmds) { return cmds->tail; }
void set_cmds_head(struct Commands *cmds, struct Command *head) {
  cmds->head = head;
}
void set_cmds_tail(struct Commands *cmds, struct Command *tail) {
  cmds->head = tail;
}

void push_new_command(struct Commands *cmds, struct Command *new_cmd) {
  if (cmds->head == NULL) {
    set_cmds_head(cmds, new_cmd);
  } else if (cmds->tail == NULL) {
    set_cmds_tail(cmds, new_cmd);
    set_next_cmd(get_cmds_head(cmds), new_cmd);
  } else {
    struct Command *current_tail = cmds->tail;
    set_cmds_tail(cmds, new_cmd);
    set_next_cmd(current_tail, new_cmd);
    set_prev_cmd(new_cmd, current_tail);
  }
  set_length(cmds, get_length(cmds) + 1);
}

struct Commands *create_commands() {
  struct Commands *cmds =
      (struct Commands *)malloc(sizeof(struct Commands) * 1);
  set_length(cmds, 0);
  set_cmds_head(cmds, NULL);
  set_cmds_tail(cmds, NULL);
  return cmds;
}
