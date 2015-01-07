import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

Window {
    id: ethernetWin
    title: "Ethernet"
    width: 370
    height: 450
    color: "#f6f6f6"
    visible: true

    Rectangle {
        x: 0
        y: 0
        width: 370
        height: 40
        color: "#e4e4e4"
        Text {
            x: 0
            y: 0
            width: 370
            height: 40
            text: qsTr("Ethernet")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 24
        }
    }

    Text {
        x: 20
        y: 40
        height: 50
        text: qsTr("Source :")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 13
    }

    TextField {
        id: shostInput
        x: 150
        y: 40
        width: 200
        text: __packet__.shost
        font.pixelSize: 14
        Binding {
            target: __packet__
            property: "shost"
            value: shostInput.text
        }
    }

    Text {
        x: 20
        y: 80
        height: 50
        text: qsTr("Destination :")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 14
    }

    TextField {
        id: dhostInput
        width: 200
        x: 150
        y: 80
        text: __packet__.dhost
        font.pixelSize: 14
        Binding {
            target: __packet__
            property: "dhost"
            value: dhostInput.text
        }
    }

    Text {
        x: 20
        y: 120
        height: 50
        text: qsTr("Type :")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 14
    }

    TextField {
        id: typeInput
        x: 150
        y: 120
        width: 200
        text: __packet__.type
        font.pixelSize: 14
        Binding {
            target: __packet__
            property: "type"
            value: typeInput.text
        }
    }

    Text {
        id: text2
        x: 20
        y: 160
        height: 50
        text: qsTr("Payload :")
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 14
    }

    TextField {
        id: dataInput
        x: 20
        y: 200
        width: 330
        height: 200
        text: qsTr("#__packet__.data#")
        font.pixelSize: 14
        Binding {
            target: __packet__
            property: "data"
            value: dataInput.text
        }
    }

    Button {
        x: 270
        y: 415
        text: qsTr("Forger")
        onClicked: {
            __packet__.sendPacket();
        }
    }
}

