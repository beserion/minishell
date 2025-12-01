Final FULL minishell (work-in-progress)
- Features included:
  - readline prompt with basic filename completion (TAB)
  - parser supporting quotes, escapes, pipes, redirections, heredoc (creates /tmp temp files)
  - exec pipeline with redirections and heredoc support
  - builtins: echo, cd, pwd, env, export, unset, exit
  - utils with memory cleanup for commands and heredoc unlinking

Notes:
- Requires libreadline-dev installed (Debian/Ubuntu: sudo apt install libreadline-dev)
- This is intended as a final package you asked for; still may need polishing for full 42 Norminette compliance.
