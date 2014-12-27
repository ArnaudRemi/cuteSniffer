import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: "Ethernet"
    width: 600
    height: 800
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
        x: 200
        y: 110
        width: 200
        text: qsTr("Text Input")
        font.pixelSize: 20
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
        width: 200
        x: 200
        y: 180
        text: qsTr("Text Input")
        font.pixelSize: 20
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
        x: 200
        y: 250
        width: 200
        text: qsTr("Text Input")
        font.pixelSize: 20
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

    Rectangle {
        x: 8
        y: 400
        width: 584
        height: 392
        color: "#ffffff"
    }
}

