import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: applicationWindow1
    title: "cuteSniffer2"
    width: 800
    height: 450
    color: "#e0dfdf"
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("Filtres")
            /*Menu {
                title: qsTr("&File")
                MenuItem {
                    text: qsTr("&Open")
                    onTriggered: messageDialog.show(qsTr("Open action triggered"));
                }
                MenuItem {
                    text: qsTr("E&xit")
                    onTriggered: Qt.quit();
                }
            }*/
            Menu {
                title: qsTr("Ethernet")
                MenuItem {
                    text: qsTr("dhost")
                    onTriggered: {
                        filterBox_text.text = qsTr("Ethernet dhost : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.ether_dhost
                        filterBox_textFiled_biding.property = "ether_dhost"
                        filterBox.visible = true
                    }
                }
                MenuItem {
                    text: qsTr("shost")
                    onTriggered: {
                        filterBox_text.text = qsTr("Ethernet shost : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.ether_shost
                        filterBox_textFiled_biding.property = "ether_shost"
                        filterBox.visible = true
                    }
                }
                MenuItem {
                    text: qsTr("type")
                    onTriggered: {
                        filterBox_text.text = qsTr("Ethernet type : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.ether_type
                        filterBox_textFiled_biding.property = "ether_type"
                        filterBox.visible = true
                    }
                }
            }
            MenuSeparator { }
            Menu {
                title: qsTr("ARP")
                /*MenuItem {
                    text: qsTr("htype")
                }
                MenuItem {
                    text: qsTr("ptype")
                }
                MenuItem {
                    text: qsTr("hlen")
                }
                MenuItem {
                    text: qsTr("plen")
                }
                MenuItem {
                    text: qsTr("oper")
                }*/
                MenuItem {
                    text: qsTr("sha")
                    onTriggered: {
                        filterBox_text.text = qsTr("ARP sha : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.arp_sha
                        filterBox_textFiled_biding.property = "arp_sha"
                        filterBox.visible = true
                    }
                }
                MenuItem {
                    text: qsTr("spa")
                    onTriggered: {
                        filterBox_text.text = qsTr("ARP spa : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.arp_spa
                        filterBox_textFiled_biding.property = "arp_spa"
                        filterBox.visible = true
                    }
                }
                MenuItem {
                    text: qsTr("tha")
                    onTriggered: {
                        filterBox_text.text = qsTr("ARP tha : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.arp_tha
                        filterBox_textFiled_biding.property = "arp_tha"
                        filterBox.visible = true
                    }
                }
                MenuItem {
                    text: qsTr("tpa")
                    onTriggered: {
                        filterBox_text.text = qsTr("ARP tpa : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.arp_tpa
                        filterBox_textFiled_biding.property = "arp_tpa"
                        filterBox.visible = true
                    }
                }
            }
            Menu {
                title: qsTr("IP")
                MenuItem {
                    text: qsTr("vhl")
                    onTriggered: {
                        filterBox_text.text = qsTr("IP vhl : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.ip_vhl
                        filterBox_textFiled_biding.property = "ip_vhl"
                        filterBox.visible = true
                    }
                }
                /*MenuItem {
                    text: qsTr("tos")
                }
                MenuItem {
                    text: qsTr("len")
                }
                MenuItem {
                    text: qsTr("id")
                }
                MenuItem {
                    text: qsTr("off")
                }
                MenuItem {
                    text: qsTr("ttl")
                }*/
                MenuItem {
                    text: qsTr("p")
                    onTriggered: {
                        filterBox_text.text = qsTr("IP p : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.ip_p
                        filterBox_textFiled_biding.property = "ip_p"
                        filterBox.visible = true
                    }
                }
                /*MenuItem {
                    text: qsTr("sum")
                }*/
                MenuItem {
                    text: qsTr("src")
                    onTriggered: {
                        filterBox_text.text = qsTr("IP src : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.ip_src
                        filterBox_textFiled_biding.property = "ip_src"
                        filterBox.visible = true
                    }
                }
                MenuItem {
                    text: qsTr("dst")
                    onTriggered: {
                        filterBox_text.text = qsTr("IP dst : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.ip_dst
                        filterBox_textFiled_biding.property = "ip_dst"
                        filterBox.visible = true
                    }
                }
            }
            Menu {
                title: qsTr("IPV6")

                /*MenuItem {
                    text: qsTr("flow")
                }
                MenuItem {
                    text: qsTr("plen")
                }
                MenuItem {
                    text: qsTr("next_head")
                }
                MenuItem {
                    text: qsTr("hop_limit")
                }
                MenuItem {
                    text: qsTr("un2_vfc")
                }*/
                MenuItem {
                    text: qsTr("src")
                    onTriggered: {
                        filterBox_text.text = qsTr("IPV6 src : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.ipv6_src
                        filterBox_textFiled_biding.property = "ipv6_src"
                        filterBox.visible = true
                    }
                }
                MenuItem {
                    text: qsTr("dest")
                    onTriggered: {
                        filterBox_text.text = qsTr("IPV6 dest : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.ipv6_dest
                        filterBox_textFiled_biding.property = "ipv6_dest"
                        filterBox.visible = true
                    }
                }
            }
            MenuSeparator { }
            /*Menu {
                title: qsTr("ICMP")
                MenuItem {
                    text: qsTr("type")
                }
                MenuItem {
                    text: qsTr("code")
                }
                MenuItem {
                    text: qsTr("checksum")
                }
                MenuItem {
                    text: qsTr("gateway")
                }
            }
            Menu {
                title: qsTr("ICMPV6")
                MenuItem {
                    text: qsTr("type")
                }
                MenuItem {
                    text: qsTr("code")
                }
                MenuItem {
                    text: qsTr("checksum")
                }
            }*/
            Menu {
                title: qsTr("TCP")
                MenuItem {
                    text: qsTr("sport")
                    onTriggered: {
                        filterBox_text.text = qsTr("TCP sport : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.tcp_sport
                        filterBox_textFiled_biding.property = "tcp_sport"
                        filterBox.visible = true
                    }
                }
                MenuItem {
                    text: qsTr("dport")
                    onTriggered: {
                        filterBox_text.text = qsTr("TCP dport : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.tcp_dport
                        filterBox_textFiled_biding.property = "tcp_dport"
                        filterBox.visible = true
                    }
                }
                /*MenuItem {
                    text: qsTr("seq")
                }
                MenuItem {
                    text: qsTr("ack")
                }
                MenuItem {
                    text: qsTr("off")
                }
                MenuItem {
                    text: qsTr("flags")
                }
                MenuItem {
                    text: qsTr("win")
                }
                MenuItem {
                    text: qsTr("sum")
                }
                MenuItem {
                    text: qsTr("urp")
                }*/
            }
            Menu {
                title: qsTr("UDP")
                MenuItem {
                    text: qsTr("srcport")
                    onTriggered: {
                        filterBox_text.text = qsTr("UDP srcport : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.udp_srcport
                        filterBox_textFiled_biding.property = "udp_srcport"
                        filterBox.visible = true
                    }
                }
                MenuItem {
                    text: qsTr("destport")
                    onTriggered: {
                        filterBox_text.text = qsTr("UDP destport : ");
                        filterBox_textFiled_biding.property = ""
                        filterBox_textField.text = __filters__.udp_destport
                        filterBox_textFiled_biding.property = "udp_destport"
                        filterBox.visible = true
                    }
                }
               /* MenuItem {
                    text: qsTr("len")
                }
                MenuItem {
                    text: qsTr("chksum")
                }*/
            }
            /*MenuSeparator { }
            Menu {
                 title: qsTr("Contenu")
                 MenuItem {
                     text: qsTr("Texte")
                 }
                 MenuItem {
                     text: qsTr("Hexadecimal")
                 }
            }*/
        }
    }

    Button {
        id: playBtn
        x: 20
        y: 20
        width: 64
        height: 64
        onClicked: {
            __root__.runCapture()
            playBtn.opacity=0.7
            playImg.opacity=0.7
            playBtn.enabled=false
            stopBtn.opacity=1
            stopImg.opacity=1
            stopBtn.enabled=true
            interfaceInput.enabled=false
            macInput.enabled=false
        }
        Image {
            id: playImg
            width: 64
            height: 64
            source: "qrc:/images/play.png"
        }
    }

    Button {
        id: stopBtn
        x: 104
        y: 20
        width: 64
        height: 64
        opacity: 0.7
        enabled: false
        onClicked: {
            __root__.stopCapture()
            playBtn.opacity=1
            playImg.opacity=1
            playBtn.enabled=true
            stopBtn.opacity=0.7
            stopImg.opacity=0.7
            stopBtn.enabled=false
            interfaceInput.enabled=true
            macInput.enabled=true
        }
        Image {
            id: stopImg
            width: 64
            height: 64
            opacity: 0.7
            source: "qrc:/images/stop.png"
        }
    }

    Button {
        id: saveBtn
        x: 188
        y: 20
        width: 64
        height: 64
        onClicked: {
            __root__.saveCapture();
        }
        Image {
            width: 64
            height: 64
            source: "qrc:/images/save.png"
        }
    }

    Button {
        id: openBtn
        x: 272
        y: 20
        width: 64
        height: 64
        onClicked: {
            __root__.openCapture();
        }
        Image {
            width: 64
            height: 64
            source: "qrc:/images/open.png"
        }
    }

    Button {
        id: deleteBtn
        x: 356
        y: 20
        width: 64
        height: 64
        onClicked: {
            __root__.deleteCapture();
        }
        Image {
            width: 64
            height: 64
            source: "qrc:/images/delete.png"
        }
    }

    Button {
        id: users
        x: 440
        y: 20
        width: 64
        height: 64
        onClicked: {
            __root__.displayUsers()
        }
        Image {
            width: 64
            height: 64
            source: "qrc:/images/users.png"
        }
    }

    Button {
        id: newPacket
        x: 524
        y: 20
        width: 64
        height: 64
        onClicked: {
            __root__.newPacket()
        }
        Image {
            id: newPacketImg
            x: 5
            y: 5
            width: 54
            height: 54
            source: "qrc:/images/newPacket.png"
        }
    }

    Text {
        x: 20
        y: 105
        text: qsTr("Interface : ")
        font.pointSize: 15
    }

    TextField {
        id: interfaceInput
        x: 130
        y: 105
        width: 150
        font.pointSize: 16
        text: __root__.interface
        Binding {
            target: __root__
            property: "interface"
            value: interfaceInput.text
        }
    }

    Text {
        x: 350
        y: 105
        text: qsTr("Mac : ")
        font.pointSize: 15
    }

    TextField {
        id: macInput
        x: 410
        y: 105
        width: 300
        font.pointSize: 16
        text: __root__.mac
        Binding {
            target: __root__
            property: "mac"
            value: macInput.text
        }
    }

    TableView {
        x: 10
        y: 150
        width: 780
        height: 270
        currentRow: 50
        model: __root__.packets


        onDoubleClicked: {
            __root__.rowDoubleClick(row)
        }


        TableViewColumn {
            title: "Source"
            role: "shost"
        }
        TableViewColumn {
            title: "Destination"
            role: "dhost"
        }
        TableViewColumn {
            title: "Type"
            role: "type"
            width: 100
        }
        TableViewColumn {
            title: "Data"
            role: "dotData"
            width: 350
        }
    }



    Rectangle {
        id: filterBox
        width: 350
        height: 200
        x: 225
        y: 125
        color: "#f6f6f6"
        visible: false
        border.width: 1
        Rectangle {
            width: 350
            height: 30
            color: "#e4e4e4"
            border.width: 1
            Text {
                width: 350
                height: 30
                text: qsTr("Gestion des Filtres")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 16
            }
        }

        Text {
            id: filterBox_text
            x: 20
            y: 105
            text: qsTr("Text")
            font.pixelSize: 12
        }

        TextField {
            id: filterBox_textField
            x: 150
            y: 100
            placeholderText: qsTr("Text Field")
            Binding {
                id: filterBox_textFiled_biding
                target: __filters__
                value: filterBox_textField.text
            }
        }

        Button {
            id: filterBox_button
            x: 280
            y: 100
            width: 50
            text: qsTr("OK")
            onClicked: {
                filterBox.visible = false
            }
        }
    }

}
