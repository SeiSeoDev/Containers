CC = c++

NAME = Container

DIR_S = srcs/

SOURCES = Vector.cpp

INC = inc/

SRCS = $(addprefix $(DIR_S),$(SOURCES))

OBJS = $(SOURCES:.cpp=.o)

FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -o $(NAME)

$(OBJS): $(SRCS) $(INC)
	$(CC) -c $(SRCS) $(FLAGS) -I $(INC)

bonus: all

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
