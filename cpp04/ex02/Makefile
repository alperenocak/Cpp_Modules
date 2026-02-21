NAME    := Animal
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

SRCS    :=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

HDRS    := Dog.hpp Cat.hpp Animal.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

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
