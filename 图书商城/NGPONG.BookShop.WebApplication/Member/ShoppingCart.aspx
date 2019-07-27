<%@ Page Title="" Language="C#" MasterPageFile="~/Master/CustomerSite.Master" AutoEventWireup="true" CodeBehind="ShoppingCart.aspx.cs" Inherits="NGPONG.BookShop.WebApplication.Member.ShoppingCart" %>

<asp:Content ID="Content1" ContentPlaceHolderID="Cunstomer_Header" runat="server">
    <link href="/Css/themes/ui-lightness/jquery-ui-1.8.2.custom.css" rel="stylesheet" />
    <link href="/Css/index.css" rel="stylesheet" />
    <script src="/js/jquery-1.7.1.js"></script>
    <script src="/js/jquery-ui-1.8.2.custom.min.js"></script>

    <script>
        var beforeChangeValue = 0;

        $(this).ready(function () {

            $(".txtCountCla").blur(function () {

                changeTextOnBlur($(this).attr("tagID"), beforeChangeValueTemp);
                beforeChangeValueTemp = 0;
            }).focus(function () {

                beforeChangeValueTemp = parseInt($(this).val());
            });
        });
        function toDecimal(x) {
            var f = Math.round(x * 100) / 100;
            var s = f.toString();
            var rs = s.indexOf('.');
            if (rs < 0) {
                rs = s.length;
                s += '.';
            }
            while (s.length <= rs + 2) {
                s += '0';
            }
            return s;
        }
        function changeBar(action,bookId) {

            var $txtCount = $("#txtCount" + bookId);
            if ($txtCount.val() == "1" && action == "-") {

                // 删除
                deleteCart(bookId);
            }
            else {

                $.ajax({
                    type: "post",
                    url: "/ashx/ProcessShoppingCart.ashx",
                    async: true,
                    dataType: "json",
                    data: "productInfo={\"bookId\":\"" + bookId + "\",\"qty\":" + (action == "-" ? -1 : 1) + "}&Action=Add",
                    success: function (data, textStatus, jqXHR) {

                        if (!data.IsSuccess) {

                            if (data.Status == "500") {

                                window.alert(data.Message);
                            }
                        }
                        else {

                            // 修改数量
                            $txtCount.val((parseInt($txtCount.val()) + (action == "-" ? -1 : 1)));

                            // 修改价格
                            $("#tMoney").text(toDecimal(parseFloat($("#tMoney").text()) + (parseFloat($("#price_" + bookId).text()) * (action == "-" ? -1.00 : 1.00))));
                        }
                    }
                });
            }
        }
        function deleteCart(bookId) {

            if (window.confirm("是否要删除这个商品？") == true)
            {
                $.ajax({
                    type: "post",
                    url: "/ashx/ProcessShoppingCart.ashx",
                    async: true,
                    dataType: "json",
                    data: "productInfo={\"bookId\":\"" + bookId + "\",\"qty\":1}&Action=Delete",
                    success: function (data, textStatus, jqXHR) {

                        if (!data.IsSuccess) {

                            if (data.Status == "500") {

                                window.alert(data.Message);
                            }
                        }
                        else {

                            // 更新价格
                            $("#tMoney").text(toDecimal(parseFloat($("#tMoney").text()) - (parseFloat($("#price_" + bookId).text()) * parseFloat($("#txtCount" + bookId).val()))));

                            // 删除行
                            $("#tr_" + bookId).remove();

                            window.alert(data.Message);
                        }
                    }
                });
            }
        }
        function changeTextOnBlur(bookId, beforeChangeValue) {

            var $txtCount = $("#txtCount" + bookId);
            if (parseInt($txtCount.val()) <= 0) {

                window.alert("所修改的数量不能小于0");
                return;
            }

            if (!/^[0-9]*$/.test($txtCount.val()))
            {
                window.alert("输入的数字非法!请确认!");
                // Reset
                $txtCount.val("1");
                return;
            }

            $.ajax({
                type: "post",
                url: "/ashx/ProcessShoppingCart.ashx",
                async: true,
                dataType: "json",
                data: "productInfo={\"bookId\":\"" + bookId + "\",\"qty\":" + parseInt($txtCount.val()) + "}&Action=Update",
                success: function (data, textStatus, jqXHR) {

                    if (!data.IsSuccess) {

                        if (data.Status == "500") {

                            window.alert(data.Message);
                        }
                    }
                    else {

                        var afterChangeValue = parseInt($txtCount.val());

                        // 增加
                        if (afterChangeValue > beforeChangeValue) {

                            var changeValueTemp = afterChangeValue - beforeChangeValue; 

                            // 更新价格
                            $("#tMoney").text(toDecimal(parseFloat($("#tMoney").text()) + (parseFloat($("#price_" + bookId).text()) * parseFloat(changeValueTemp))));
                        }
                        // 减少
                        else if (afterChangeValue < beforeChangeValue) {

                            var changeValueTemp = beforeChangeValue - afterChangeValue;

                            // 更新价格
                            $("#tMoney").text(toDecimal(parseFloat($("#tMoney").text()) - (parseFloat($("#price_" + bookId).text()) * parseFloat(changeValueTemp))));
                        }
                    }

                    // init
                    beforeChangeValue = 0;
                }
            });
        }
    </script>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="Cunstomer_Body" runat="server">
    <div>
        <table cellpadding="0" cellspacing="0" width="98%">
            <tr>
                <td colspan="2">
                    <img height="27" src="/Images/shop-cart-header-blue.gif" width="206" /><img alt="" src="/Images/png-0170.png" /><asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/myorder.aspx">我的订单</asp:HyperLink>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                </td>
            </tr>
            <tr>
                <td colspan="2" width="98%">
                    <%if (!base.IsNoneCart) %>
                    <% { %>
                    <table cellpadding='0' cellspacing='0' width='100%'>
                        <tr class='align_Center Thead'>
                            <td width='7%' style='height: 30px'>图片</td>
                            <td>图书名称</td>
                            <td width='14%'>单价</td>
                            <td width='11%'>购买数量</td>
                            <td width='7%'>删除图书</td>
                        </tr>
                        <!--一行数据的开始 -->
                        <asp:Repeater ID="repBookInfo" runat="server">
                            <ItemTemplate>
                                <tr class='align_Center' id="tr_<%#Eval("Id") %>">
                                    <td style='padding: 5px 0 5px 0;'>
                                        <img src='/images/bookcovers/<%#Eval("ISBN") %>.jpg' width="40" height="50" border="0" /></td>
                                    <td class='align_Left'>
                                        <span class="bookTitle"><%#Eval("Title") %></span>
                                    </td>
                                    <td>
                                        <span id='price_<%#Eval("Id") %>'><%#Convert.ToDecimal(Eval("UnitPrice")).ToString("0.00") %></span>
                                    </td>
                                    <td>
                                        <a href='#none' title='减一' onclick="changeBar('-',<%#Eval("Id") %>)" style='margin-right: 2px;'>
                                            <img src="/Images/bag_close.gif" width="9" height="9" border='none' style='display: inline' />
                                        </a>
                                        <input type='text' class="txtCountCla" id='txtCount<%#Eval("Id") %>' name='txtCount<%#Eval("Id") %>' maxlength='3' style='width: 30px' value='<%#Eval("Count") %>' tagID="<%#Eval("Id") %>" />
                                        <a href='#none' title='加一' onclick="changeBar('+',<%#Eval("Id") %>)" style='margin-left: 2px;'>
                                            <img src='/images/bag_open.gif' width="9" height="9" border='none' style='display: inline' />
                                        </a>
                                    </td>
                                    <td>
                                        <a href='#none' id='btnDelete' onclick="deleteCart(<%#Eval("Id") %>,this)">删除</a>
                                    </td>
                                </tr>
                            </ItemTemplate>
                        </asp:Repeater>
                        <!--一行数据的结束 -->
                        <tr>
                            <td class='align_Right Tfoot' colspan='5' style='height: 30px'>&nbsp;</td>
                        </tr>
                    </table>
                    <%} %>
                    <%else %>
                    <%{ %>
                        <center>
                            <h1>您还未添加任何商品到购物车中！</h1>
                        </center>
                    <%} %>
                </td>
            </tr>
            <tr>
                <%if (!base.IsNoneCart) %>
                <%{ %>
                <td style="text-align: center">&nbsp;&nbsp;&nbsp; 
                    商品金额总计：<span id="tMoney" style="font-size: 20px; color: red; font-weight: bold"><%=base.CharPrice.ToString("0.00") %></span>&nbsp;元
                <%} %>
                </td>
                <td>&nbsp;
                    <a href="/Member/BookList.aspx">
                        <img alt="" src="/Images/gobuy.jpg" width="103" height="36" border="0" />
                    </a>
                    <%if (!base.IsNoneCart) %>
                    <%{ %>
                    <a href="OrderConfirm.aspx">
                        <img src="/Images/balance.gif" border="0" />
                    </a>
                    <%} %>
                </td>
            </tr>
        </table>
    </div>
    <div id="showResult" style="display: none">
        <span id="errorMsg" style="font-size: 20px; color: red"></span>
    </div>
    <input type="hidden" id="pCount" />
</asp:Content>
