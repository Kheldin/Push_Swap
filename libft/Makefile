NAME		:= libft.a
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar rcs

SRCDIR		:= .
DEPDIR		:= $(SRCDIR)/.deps
INCDIR		:= includes
BUILDDIR	:= build

SRCFILES	:= ft_fds.c ft_alloc.c ft_is.c ft_itoa.c ft_split.c ft_str.c ft_str2.c \
			ft_str3.c ft_strtrim.c ft_utils.c ft_mem.c \
			get_next_line_bonus.c ft_printf.c do_operation.c operations.c \
			get_next_line_utils_bonus.c ft_lstnew_bonus.c ft_lstfree_bonus.c

OBJS		:= $(addprefix $(BUILDDIR)/,$(SRCFILES:.c=.o))
HEADERS		:= $(INCDIR)/libft.h

DEPFLAGS	:= -MD -MP -MF $(DEPDIR)/$*.d

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(BUILDDIR)/%.o: %.c $(HEADERS)
	mkdir -p $(BUILDDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -I$(INCDIR) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -rf $(DEPDIR)
	rm -rf $(BUILDDIR)

fclean: clean
	rm -f $(NAME)
	rm -f *out

re: fclean all

.PHONY: all clean fclean re