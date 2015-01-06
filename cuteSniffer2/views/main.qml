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
                        filterBox_textField.text = __filters__.ether_dhost
                        filterBox_textFiled_biding.property = "ether_dhost"
                        filterBox.visible = true
                    }
                }
                MenuItem {
                    text: qsTr("shost")
                    onTriggered: {
                        filterBox_text.text = qsTr("Ethernet shost : ");
                        filterBox_textField.text = __filters__.ether_shost
                        filterBox_textFiled_biding.property = "ether_shost"
                        filterBox.visible = true
                    }
                }
                MenuItem {
                    text: qsTr("type")
                    onTriggered: {
                        filterBox_text.text = qsTr("Ethernet type : ");
                        filterBox_textField.text = __filters__.ether_type
                        filterBox_textFiled_biding.property = "ether_type"
                        filterBox.visible = true
                    }
                }
            }
            MenuSeparator { }
            Menu {
                title: qsTr("ARP")
                MenuItem {
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
                }
                MenuItem {
                    text: qsTr("sha")
                }
                MenuItem {
                    text: qsTr("spa")
                }
                MenuItem {
                    text: qsTr("tha")
                }
                MenuItem {
                    text: qsTr("tpa")
                }
            }
            Menu {
                title: qsTr("IP")
                MenuItem {
                    text: qsTr("vhl")
                }
                MenuItem {
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
                }
                MenuItem {
                    text: qsTr("p")
                }
                MenuItem {
                    text: qsTr("sum")
                }
                MenuItem {
                    text: qsTr("src")
                }
                MenuItem {
                    text: qsTr("dst")
                }
            }
            Menu {
                title: qsTr("IPV6")
                MenuItem {
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
                }
                MenuItem {
                    text: qsTr("src")
                }
                MenuItem {
                    text: qsTr("dst")
                }
            }
            MenuSeparator { }
            Menu {
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
            }
            Menu {
                title: qsTr("TCP")
                MenuItem {
                    text: qsTr("sport")
                }
                MenuItem {
                    text: qsTr("dport")
                }
                MenuItem {
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
                }
            }
            Menu {
                title: qsTr("UDP")
                MenuItem {
                    text: qsTr("srcport")
                }
                MenuItem {
                    text: qsTr("destport")
                }
                MenuItem {
                    text: qsTr("len")
                }
                MenuItem {
                    text: qsTr("chksum")
                }
            }
            MenuSeparator { }
            Menu {
                 title: qsTr("Contenu")
                 MenuItem {
                     text: qsTr("Texte")
                 }
                 MenuItem {
                     text: qsTr("Hexadecimal")
                 }
            }
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

    Text {
        x: 20
        y: 104
        text: qsTr("Interface")
        font.pointSize: 15
    }

    TextField {
        id: interfaceInput
        x: 130
        y: 104
        width: 150
        font.pointSize: 16
        text: __root__.interface
        Binding {
            target: __root__
            property: "interface"
            value: interfaceInput.text
        }
    }

    TableView {
        x: 10
        y: 150
        width: 780
        height: 270
        currentRow: -1
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
            role: "data"
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
