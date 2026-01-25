# 🐚 **Minishell**

### *A minimal yet powerful UNIX shell — 42 School Project*

---

## 📌 Overview

**Minishell** is a lightweight yet fully functional UNIX shell written entirely in C, following the strict rules of the **42 School Norm v4.1**.
It replicates essential behaviors of real shells such as bash, including command parsing, pipelines, redirections, environment variables, builtins, and proper signal handling.

The project focuses on deepening knowledge of **process management**, **system calls**, **file descriptors**, **parsing**, and **memory management**.

---

## 🚀 Features

### ✔️ Builtins

All mandatory builtins have been implemented:

* `echo`
* `cd`
* `pwd`
* `env`
* `export`
* `unset`
* `exit`

Builtins that must run in the parent process are executed without forking.

---

### ✔️ Lexer & Parser

A robust parsing system capable of handling:

* Tokenization with whitespace handling
* Quoted strings: `'single'`, `"double"`
* Escape character support
* Pipes: `cmd1 | cmd2 | cmd3`
* Redirections:

  * `>`
  * `>>`
  * `<`
  * `<<` (heredoc)
* Multiple commands via lightweight AST-like structures
* Environment variable expansion (`$VAR`)

The parser is fully memory-safe and leak-free.

---

### ✔️ Execution Engine

* Pipeline execution using `fork`, `pipe`, and `dup2`
* Input/output redirection
* Heredoc implementation using temporary files
* Correct detection and execution of builtins
* External command execution using `execve`
* PATH resolution
* Proper exit code handling

---

### ✔️ Environment Variable System

Custom environment list implementation:

* Exporting variables
* Unsetting variables
* Passing environment to child processes
* Expanding `$VARIABLE` inside commands

---

### ✔️ Readline Integration

* Interactive prompt using `readline()`
* Command history
* CTRL key behavior:

  * `CTRL + C` → resets prompt
  * `CTRL + D` → exits shell
  * `CTRL + \` → ignored (matching bash)

---

### ✔️ Signal Handling

* Parent process uses custom signal handlers
* Child processes restore default behavior
* Bash-like signal interpretation
* Prevents prompt corruption on interrupts

---

### ✔️ Memory Safety

* No memory leaks
* All commands, tokens, environment lists, heredocs, and parser structures properly freed
* Temporary heredoc files cleaned automatically

---

## 📂 Project Structure

```
minishell/
│── Makefile
│── include/
│   ├── minishell.h
│   ├── parser.h
│   ├── exec.h
│   └── builtin.h
│
│── src/
│   ├── main.c
│   ├── parser.c
│   ├── lexer.c
│   ├── exec.c
│   ├── builtin.c
│   ├── env.c
│   ├── signals.c
│   └── utils.c
│
└── lib/
    ├── libft/
    └── printf/
```

---

## 🔧 Build & Run

### Build the project:

```
make
```

### Run the shell:

```
./minishell
```

### Cleanup:

```
make clean
make fclean
make re
```

---

## 🧪 Example Usage

```
minishell> echo hello world
hello world

minishell> export PATH=/usr/bin
minishell> ls | grep .c > list.txt

minishell> cat << EOF
heredoc working
EOF
```

---

## 🌐 Compatibility

* Linux (Ubuntu, Debian, Arch, Fedora)
* macOS (with readline installed)
* Fully Norminette v4.1 compliant
* GCC / Clang compatible

---

## 🧩 What This Project Teaches

* Process creation & management
* Inter-process communication (pipes)
* Terminal control
* Signal handling
* Memory management
* Parsing and grammar structures
* UNIX system calls:

  * `fork`, `execve`, `pipe`, `dup2`, `waitpid`
  * `open`, `read`, `write`, `close`
  * `getcwd`, `chdir`

---

## 🔥 Possible Future Improvements

* Auto-completion (tab)
* Colored prompt themes
* Job control (`jobs`, `fg`, `bg`)
* Alias system
* `.minishellrc` config file support

---

## 📬 Contact

**Yahya Karacan**
GitHub: *https://github.com/beserion*

---

- minor update @ 2026-01-13 17:27:13.621870
- minor update @ 2026-01-13 17:27:29.484854
- minor update @ 2026-01-13 17:27:31.744849
- minor update @ 2026-01-13 17:27:37.018398
- minor update @ 2026-01-13 17:27:58.794234
- minor update @ 2026-01-14 09:30:36.929828
- minor update @ 2026-01-14 09:30:43.603653
- minor update @ 2026-01-14 09:30:56.777146
- minor update @ 2026-01-14 09:31:04.918211
- minor update @ 2026-01-14 09:31:07.642313
- minor update @ 2026-01-14 09:31:15.973288
- minor update @ 2026-01-14 11:22:59.079529
- minor update @ 2026-01-14 11:23:11.589623
- minor update @ 2026-01-15 06:36:05.497917
- minor update @ 2026-01-15 06:36:10.216422
- minor update @ 2026-01-15 06:36:16.480158
- minor update @ 2026-01-15 19:25:33.456707
- minor update @ 2026-01-15 19:25:40.780066
- minor update @ 2026-01-15 19:26:00.902496
- minor update @ 2026-01-15 19:26:07.213217
- minor update @ 2026-01-16 04:40:46.585444
- minor update @ 2026-01-16 04:40:50.886636
- minor update @ 2026-01-16 15:25:50.683983
- minor update @ 2026-01-16 15:25:53.973691
- minor update @ 2026-01-16 15:25:57.256148
- minor update @ 2026-01-16 15:26:02.543301
- minor update @ 2026-01-16 15:26:10.830504
- minor update @ 2026-01-17 04:33:21.559576
- minor update @ 2026-01-17 04:33:27.845494
- minor update @ 2026-01-17 04:33:37.127910
- minor update @ 2026-01-17 07:20:09.014396
- minor update @ 2026-01-17 07:20:21.644203
- minor update @ 2026-01-17 07:20:52.071554
- minor update @ 2026-01-17 07:20:54.359190
- minor update @ 2026-01-17 07:20:58.647802
- minor update @ 2026-01-17 07:21:02.938283
- minor update @ 2026-01-17 07:21:06.211996
- minor update @ 2026-01-17 21:19:14.583612
- minor update @ 2026-01-17 21:19:41.805957
- minor update @ 2026-01-17 21:20:03.686442
- minor update @ 2026-01-17 23:20:26.079104
- minor update @ 2026-01-17 23:20:37.681420
- minor update @ 2026-01-17 23:20:45.989932
- minor update @ 2026-01-17 23:20:58.595974
- minor update @ 2026-01-18 06:33:30.118598
- minor update @ 2026-01-18 06:33:44.029006
- minor update @ 2026-01-18 06:34:02.798759
- minor update @ 2026-01-19 01:55:43.853460
- minor update @ 2026-01-19 01:55:52.476282
- minor update @ 2026-01-19 01:56:00.734098
- minor update @ 2026-01-19 01:56:03.003120
- minor update @ 2026-01-19 01:56:06.268960
- minor update @ 2026-01-19 01:56:15.528396
- minor update @ 2026-01-19 01:56:21.048597
- minor update @ 2026-01-19 06:40:31.529437
- minor update @ 2026-01-20 20:13:32.520626
- minor update @ 2026-01-20 22:24:16.830482
- minor update @ 2026-01-20 22:24:22.217678
- minor update @ 2026-01-21 04:45:23.757992
- minor update @ 2026-01-21 04:45:57.809543
- minor update @ 2026-01-21 04:46:06.071729
- minor update @ 2026-01-21 21:29:25.467080
- minor update @ 2026-01-21 21:29:34.771130
- minor update @ 2026-01-21 21:29:42.052264
- minor update @ 2026-01-22 05:29:45.986794
- minor update @ 2026-01-22 05:29:48.322270
- minor update @ 2026-01-22 05:29:55.574391
- minor update @ 2026-01-22 13:48:53.523117
- minor update @ 2026-01-22 13:49:01.777177
- minor update @ 2026-01-22 13:49:13.363062
- minor update @ 2026-01-22 13:49:22.622330
- minor update @ 2026-01-22 19:26:01.532968
- minor update @ 2026-01-22 19:26:40.288279
- minor update @ 2026-01-23 06:37:05.507412
- minor update @ 2026-01-23 06:37:16.103315
- minor update @ 2026-01-23 06:37:46.300099
- minor update @ 2026-01-23 06:38:00.875476
- minor update @ 2026-01-23 09:32:03.236580
- minor update @ 2026-01-23 09:32:13.142978
- minor update @ 2026-01-23 09:32:23.799946
- minor update @ 2026-01-23 09:32:31.554301
- minor update @ 2026-01-23 09:32:42.214729
- minor update @ 2026-01-23 19:25:25.561783
- minor update @ 2026-01-24 07:20:55.692940
- minor update @ 2026-01-24 07:21:08.848145
- minor update @ 2026-01-24 07:21:28.388849
- minor update @ 2026-01-24 07:22:00.476606
- minor update @ 2026-01-24 10:22:53.280392
- minor update @ 2026-01-24 10:23:16.145201
- minor update @ 2026-01-24 10:23:26.600459
- minor update @ 2026-01-24 10:23:50.540159
- minor update @ 2026-01-24 10:24:00.035415
- minor update @ 2026-01-24 10:24:09.003499
- minor update @ 2026-01-24 16:26:58.402818
- minor update @ 2026-01-24 16:27:04.693666
- minor update @ 2026-01-24 16:27:09.986363
- minor update @ 2026-01-24 21:19:25.194683
- minor update @ 2026-01-24 21:19:38.780323
- minor update @ 2026-01-25 06:34:19.260038
- minor update @ 2026-01-25 06:34:21.954149
- minor update @ 2026-01-25 06:34:30.201886
- minor update @ 2026-01-25 06:34:36.448113
- minor update @ 2026-01-25 06:34:44.693586
- minor update @ 2026-01-25 06:34:58.201055
- minor update @ 2026-01-25 06:35:06.448220
- minor update @ 2026-01-25 06:35:16.952106
- minor update @ 2026-01-25 06:35:25.198656
- minor update @ 2026-01-25 10:24:02.573684
- minor update @ 2026-01-25 10:24:06.079632
- minor update @ 2026-01-25 10:24:23.837174
- minor update @ 2026-01-25 10:24:27.303307
- minor update @ 2026-01-25 14:20:17.518671
- minor update @ 2026-01-25 14:20:26.232179
- minor update @ 2026-01-25 14:20:34.838631
- minor update @ 2026-01-25 22:21:51.364328
- minor update @ 2026-01-25 22:21:59.653640