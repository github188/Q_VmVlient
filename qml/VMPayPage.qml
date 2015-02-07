import QtQuick 2.0

VMWidget {
    id:vmPay_page
    anchors.fill: parent
    Rectangle{
        id:goods_view_rect
        anchors{
            top:parent.top
        }
        width: parent.width
        height: parent.height * 0.5

//        Component{
//            id:test_component
//            Column {
//                Text { text: '<b>Name:</b> ' + name }
//                Text { text: '<b>Number:</b> ' + number }
//            }

//        }

//        ListView{
//            anchors.fill: parent
//           delegate: test_component
//           focus: true
//        }
    }


    Rectangle{
        id:pay_bar_rect
        anchors{
            top:goods_view_rect.bottom
        }
        width: parent.width
        height: parent.height * 0.05
        Image {
            id: title_image
            width: parent.width
            height: parent.height
            anchors.fill: parent
            source: "../images/tool/topbg.png"
            rotation: 0

        }

        Text{
            width: 50
            height: 20
            anchors{
                verticalCenter: parent.verticalCenter
                left: parent.left
                leftMargin: 5
            }
            color: "#FFFFFF"
            font.bold: true
            font.pixelSize: parent.height * 0.5
            text:"支付流程"

        }


    }




}

