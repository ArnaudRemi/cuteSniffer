import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import __data_element__ 1.0

ApplicationWindow {
    title: "cuteSniffer2"
    width: 800
    height: 450
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
        x: 50
        y: 50
        width: 200
        height: 50
        text: "RUN CAPTURE"
        onClicked: {
            __root__.runCapture()
        }
    }

    Button {
        x: 300
        y: 50
        width: 200
        height: 50
        text: "STOP CAPTURE"
        onClicked: {
            __root__.stopCapture()
        }
    }


    TableView {
        width: 800
        height: 300
        model: __root__.packets

        onDoubleClicked: {
            __root__.rowDoubleClick(row)
        }

        y: 150

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
