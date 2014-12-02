NAME	=	paquet

SRCS	=	main.cpp \
			../Utils.cpp \
			Ethernet.cpp

OBJS	=	$(SRCS:.cpp=.o)

COMPIL	=	g++

CXXFLAGS = -std=c++0x -g

$(NAME):	$(OBJS)
			$(COMPIL) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

		