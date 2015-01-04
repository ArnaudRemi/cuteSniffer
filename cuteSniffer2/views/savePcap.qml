import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: saveFileWin
    title: "Sauvegarder un fichier Pcap"
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
        id: saveFile
        x: 85
        y: 65
        width: 200
        text: __root__.saveFile
        Binding {
            target: __root__
            property: "saveFile"
            value: saveFile.text
        }
    }

    Button {
        id: button1
        x: 300
        y: 65
        text: qsTr("Sauvegarder")
        onClicked: {
            __root__.saveFileSelect()
            saveFileWin.close()
        }
    }
}

