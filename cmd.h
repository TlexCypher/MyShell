#include <stdlib.h>

struct Command;
struct Commands;
int get_length(struct Commands *cmds);
struct Command *get_next_cmd(struct Command *cmd);
struct Command *get_prev_cmd(struct Command *cmd);
const char *get_cmd_name(struct Command *cmd);
void set_length(struct Commands *cmds, int new_length);
void set_next_cmd(struct Command *cmd, struct Command *next_cmd);
void set_prev_cmd(struct Command *cmd, struct Command *prev_cmd);
void set_cmd_name(struct Command *cmd, const char *cmd_name);
struct Command *create_command(const char *cmd_name);
struct Command *get_cmds_head(struct Commands *cmds);
struct Command *get_cmds_tail(struct Commands *cmds);
void set_cmds_head(struct Commands *cmds, struct Command *head);
void set_cmds_tail(struct Commands *cmds, struct Command *tail);
void push_new_command(struct Commands *cmds, struct Command *new_cmd);
struct Commands *create_commands();
