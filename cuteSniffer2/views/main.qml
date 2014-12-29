import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import __data_element__ 1.0

ApplicationWindow {
    id: applicationWindow1
    title: "cuteSniffer2"
    width: 800
    height: 450
    color: "#e0dfdf"
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
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
        }
        Image {
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
        onClicked: {
            __root__.stopCapture()
        }
        Image {
            width: 64
            height: 64
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
        id: deleteBtn
        x: 272
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
        x: 356
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
        }
        TableViewColumn {
            title: "Data"
            role: "data"
        }
    }

    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }

}
