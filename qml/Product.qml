import QtQuick 2.0

Rectangle {
    id:product
    signal goods_clicked
    width: 350*0.25
    height: 450*0.25
    border{
     width: 2
     color: "gray"
    }



    Rectangle{
        id:pic_rect
        width:(parent.width-4) * 0.75
        height: (parent.height-4) * 0.75
        anchors{
            top:parent.top
            topMargin: 5
            horizontalCenter: parent.horizontalCenter
        }
        Image {
            id: pic_image
            anchors.fill: parent
            source: "../images/product/default_product.png"
            fillMode: Image.PreserveAspectCrop
            clip: true
        }
    }

    Rectangle{
        id: pic_info_rect
        width:  pic_rect.width
        height: (parent.height-4) * 0.2
        anchors{
            top:pic_rect.bottom
            topMargin: 2
            bottom: parent.bottom
            bottomMargin: 2
            horizontalCenter: parent.horizontalCenter
        }

        Column{
            spacing: 1
            anchors.fill: parent
            Text {
                id: pic_info
                anchors.horizontalCenter: parent.horizontalCenter
                font{
                   bold: true
                   pixelSize: parent.width * 0.12
                }
                text: "商品名称"
            }
            Text {
                id: pic_price
                anchors.horizontalCenter: parent.horizontalCenter
                font{
                   bold: true
                   pixelSize: parent.width * 0.12
                }
                text: "商品单价"

            }
        }



    }




    MouseArea{
        hoverEnabled: false
        anchors.fill: parent
        onClicked: goods_clicked()
    }
}

