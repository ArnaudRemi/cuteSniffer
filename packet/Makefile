NAME		=	packet

SRCS		=	main.cpp \
				../Utils.cpp \
				Ethernet.cpp \
				AProtocol.cpp

OBJS		=	$(SRCS:.cpp=.o)

COMPIL		=	g++

INCLUDE		=	-I../ \
				-I.

CXXFLAGS 	=	-std=c++0x -g $(INCLUDE)

$(NAME):	$(OBJS)
			$(COMPIL) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

		