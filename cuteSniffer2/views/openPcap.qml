import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: openFileWin
    title: "Ouvrir un fichier Pcap"
    width: 400
    height: 150
    color: "#f6f6f6"
    visible: true

    Text {
        id: text1
        x: 20
        y: 70
        text: qsTr("Fichier :")
        font.pixelSize: 12
    }

    TextField {
        id: openFile
        x: 85
        y: 65
        width: 200
        placeholderText: qsTr("/tmp/...")
        text: __root__.openFile
        Binding {
            target: __root__
            property: "openFile"
            value: openFile.text
        }
    }

    Button {
        id: button1
        x: 300
        y: 65
        text: qsTr("Ouvrir")
        onClicked: {
            __root__.openFileSelect()
            openFileWin.close()
        }
    }
}

