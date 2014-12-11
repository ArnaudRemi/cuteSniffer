NAME		=	cuteSniffer

SRCS		=	main.cpp \
				tools/Utils.cpp \
				tools/RawSocket.cpp \
				packet/Ethernet.cpp \
				packet/AProtocol.cpp

OBJS		=	$(SRCS:.cpp=.o)

COMPIL		=	g++

INCLUDE		=	-Ipacket \
				-Itools

CXXFLAGS 	=	-std=c++0x -g $(INCLUDE)

$(NAME):	$(OBJS)
			$(COMPIL) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

		