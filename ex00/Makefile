NAME = claptrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I inc

SRCDIR = src
INCDIR = inc

SRC = $(SRCDIR)/main.cpp \
      $(SRCDIR)/ClapTrap.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(INCDIR)/ClapTrap.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re