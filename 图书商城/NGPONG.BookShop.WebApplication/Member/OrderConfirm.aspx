<%@ Page Title="" Language="C#" MasterPageFile="~/Master/CustomerSite.Master" AutoEventWireup="true" CodeBehind="OrderConfirm.aspx.cs" Inherits="NGPONG.BookShop.WebApplication.Member.OrderConfirm" %>

<asp:Content ID="Content1" ContentPlaceHolderID="Cunstomer_Header" runat="server">
    <script>
        $(document).ready(function () {

            $("#btnGoPay").click(function () {

                if ($("#txtName").val() == "") {

                    window.alert("请输入姓名!");
                    return false;
                }
                else if ($("#txtAddress").val() == "") {

                    window.alert("请输入地址!");
                    return false;
                }
                else if ($("#txtPhone").val() == "") {

                    window.alert("请输入联系方式!");
                    return false;
                }
                else if ($("#txtPostCode").val() == "") {

                    window.alert("请输入邮编!");
                    return false;
                }
            });
        });
    </script>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="Cunstomer_Body" runat="server">
    <div style="border: solid 4px #aacded; width: 710px">
        <%if (!base.IsCartEmpty)
            { %>
        <form id="form1" runat="server">
        <div style="background: #AACDED; text-align: left">
            <h2>填写核对订单信息</h2>
        </div>
        <div align="left">
            <h2>收货人信息:</h2>
            <div>
                <table datasrc="" style="width: 100%" id="userinfo">
                    <tbody>
                        <tr>
                            <td style="width: 100px" align="right">姓名：
                            </td>
                            <td style="text-align: left">
                                <input type="text" name="txtName" id="txtName" size="50" value="<%=UserInfo.Name %>" /><img src="images/cha.ico" style="display: none" width="15" height="15" />
                            </td>
                        </tr>
                        <tr>
                            <td align="right">地址：
                            </td>
                            <td style="text-align: left">
                                <input type="text" name="txtAddress" id="txtAddress" size="50" value="<%=UserInfo.Address %>" /><img src="images/cha.ico" style="display: none" width="15" height="15" />
                            </td>
                        </tr>
                        <tr>
                            <td align="right">电话：
                            </td>
                            <td style="text-align: left">
                                <input type="text" name="txtPhone" id="txtPhone" size="50" value="<%=UserInfo.Phone %>" /><img src="images/cha.ico" style="display: none" width="15" height="15" />
                            </td>
                        </tr>
                        <tr>
                            <td align="right">邮编：
                            </td>
                            <td style="text-align: left">
                                <input type="text" name="txtPostCode" id="txtPostCode" size="50" value="" /><img src="images/cha.ico" style="display: none" width="15" height="15" />
                            </td>
                        </tr>
                    </tbody>
                </table>
            </div>
            <hr style="border-style: dashed; width: 100%; border-color: #ccc" />
            <div align="left">
                <h2>请选择支付方式:</h2>
                <div>
                    <!--支付方式-->
                    <table style="width: 100%" datasrc="">
                        <tbody>
                            <tr valign="middle">
                                <td style="text-align: right; width: 80px">支付方式：
                                </td>
                                <td style="vertical-align: middle; text-align: left">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                                    <img alt="" src="/Images/y_zfb.gif" /><input name="zfPay" type="radio" value="zfb" checked="checked" />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                                    <img alt="" src="/Images/unionpay.gif" /><input name="zfPay" type="radio" value="wyzx" />
                                </td>
                            </tr>
                        </tbody>
                    </table>
                </div>
                <!--支付方式-->
            </div>
            <hr style="border-style: dashed; width: 100%; border-color: #ccc" />
            <div align="left">
                <!--订单确定-->
                <h2>商品清单:</h2>
                <div>
                    <table datasrc="" cellspacing="0" cellpadding="1" width="98%" border="1">
                        <tr class="align_Center Thead">
                            <th width="10%">图书编号</th>
                            <th>商品名称</th>
                            <th width="10%">单价</th>
                            <th width="8%">数量</th>
                        </tr>
                        <asp:Repeater ID="repBookInfo" runat="server">
                            <ItemTemplate>
                                <tr class="align_Center">
                                    <td style="padding-bottom: 5px; padding-left: 0px; padding-right: 0px; padding-top: 5px">
                                        <%#Eval("Id") %>
                                    </td>
                                    <td class="align_Left">
                                        <a href="#" target="_blank"><%#Eval("Title") %></a>
                                    </td>
                                    <td>
                                        <span class="price">￥<%#Convert.ToDecimal(Eval("UnitPrice")).ToString("0.00") %></span></td>
                                    <td>
                                        <%#Eval("Count") %>
                                    </td>
                                </tr>
                            </ItemTemplate>
                        </asp:Repeater>
                    </table>
                </div>
            </div>
            <!--订单确定_Start-->
            <div align="right" style="margin-right: 20px">
                <!--总价格显示-->
                <h2>你需要支付的总价格为:<span class="price">￥<%=TotalMoney.ToString("0.00")%></span></h2>
                <br />
                <input id="btnGoPay" type="submit" onclick="return OnSubmit()" value="" style="background: url('/Images/gopay.jpg') no-repeat center; cursor:pointer;width: 95px; height: 32px" name="btnGoPay" />
                <span id="spanMsg" style="color: Red"></span>
            </div>
            <!--订单确定_End-->
        </div>
            </form>
        <%}else{ %>
        <h1>您还未添加任何信息至购物车中，请<a href="/Member/BookList.aspx">返回</a>继续购物</h1>
        <%} %>
    </div>
</asp:Content>
