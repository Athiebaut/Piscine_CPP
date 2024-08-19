NAME = Diamond
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
SRC =	main.cpp \
	ClapTrap.cpp \
	FragTrap.cpp \
	DiamondTrap.cpp \
	ScavTrap.cpp
OBJS_DIR = .objs/
OBJS_NAMES = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAMES))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXFLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(C_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all