import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: root
    width: 600
    height: 500
    objectName: "obj_wn_app"

    Rectangle {
        anchors.fill: parent
        color: "#fafafa"

        Label {
            anchors.centerIn: parent
            text: "Page <b>%1</b?".arg("App")
            font.pixelSize: 12
        }
    }
}
