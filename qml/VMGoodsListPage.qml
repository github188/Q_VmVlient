import QtQuick 2.0

VMWidget {
    id:goodsList_page
    signal goodsList_clicked
    anchors.fill: parent

    onVisibleChanged: {
        if(goodsList_page.visible == true){
            console.log("goodsList_page active");
            vmGoodlist();

        }

    }

    Rectangle{
       id:product_rect
       width: parent.width
       height: parent.height*0.9
       anchors.top:parent.top
       anchors.left: parent.left
       //商品列表区
       Grid {
           id:grid_product
           columns: 4
           spacing: 4
           anchors{
               top:parent.top
               topMargin: 4
               horizontalCenter: parent.horizontalCenter
           }                   



       }

    }



    function vmGoodlist(){
        for(var i = 0;i < 10;i++)
        {
            var product = Qt.createQmlObject('Product{onGoods_clicked:goodsList_clicked()}',grid_product,'err')
        }
    }

    function vmCreateProduct(){
        var product =  Qt.createQmlObject('Product{onGoods_clicked:goodsList_clicked()}',grid_product,'err')
        return product
    }

    function vmDeleteProduct(p){
        p.destroy()
    }

}

