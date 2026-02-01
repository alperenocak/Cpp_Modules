NAME    := UnnecessaryViolence
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

SRCS    :=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

HDRS    := Weapon.hpp HumanA.hpp HumanB.hpp

OBJS    := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
