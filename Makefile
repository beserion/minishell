CC=gcc
CFLAGS=-g -I include
SRCS=src/main.c src/parser.c src/exec.c src/builtin.c src/utils.c src/lexer.c
OBJS=$(SRCS:.c=.o)
NAME=minishell

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
