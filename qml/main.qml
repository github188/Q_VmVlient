import QtQuick 2.0


Rectangle {
    id:main_rect
    anchors.fill: parent
    property VMWidget curPage:vmFaultPage
    property VMWidget lastPage:vmFaultPage


    //1.广告页面
    VMAdsPage{
        id:ads_page
        anchors.fill: parent
        onAds_clicked: {
            vmPageSwitch(goodsListPage);
        }
    }


    //标题栏区域
    VMTitlebar{
        id:title_bar
        width: parent.width
        height: parent.height*0.05
        anchors{top:parent.top}
    }

    //主界面显示区
    Rectangle{
        id:main_page
        width: parent.width
        height: parent.height*0.9
        anchors{top:title_bar.bottom}
        signal main_change_signal



        //2.故障页面
        VMFaultPage{
            id:vmFaultPage
            anchors.fill: parent
        }


        //3.商品列表陀
        VMGoodsListPage{
            id:goodsListPage
            anchors.fill: parent
            onGoodsList_clicked: {
                vmPageSwitch(transactionPage);
            }
        }


        //4.交易界面
        VMTransactionPage{
            id:transactionPage
            anchors.fill: parent

            onButton_pay_clicked:{
                vmPageSwitch(vmPayPage);
                vm.vmcpaySlot(1,11,1,0)                
            }
        }

        //5.支付界面
        VMPayPage{
            id:vmPayPage
            anchors.fill: parent
        }




    }


    //状态栏区域
    VMStatusbar{
        id:status_bar
        width: parent.width
        height: parent.height*0.05
        anchors{top:main_page.bottom}
        onStatus_back_clicked: {
            //执行返回按钮
            back_req()
        }
    }




    //返回函数
    function back_req(){
        if(main_rect.curPage != vmFaultPage)
            vmPageSwitch(ads_page)
    }



    //交互接口
    function vmcStatehandle(s){
        if(s === 2)//正常
        {
            vmPageSwitch(ads_page)
        }
        else //故障
        {
            vmPageSwitch(vmFaultPage)
            //vmPageSwitch(goodsListPage)
        }
        return 1;
    }

    //页面切换函数
    function vmPageSwitch(page){
        main_rect.lastPage = main_rect.curPage
        main_rect.curPage = page
        main_rect.lastPage.state="hide"
        main_rect.curPage.state="show"
        if(main_rect.curPage == ads_page){//广告界面隐藏工具栏
            title_bar.visible=false
            status_bar.visible=false
            main_page.visible=false
        }
        else{
            title_bar.visible=true
            status_bar.visible=true
            main_page.visible=true

        }

    }








}



