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
- minor update @ 2026-01-25 22:22:03.934811
- minor update @ 2026-01-25 22:22:10.226374
- minor update @ 2026-01-25 22:22:13.524583
- minor update @ 2026-01-25 22:22:18.815097
- minor update @ 2026-01-26 15:30:36.793867
- minor update @ 2026-01-26 15:30:40.438832
- minor update @ 2026-01-26 15:30:46.721486
- minor update @ 2026-01-26 15:30:56.996497
- minor update @ 2026-01-26 15:31:18.162785
- minor update @ 2026-01-26 15:31:24.439945
- minor update @ 2026-01-26 21:25:53.634878
- minor update @ 2026-01-26 21:26:00.913862
- minor update @ 2026-01-28 08:34:38.009994
- minor update @ 2026-01-28 08:34:45.552056
- minor update @ 2026-01-28 08:34:48.086485
- minor update @ 2026-01-28 08:35:02.904763
- minor update @ 2026-01-28 08:35:15.058805
- minor update @ 2026-01-28 08:35:18.342483
- minor update @ 2026-01-28 10:30:50.716486
- minor update @ 2026-01-28 10:31:02.935638
- minor update @ 2026-01-28 10:31:13.153935
- minor update @ 2026-01-28 21:30:56.304917
- minor update @ 2026-01-28 21:30:59.963185
- minor update @ 2026-01-28 21:31:16.271385
- minor update @ 2026-01-28 21:31:19.572136
- minor update @ 2026-01-29 22:29:34.054879
- minor update @ 2026-01-30 11:29:38.117591
- minor update @ 2026-01-30 15:35:59.389788
- minor update @ 2026-01-30 15:36:07.880404
- minor update @ 2026-01-30 18:44:58.723794
- minor update @ 2026-01-30 22:27:35.676236
- minor update @ 2026-01-30 22:27:37.928825
- minor update @ 2026-01-31 02:03:40.479223
- minor update @ 2026-01-31 13:41:26.202917
- minor update @ 2026-01-31 13:41:44.787382
- minor update @ 2026-02-04 09:45:53.454879
- minor update @ 2026-02-04 22:29:45.087835
- minor update @ 2026-02-04 22:29:53.345036
- minor update @ 2026-02-05 14:43:26.292079
- minor update @ 2026-02-07 06:43:34.744949
- minor update @ 2026-02-07 07:32:45.877841
- minor update @ 2026-02-07 07:32:54.483422
- minor update @ 2026-02-07 14:27:43.694411
- minor update @ 2026-02-07 16:32:10.294100
- minor update @ 2026-02-07 16:32:14.962482
- minor update @ 2026-02-08 11:24:14.582978
- minor update @ 2026-02-08 11:24:18.190906
- minor update @ 2026-02-08 21:27:56.631724
- minor update @ 2026-02-09 14:53:20.235862
- minor update @ 2026-02-09 14:53:33.394939
- minor update @ 2026-02-09 15:57:23.867964
- minor update @ 2026-02-10 02:32:46.294781
- minor update @ 2026-02-10 02:33:03.533782
- minor update @ 2026-02-10 21:49:05.338347
- minor update @ 2026-02-11 13:14:11.649047
- minor update @ 2026-02-12 09:52:29.506380
- minor update @ 2026-02-15 17:26:40.100408
- minor update @ 2026-02-15 17:26:49.590905
- minor update @ 2026-02-15 17:27:03.946683
- minor update @ 2026-02-16 08:51:19.367566
- minor update @ 2026-02-16 08:51:51.605191
- minor update @ 2026-02-16 20:33:52.269538
- minor update @ 2026-02-16 20:34:12.037074
- minor update @ 2026-02-17 10:48:12.113822
- minor update @ 2026-02-17 11:40:02.156094
- minor update @ 2026-02-17 11:40:14.358598
- minor update @ 2026-02-17 16:59:10.124311
- minor update @ 2026-02-18 07:51:11.673706
- minor update @ 2026-02-18 07:51:15.896024
- minor update @ 2026-02-18 10:46:28.501909
- minor update @ 2026-02-18 10:46:41.692278
- minor update @ 2026-02-18 11:39:18.201010
- minor update @ 2026-02-18 11:39:49.574410
- minor update @ 2026-02-18 15:54:04.728201
- minor update @ 2026-02-19 07:12:44.190549
- minor update @ 2026-02-19 07:12:57.432864
- minor update @ 2026-02-19 07:13:16.624365
- minor update @ 2026-02-19 15:50:31.397007
- minor update @ 2026-02-19 20:35:04.926561
- minor update @ 2026-02-20 07:52:15.579461
- minor update @ 2026-02-20 07:52:23.901146
- minor update @ 2026-02-20 13:01:14.251792
- minor update @ 2026-02-20 16:41:13.525368
- minor update @ 2026-02-20 16:41:27.733897
- minor update @ 2026-02-20 22:27:58.608440
- minor update @ 2026-02-20 22:28:05.961426
- minor update @ 2026-02-20 22:28:17.543395
- minor update @ 2026-02-21 13:42:21.367128
- minor update @ 2026-02-21 13:43:10.057817
- minor update @ 2026-02-21 17:26:49.434996
- minor update @ 2026-02-21 17:26:53.690028
- minor update @ 2026-02-21 17:27:03.943120
- minor update @ 2026-02-22 13:44:35.924412
- minor update @ 2026-02-22 13:44:54.135787
- minor update @ 2026-02-22 19:25:49.482119
- minor update @ 2026-02-22 19:26:19.206854
- minor update @ 2026-02-22 20:28:41.807782
- minor update @ 2026-02-25 13:08:00.014719
- minor update @ 2026-02-25 13:08:12.259503
- minor update @ 2026-02-26 10:48:47.738776
- minor update @ 2026-02-26 10:48:59.710976
- minor update @ 2026-02-26 19:42:49.905413
- minor update @ 2026-02-26 23:31:34.346766
- minor update @ 2026-02-28 04:59:59.784415
- minor update @ 2026-02-28 05:41:09.137534
- minor update @ 2026-02-28 05:41:12.408235
- minor update @ 2026-02-28 05:41:25.180044
- minor update @ 2026-02-28 05:41:31.434627
- minor update @ 2026-02-28 06:40:04.095098
- minor update @ 2026-02-28 06:40:16.678379
- minor update @ 2026-02-28 06:40:23.296043
- minor update @ 2026-03-01 13:39:35.959218
- minor update @ 2026-03-01 15:25:04.229439
- minor update @ 2026-03-01 20:28:47.693362
- minor update @ 2026-03-01 20:28:54.993630
- minor update @ 2026-03-02 18:51:20.961040
- minor update @ 2026-03-02 18:51:45.634630
- minor update @ 2026-03-02 18:51:52.478427
- minor update @ 2026-03-03 05:50:55.465691
- minor update @ 2026-03-03 05:51:03.338226
- minor update @ 2026-03-03 05:51:16.327672
- minor update @ 2026-03-03 05:51:30.300535
- minor update @ 2026-03-03 11:34:01.904782
- minor update @ 2026-03-03 19:39:33.849175
- minor update @ 2026-03-03 19:39:44.191489
- minor update @ 2026-03-03 19:39:52.457434
- minor update @ 2026-03-04 07:38:08.127259
- minor update @ 2026-03-04 07:38:29.083115
- minor update @ 2026-03-04 22:33:04.385357
- minor update @ 2026-03-05 07:43:00.833889
- minor update @ 2026-03-05 13:03:30.196788
- minor update @ 2026-03-05 18:05:19.743343
- minor update @ 2026-03-05 18:05:36.948334
- minor update @ 2026-03-05 18:05:55.143559
- minor update @ 2026-03-05 19:52:22.688257
- minor update @ 2026-03-05 19:52:28.344459
- minor update @ 2026-03-06 22:30:17.601505
- minor update @ 2026-03-06 22:30:21.910928
- minor update @ 2026-03-07 04:22:11.065345
- minor update @ 2026-03-07 04:22:19.320586
- minor update @ 2026-03-07 06:42:32.379882
- minor update @ 2026-03-07 07:29:13.866053
- minor update @ 2026-03-08 02:12:25.552792
- minor update @ 2026-03-08 07:31:20.524166
- minor update @ 2026-03-08 07:31:23.769309
- minor update @ 2026-03-08 19:24:24.194753
- minor update @ 2026-03-08 22:25:34.908078
- minor update @ 2026-03-09 13:06:42.049006
- minor update @ 2026-03-09 17:03:41.316657
- minor update @ 2026-03-09 21:34:21.285774
- minor update @ 2026-03-10 08:44:12.054871
- minor update @ 2026-03-10 09:45:49.921683
- minor update @ 2026-03-10 13:03:26.777487
- minor update @ 2026-03-10 13:03:45.086039
- minor update @ 2026-03-10 18:51:55.984761
- minor update @ 2026-03-11 16:54:01.665242
- minor update @ 2026-03-11 16:54:15.845512
- minor update @ 2026-03-11 16:54:20.074675
- minor update @ 2026-03-11 22:27:58.300137
- minor update @ 2026-03-11 22:28:07.119115
- minor update @ 2026-03-11 22:28:12.382906
- minor update @ 2026-03-12 06:57:47.553790
- minor update @ 2026-03-12 13:02:56.557845
- minor update @ 2026-03-12 13:03:17.906406
- minor update @ 2026-03-12 13:03:26.353693
- minor update @ 2026-03-12 15:59:45.586584
- minor update @ 2026-03-13 23:29:53.688274
- minor update @ 2026-03-14 02:07:25.654879
- minor update @ 2026-03-14 02:07:40.477599
- minor update @ 2026-03-14 09:34:52.080567
- minor update @ 2026-03-14 09:35:18.194151
- minor update @ 2026-03-14 16:33:26.392750
- minor update @ 2026-03-15 10:32:00.069493
- minor update @ 2026-03-15 10:32:13.496888
- minor update @ 2026-03-15 10:32:20.541681
- minor update @ 2026-03-15 10:32:29.462744
- minor update @ 2026-03-16 02:33:34.672142
- minor update @ 2026-03-16 02:33:45.385065
- minor update @ 2026-03-16 08:58:25.792742
- minor update @ 2026-03-16 08:58:36.593645
- minor update @ 2026-03-17 07:16:09.026412
- minor update @ 2026-03-18 04:57:27.249471
- minor update @ 2026-03-18 08:52:37.364431
- minor update @ 2026-03-18 08:52:46.938144
- minor update @ 2026-03-19 07:10:24.316230
- minor update @ 2026-03-19 07:10:48.213749
- minor update @ 2026-03-19 19:08:58.825199
- minor update @ 2026-03-19 19:09:06.261564
- minor update @ 2026-03-19 19:09:15.529846
- minor update @ 2026-03-20 13:02:32.292659
- minor update @ 2026-03-20 23:30:01.011240
- minor update @ 2026-03-20 23:30:05.341844
- minor update @ 2026-03-21 02:05:11.510059
- minor update @ 2026-03-21 06:46:43.318186
- minor update @ 2026-03-21 07:33:30.732108
- minor update @ 2026-03-21 07:33:46.376654
- minor update @ 2026-03-21 08:35:20.716926
- minor update @ 2026-03-21 08:35:45.772685
- minor update @ 2026-03-21 22:26:55.316102
- minor update @ 2026-03-22 12:54:38.476731
- minor update @ 2026-03-22 22:28:10.334367
- minor update @ 2026-03-23 13:10:48.715074
- minor update @ 2026-03-24 23:34:02.796977
- minor update @ 2026-03-25 15:00:31.522343
- minor update @ 2026-03-25 15:00:47.842423
- minor update @ 2026-03-25 20:39:46.423987
- minor update @ 2026-03-25 20:39:56.374097
- minor update @ 2026-03-25 20:39:58.662696
- minor update @ 2026-03-25 22:38:09.076962
- minor update @ 2026-03-25 22:38:14.421240
- minor update @ 2026-03-26 23:33:15.036843
- minor update @ 2026-03-26 23:33:22.331243
- minor update @ 2026-03-27 02:30:58.850143
- minor update @ 2026-03-27 02:31:17.212384
- minor update @ 2026-03-27 07:09:54.104894
- minor update @ 2026-03-27 07:10:14.287369
- minor update @ 2026-03-27 07:10:27.462845
- minor update @ 2026-03-27 07:10:44.639411
- minor update @ 2026-03-28 04:53:56.459681