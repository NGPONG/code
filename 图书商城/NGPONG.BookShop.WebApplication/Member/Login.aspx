<%@ Page Title="" Language="C#" MasterPageFile="~/Master/CustomerSite.Master" AutoEventWireup="true" CodeBehind="Login.aspx.cs" Inherits="NGPONG.BookShop.WebApplication.Member.Login" %>

<asp:Content ID="Content1" ContentPlaceHolderID="Cunstomer_Header" runat="server">
    <script>
        $(document).ready(function () {

            $("#imgLogin").click(function () {

                if ($("#txtName").val() == "") {

                    window.alert("请输入用户名!");
                    return false;
                }
                else if ($("#txtPwd").val() == "") {

                    window.alert("请输入密码!");
                    return false;
                }

                $.ajax({
                    type: "post",
                    url: "/ashx/CheckLogin.ashx",
                    async: true,
                    dataType: "json",
                    data: $("#form").serializeArray(),
                    success: function (data, textStatus, jqXHR) {

                        // Success
                        if (data.IsSuccess == false) {

                            window.alert(data.Message);
                        }
                        else {

                            if (data.RedirectUrl == "") {

                                data.RedirectUrl = "/Member/Default.aspx";
                            }
                            window.location.href = data.RedirectUrl;
                        }
                    }
                });

                return false;
            });

            $("#imgRegister").click(function () {

                window.location = "/Member/Register.aspx";
                return false;
            });
        });
    </script>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="Cunstomer_Body" runat="server">
    <table width="60%" height="22" border="0" align="center" cellpadding="0" cellspacing="0" runat="server" id="tblfirst">
        <tr>
            <td width="10">
                <img src="/Images/az-tan-top-left-round-corner.gif" width="10" height="28" /></td>
            <td bgcolor="#DDDDCC"><span style="font-family: '黑体'; font-size: 16px; color: #660000;">登录网上书店</span></td>
            <td width="10">
                <img src="/Images/az-tan-top-right-round-corner.gif" width="10" height="28" /></td>
        </tr>
    </table>
    <form id="form" method="post" action="/ashx/CheckLogin.ashx">
        <input type="hidden" id="RedirectUrl" name="RedirectUrl" value="<%=base.Request.QueryString["RedirectUrl"] == null ? "":base.Request.QueryString["RedirectUrl"] %>" />
        <table width="60%" height="22" border="0" align="center" cellpadding="0" cellspacing="0" runat="server" id="tblsecend">
            <tr>
                <td bgcolor="#DDDDCC" style="width: 2px">&nbsp;</td>
                <td>
                    <div align="center">
                        <table height="61" cellpadding="0" cellspacing="0">
                            <tr>
                                <td height="33" colspan="6">
                                    <p style="font-size: 14px; font-weight: bold; color: #FF9900; text-align: center;">已注册用户请从这里登录</p>
                                </td>
                            </tr>
                            <tr>
                                <td width="24%" height="26" rowspan="2" align="right" valign="top"><strong>用户名：</strong></td>
                                <td valign="top" width="37%">&nbsp;<input type="text" name="txtName" id="txtName" /></td>
                            </tr>
                        </table>
                        <table height="61" cellpadding="0" cellspacing="0">
                            <tr>
                                <td height="1" colspan="2"></td>
                            </tr>
                            <tr>
                                <td width="24%" height="26" rowspan="3" align="right" valign="top"><strong>密　码：</strong></td>
                                <td valign="top" width="37%">&nbsp;<input type="password" name="txtPwd" id="txtPwd" /></td>
                            </tr>

                            <tr>
                                <td valign="top" width="37%">
                                    <input type="checkbox" name="cbAutoLogin" />记住我
                                </td>
                            </tr>
                        </table>
                        <div>
                            <input type="image" src="/Images/az-login-gold-3d.gif" id="imgLogin" />
                            <input type="image" src="/Images/az-newuser-gold-3d.gif" id="imgRegister" />
                            <a href="/Member/FindPwd.aspx">忘记密码</a> 
                        </div>
                        <div>
                            <div align="center">
                                &nbsp;
                            </div>
                        </div>
                </td>
                <td width="2" bgcolor="#DDDDCC">&nbsp;</td>
            </tr>
        </table>
        <table width="60%" height="3" border="0" align="center" cellpadding="0" cellspacing="0" runat="server" id="tblthird">
            <tr align="center">
                <td height="3" bgcolor="#DDDDCC">&nbsp;
                </td>
            </tr>
        </table>
    </form>


</asp:Content>
