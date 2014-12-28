import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: ethernetWindow
    title: "Ethernet"
    width: 600
    height: 700
    color: "#f6f6f6"
    visible: true

    Rectangle {
        x: 0
        y: 0
        width: 600
        height: 60
        color: "#e4e4e4"
        Text {
            x: 0
            y: 0
            width: 600
            height: 60
            text: qsTr("Ethernet")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 34
        }
    }

    Text {
        x: 20
        y: 110
        height: 50
        text: qsTr("Source :")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 20
    }

    TextField {
        id: shostInput
        x: 200
        y: 110
        width: 200
        text: __packet__.shost
        font.pixelSize: 20
        Binding {
            target: __packet__
            property: "shost"
            value: shostInput.text
        }
    }

    Text {
        x: 20
        y: 180
        height: 50
        text: qsTr("Destination :")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 20
    }

    TextField {
        id: dhostInput
        width: 200
        x: 200
        y: 180
        text: __packet__.dhost
        font.pixelSize: 20
        Binding {
            target: __packet__
            property: "dhost"
            value: dhostInput.text
        }
    }

    Text {
        x: 20
        y: 250
        height: 50
        text: qsTr("Type :")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 20
    }

    TextField {
        id: typeInput
        x: 200
        y: 250
        width: 200
        text: __packet__.type
        font.pixelSize: 20
        Binding {
            target: __packet__
            property: "type"
            value: typeInput.text
        }
    }

    Text {
        id: text2
        x: 8
        y: 350
        height: 50
        text: qsTr("Payload :")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 20
    }

    TextField {
        id: dataInput
        text: qsTr("#__packet__.data#")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        anchors.top: parent.top
        anchors.topMargin: 400
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        font.pixelSize: 20
        Binding {
            target: __packet__
            property: "data"
            value: dataInput.text
        }
    }

    Button {
        x: 512
        y: 667
        text: qsTr("Forger")
        onClicked: {
            __packet__.sendPacket();
        }
    }
}

