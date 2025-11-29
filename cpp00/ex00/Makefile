NAME := megaphone

SRC := megaphone.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

OBJS := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

