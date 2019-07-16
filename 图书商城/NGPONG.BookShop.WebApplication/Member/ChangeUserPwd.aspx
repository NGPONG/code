<%@ Page Title="" Language="C#" MasterPageFile="~/Master/CustomerSite.Master" AutoEventWireup="true" CodeBehind="ChangeUserPwd.aspx.cs" Inherits="NGPONG.BookShop.WebApplication.Member.ChangeUserPwd" %>

<asp:Content ID="Content1" ContentPlaceHolderID="Cunstomer_Header" runat="server">
    <script type="text/javascript">
        $(function () {
            $("#btnChangePwd").click(function () {
                ChangePwd();
            });

            function ChangePwd() {
                var PwdOld = $("#txtPwdOld").val();
                var PwdNew = $("#txtPwdNew").val();
                var PwdConfirm = $("#txtPwdConfirm").val();
                if (PwdNew != PwdConfirm) {

                    window.alert("两次密码不一致，请重新输入");
                    return;
                }

                if (PwdOld != "" && PwdNew != "") {

                    $.ajax({
                        type: "post",
                        url: "/ashx/ChangePwd.ashx",
                        async: true,
                        dataType: "json",
                        data: "PwdOld=" + PwdOld + "&PwdNew=" + PwdNew,
                        success: function (data, textStatus, jqXHR) {

                            if (data.isSuccess == "false") {

                                window.alert(data.Message);
                            }
                            else {

                                window.alert("修改密码成功!");
                                window.location.href = data.url;
                            }
                        }
                    });
                } else {
                    alert("用户名邮箱不能为空");
                }
            }
        });

    </script>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="Cunstomer_Body" runat="server">
    <table>
        <tr>
            <td>旧密码</td>
            <td>
                <input type="text" id="txtPwdOld" />
            </td>
        </tr>
        <tr>
            <td>新密码</td>
            <td>
                <input type="password" id="txtPwdNew" />
            </td>
        </tr>
        <tr>
            <td>确认密码</td>
            <td>
                <input type="password" id="txtPwdConfirm" />
            </td>
        </tr>
        <tr>
            <td colspan="2">
                <input type="button" value="修改密码" id="btnChangePwd" />
            </td>
        </tr>
    </table>
</asp:Content>
