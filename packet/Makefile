NAME	=	paquet

SRCS	=	main.cpp \
			../Utils.cpp \
			Ethernet.cpp \
			ARP.cpp

OBJS	=	$(SRCS:.cpp=.o)

COMPIL	=	g++

$(NAME):	$(OBJS)
			$(COMPIL) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

		