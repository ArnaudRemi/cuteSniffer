NAME	=	forge

SRCS	=	main.cpp \
			../RawSocket.cpp \
			../IP_Packet.cpp \
			../TCP_Packet.cpp \
			../UDP_Packet.cpp \
			../ARP_Packet.cpp \
			../ICMPV6_Packet.cpp \
			../ICMP_Packet.cpp \
			../IPV6_Packet.cpp \
			../L2_Packet.cpp \
			../L3_Packet.cpp \
			../L4_Packet.cpp \
			../Utils.cpp

INC			=	-I ..

CXXFLAGS	=	$(INC)

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

		