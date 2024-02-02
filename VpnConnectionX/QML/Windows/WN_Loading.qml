import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: root
    width: 400
    height: 400
    objectName: "obj_wn_loading"

    Rectangle {
        anchors.fill: parent
        color: "#fafafa"

        Label {
            anchors.centerIn: parent
            text: "Page <b>%1</b?".arg("Loading")
            font.pixelSize: 12
        }
    }
}
