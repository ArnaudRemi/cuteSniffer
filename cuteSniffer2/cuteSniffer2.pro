QT                      +=      core gui qml quick widgets


SOURCES			=	packet/AProtocol.cpp \
                                packet/Ethernet.cpp \
                                tools/RawSocket.cpp \
                                tools/Utils.cpp \
                                main.cpp \
                                view/MainView.cpp \
                                view/EthernetDisplay.cpp

HEADERS			=	packet/AProtocol.hh \
                                tools/RawSocket.hh \
                                tools/Utils.hh \
                                view/MainView.hh \
                                packet/BrutProtocol.hpp \
                                packet/Ethernet.hh \
                                packet/ICMP.hpp \
                                packet/ICMPV6.hpp \
                                packet/IP.hpp \
                                packet/IPV6.hpp \
                                packet/TCP.hpp \
                                packet/UDP.hpp \
                                packet/ARP.hpp \
                                view/EthernetDisplay.hh

INCLUDEPATH		=	packet \
                                tools \
                                view

QMAKE_CXXFLAGS          +=	-std=c++0x\
                                -g

OTHER_FILES             +=      view/main.qml
