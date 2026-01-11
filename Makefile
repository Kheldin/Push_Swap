NAME		:= push_swap
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
AR			:= ar rcs

SRCDIR		:= . parser operations algorithms utils bench
DEPDIR		:= .deps
INCDIR		:= includes
BUILDDIR	:= build

SRCFILES	:= utils/disorder.c main.c parser/parser.c parser/ft_free_buffer.c \
			   operations/op_push.c operations/op_swap.c operations/op_rotate.c \
			   algorithms/insertion_sort.c algorithms/selection_sort.c \
			   algorithms/chunk_sort.c utils/final_push.c utils/get_indexs.c\
			   utils/print_stacks.c algorithms/selection_sort_for_chunk.c \
			   utils/itoa_binary.c utils/init_flags_struct.c\
			   bench/bench.c algorithms/radix_sort.c utils/choose_algo.c\

OBJS		:= $(addprefix $(BUILDDIR)/,$(SRCFILES:.c=.o))
HEADERS		:= $(INCDIR)/push_swap.h

DEPFLAGS	:= -MD -MP -MF $(DEPDIR)/$*.d

LIBFTDIR	:= libft/
LIBFT		:= $(LIBFTDIR)/libft.a

ARG = 

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):force
	$(MAKE) -C $(LIBFTDIR)

$(BUILDDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@) $(DEPDIR)/$(dir $<)
	$(CC) $(CFLAGS) $(DEPFLAGS) -I$(INCDIR) -c $< -o $@

vpath %.c $(SRCDIR) #Search *.c in all dir in SRCDIR
-include $(addprefix $(DEPDIR)/,$(SRCFILES:.c=.d))

clean:
	rm -rf $(DEPDIR)
	rm -rf $(BUILDDIR)
	rm -f *.txt
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

debug: all
	$(CC) $(CFLAGS) -g3 $(OBJS) $(LIBFT) -o $(NAME)
	valgrind --leak-check=full ./$(NAME) $(ARG)

gdb_debug: re $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -g3 $(OBJS) $(LIBFT) -o $(NAME)
	gdb --args ./$(NAME) $(ARG)

.PHONY: all clean fclean re force debug gdb_debug