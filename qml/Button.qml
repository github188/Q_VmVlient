import QtQuick 2.0

Rectangle { // our inlined button ui
    id: button
    property QString label: "button"
    anchors.fill:parent
    Text {
        anchors.centerIn: parent
        text: "Start"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            status.text = "Button clicked!"
        }
    }
}



