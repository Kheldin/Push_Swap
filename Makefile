NAME		:= push_swap
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar rcs

SRCDIR		:= .
DEPDIR		:= $(SRCDIR)/.deps
INCDIR		:= includes
BUILDDIR	:= build

SRCFILES	:= disorder.c main.c

OBJS		:= $(addprefix $(BUILDDIR)/,$(SRCFILES:.c=.o))
HEADERS		:= $(INCDIR)/push_swap.h

DEPFLAGS	:= -MMD -MP -MF $(DEPDIR)/$*.d

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(BUILDDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(BUILDDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -I$(INCDIR) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -rf $(DEPDIR)
	rm -rf $(BUILDDIR)

fclean: clean
	rm -f $(NAME)
	rm -f *out

re: fclean all

debug: re
	$(CC) main.c $(NAME) -g3 -o debug.out
	./debug.out

.PHONY: all clean fclean re debug