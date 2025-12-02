NAME        = fragtrap

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -I inc

SRCDIR      = src
INCDIR      = inc
OBJDIR      = obj

SRC         = $(SRCDIR)/main.cpp \
              $(SRCDIR)/ClapTrap.cpp \
              $(SRCDIR)/ScavTrap.cpp \
              $(SRCDIR)/FragTrap.cpp

OBJ         = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ): $(INCDIR)/ClapTrap.hpp $(INCDIR)/ScavTrap.hpp $(INCDIR)/FragTrap.hpp Makefile

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
