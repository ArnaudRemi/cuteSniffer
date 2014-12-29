SOURCES			=	graphic/FocusView.cpp \
					graphic/Interaction.cpp \
					graphic/MainScreen.cpp \
					packet/AProtocol.cpp \
					packet/Ethernet.cpp \
					tools/RawSocket.cpp \
					tools/Utils.cpp \
					filters/ContentFilter.cpp \
					main.cpp

HEADERS			=	graphic/FocusView.hh \
					graphic/Interaction.hh \
					graphic/MainScreen.hh \
					packet/AProtocol.hh \
					packet/ARP.hh \
					packet/BrutProtocol.hh \
					packet/Ethernet.hh \
					packet/ICMP.hh \
					packet/ICMPV6.hh \
					packet/IP.hh \
					packet/IPV6.hh \
					packet/TCP.hh \
					packet/UDP.hh \
					filters/ContentFilter.hh \
					filters/Filter.hh \
					tools/RawSocket.hh \
					tools/Utils.hh
				
INCLUDEPATH		=	graphic \
					filters \
					packet \
					tools
				
QMAKE_CXXFLAGS	+=	-std=c++0x
				
##Pour créer le makefile : qmake -o Makefile test.pro