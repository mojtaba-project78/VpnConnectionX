import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: root
    width: 500
    height: 600
    objectName: "obj_wn_startup"

    Rectangle {
        anchors.fill: parent
        color: "#fafafa"

        Label {
            anchors.centerIn: parent
            text: "Page <b>%1</b?".arg("Startup")
            font.pixelSize: 12
        }
    }
}
