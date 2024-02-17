NAME = bureaucrat

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

RM = rm -rf

SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)

HEADERS = Bureaucrat.hpp 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	
%.o: %.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re