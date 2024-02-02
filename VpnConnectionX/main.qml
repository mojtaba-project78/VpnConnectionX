import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "./QML/Windows"

Page {
    visible: true

    WN_Loading {
        id: id_wn_loading
        visible: false
    }
    WN_Startup {
        id: id_wn_startup
        visible: false
    }
    WN_App {
        id: id_wn_app
        visible: false
    }

    property var wins: [
        id_wn_loading,  // 0
        id_wn_startup,  // 1
        id_wn_app       // 2
    ]

    function showWindow(WinId)
    {
        for(var index = 0; index < wins.length; index++)
            if(index === WinId)
                wins[index].show()
            else
                wins[index].hide()
    }
}
