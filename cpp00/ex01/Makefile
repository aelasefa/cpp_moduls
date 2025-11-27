NAME := phonebook

SRC:= main.cpp phonebook.cpp

CC := g++

OBJS := $(SRC:.cpp=.o)
all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(SRC) -o $(NAME)

.o:.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
