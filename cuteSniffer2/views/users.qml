import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

Window {
    id: usersWin
    title: "Liste des utilisateurs"
    width: 300
    height: 500
    color: "#f6f6f6"
    visible: true

    ListView {
        anchors.fill: parent
        model: __clientHandler__.clients

        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                Image {
                    width: 32
                    height: 32
                    source: {
                        if (!model.router)
                            "qrc:/images/users.png"
                        else
                            "qrc:/images/router.png"
                    }
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

