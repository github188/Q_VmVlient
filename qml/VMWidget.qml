import QtQuick 2.0

Rectangle {
    id:widget
    width:parent.width
    height:parent.height
    color:"white"
    state:"hide"   
    property int index: 0
    states:
    [
        State
        {
            name:"show"
            PropertyChanges
            {
                target: widget
                visible:true
                opacity:1
            }


        },
        State
        {
            name:"hide"
            PropertyChanges
            {
                target: widget
                visible:false
                opacity:0
            }
        }

    ]

    transitions:
    [
        Transition
        {
            PropertyAnimation
            {
                property:"opacity"
                duration: 500
            }
        }
    ]
}
