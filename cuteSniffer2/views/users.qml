import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: "Liste des utilisateurs"
    width: 300
    height: 500
    color: "#f6f6f6"
    visible: true

    ListView {
        anchors.fill: parent
        model: ListModel {
            ListElement {
                mac: "00:11:ef:22:bc:cc"
                ip: "192.168.0.17"
                colorCode: "grey"
            }
            ListElement {
                mac: "00:11:ef:22:bc:cc"
                ip: "192.168.0.17"
                colorCode: "red"
            }
            ListElement {
                mac: "00:11:ef:22:bc:cc"
                ip: "192.168.0.17"
                colorCode: "blue"
            }
            ListElement {
                mac: "00:11:ef:22:bc:cc"
                ip: "192.168.0.17"
                colorCode: "green"
            }
        }
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: mac
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }

                Text {
                    text: ip
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
                spacing: 10
            }
        }
    }
}

