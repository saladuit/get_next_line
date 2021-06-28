NAME  = get_next_line
								#Project files
SRC_DIR := .
SRCS = get_next_line.c get_next_line_utils.c main.c
OBJS = $(SRCS:.c=.o)
								#Compiler flags
CC     = gcc
CFLAGS = -Wall -Wextra -Werror
								#Release build settings
RELDIR = .
RELEXE = $(RELDIR)/$(NAME)
RELOBJS = $(addprefix $(SRC_DIR)/, $(OBJS))
RELCFLAGS = -D BUFFER_SIZE=3
								#Debug settings
ifdef DEBUG
CFLAGS	+=	-g
NAME = debug_get_next_line
endif
ifdef FSAN
FLAGS	+=	-fsanitize=address
endif
ifdef SPEED
FLAGS	+=	-Ofast
endif
ifdef ERROR
FLAGS	+=	-D ELABORATE_ERR=1
endif
ifdef LEAKS
FLAGS	+=	-D LEAKS=1
endif
								#Release rules
all: release
release: $(RELEXE)
$(RELEXE): $(RELOBJS) | $(RELDIR)
	$(CC) $(CFLAGS) $(RELCFLAGS) -o $(RELEXE) $^
$(RELDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(RELCFLAGS) -o $@ $<
re: clean all
clean:
	rm -f $(RELOBJS) $(DBGOBJS)
fclean:
	rm -f $(RELEXE) $(RELOBJS) debug_get_next_line
.PHONY: all clean release re debug fclean
