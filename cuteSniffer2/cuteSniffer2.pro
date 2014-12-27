QT                      +=      core gui qml quick widgets


SOURCES			=	main.cpp \
                                packet/AProtocol.cpp \
                                packet/Ethernet.cpp \
                                tools/RawSocket.cpp \
                                tools/Utils.cpp \
                                tools/ClientHandler.cpp \
                                tools/Client.cpp \
                                views/MainView.cpp \
                                views/EthernetDisplay.cpp

HEADERS			=	packet/AProtocol.hh \
                                packet/Ethernet.hh \
                                packet/ICMP.hpp \
                                packet/ICMPV6.hpp \
                                packet/IP.hpp \
                                packet/IPV6.hpp \
                                packet/TCP.hpp \
                                packet/UDP.hpp \
                                packet/ARP.hpp \
                                tools/RawSocket.hh \
                                tools/Utils.hh \
                                tools/ClientHandler.hh \
                                tools/Client.hh \
                                views/MainView.hh \
                                views/EthernetDisplay.hh

INCLUDEPATH		=	packet \
                                tools \
                                views

QMAKE_CXXFLAGS          +=	-std=c++0x\
                                -g

RESOURCES               +=      qml.qrc
