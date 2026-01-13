NAME		:= push_swap
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
AR			:= ar rcs

SRCDIR		:= . parser operations algorithms utils bench
DEPDIR		:= .deps
INCDIR		:= includes
BONUS_INCDIR := bonus/includes
BUILDDIR	:= build
BONUS_BUILDDIR := bonus/build

SRCFILES	:= parser/parser.c parser/ft_free_buffer.c \
			   operations/op_push.c operations/op_swap.c operations/op_rotate.c \
			   algorithms/selection_sort.c algorithms/chunk_sort.c \
			   algorithms/selection_sort_for_chunk.c algorithms/radix_sort.c \
			   utils/final_push.c utils/get_indexs.c utils/disorder.c \
			   utils/print_stacks.c utils/itoa_binary.c utils/init_flags_struct.c \
			   utils/choose_algo.c bench/bench_utils.c bench/bench.c \
			   utils/free_flags.c \
			   main.c

BONUS_SRCFILES := bonus/get_next_line.c bonus/get_next_line_utils.c \
				  parser/parser.c parser/ft_free_buffer.c \
				  bonus/operations_checker.c checker.c\
				  utils/init_flags_struct.c utils/print_stacks.c \
				  utils/free_flags.c \

OBJS		:= $(addprefix $(BUILDDIR)/,$(SRCFILES:.c=.o))
HEADERS		:= $(INCDIR)/push_swap.h

BONUS_OBJS := $(BONUS_SRCFILES:.c=.o) 
BONUS_HEADER := bonus/includes/bonus.h

DEPFLAGS	:= -MD -MP -MF $(DEPDIR)/$*.d

LIBFTDIR	:= libft
LIBFT		:= $(LIBFTDIR)/libft.a


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):force
	$(MAKE) -C $(LIBFTDIR)

$(BUILDDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@) $(DEPDIR)/$(dir $<)
	$(CC) $(CFLAGS) $(DEPFLAGS) -I$(INCDIR) -c $< -o $@

$(BONUS_BUILDDIR)/%.o: %.c $(BONUS_HEADERS)
	@mkdir -p $(dir $@) $(DEPDIR)/$(dir $<)
	$(CC) $(CFLAGS) $(DEPFLAGS) -I$(BONUS_INCDIR) -c $< -o $@

vpath %.c $(SRCDIR) # Search *.c in all dir in SRCDIR
-include $(addprefix $(DEPDIR)/,$(SRCFILES:.c=.d))

clean:
	rm -rf $(DEPDIR)
	rm -rf $(BUILDDIR)
	rm -rf $(BONUS_BUILDDIR)
	rm -f *.txt
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f checker
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

debug: all
	$(CC) $(CFLAGS) -g3 $(OBJS) $(LIBFT) -o $(NAME)
	valgrind --leak-check=full ./$(NAME)

gdb_debug: re $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -g3 $(OBJS) $(LIBFT) -o $(NAME)
	gdb --args ./$(NAME) $(ARG)

bonus: $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o checker

.PHONY: all clean fclean re force debug gdb_debug bonus checker 