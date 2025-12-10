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

DEPFLAGS	:= -MD -MP -MF $(DEPDIR)/$*.d

LIBFTDIR	:= libft/
LIBFT		:= $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):force
	$(MAKE) -C $(LIBFTDIR)

$(BUILDDIR)/%.o: %.c $(HEADERS)
	mkdir -p $(BUILDDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -I$(INCDIR) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -rf $(DEPDIR)
	rm -rf $(BUILDDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f *out
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re force