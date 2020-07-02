<%@ Page Title="" Language="C#" MasterPageFile="~/Master/CustomerSite.Master" AutoEventWireup="true" CodeBehind="FindPwd.aspx.cs" Inherits="BookShop.Web.Member.FindPwd" %>
<asp:Content ID="Content1" ContentPlaceHolderID="Cunstomer_Header" runat="server">
    <script type="text/javascript">
        $(function () {
            $("#btnFindPwd").click(function () {
                findPwd();
            });
        });
        function findPwd() {
            var userName = $("#txtName").val();
            var userMail = $("#txtMail").val();
            if (userName != "" && userMail != "") {

                $.ajax({
                    type: "post",
                    url: "/ashx/FindPwd.ashx",
                    async: true,    
                    dataType: "json",
                    data: "name=" + userName + "&mail=" + userMail,
                    success: function (data, textStatus, jqXHR) {

                        if (data.isSuccess == "false") {

                            window.alert(data.Message);
                        }
                        else {

                            window.alert("发送邮件成功！请及时在邮箱中确认！");
                        }
                    }
                });
            } else {
                alert("用户名邮箱不能为空");
            }
        }
    </script>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="Cunstomer_Body" runat="server">

    <table>
        <tr><td>用户名</td><td><input type="text" id="txtName" /></td></tr>
          <tr><td>邮箱</td><td><input type="text" id="txtMail" /></td></tr>
          <tr><td colspan="2"><input type="button" value="找回密码" id="btnFindPwd" /></td></tr> 
    </table>
</asp:Content>
