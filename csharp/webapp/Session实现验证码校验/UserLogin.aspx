<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="UserLogin.aspx.cs" Inherits="Session实现验证码校验.UserLogin" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <script type="text/javascript">
        window.onload = function () {

            var element = document.getElementById("imgVerificationCode");
            element.onclick = function () {

                element.src = "VerificationCode.ashx?" + Date.now();
            }
        }
    </script>
</head>
<body>
    <form id="form1" runat="server">
        用户：<input type="text" name="userName"/><br />
        密码：<input type="password" name="userPwd"/><br />
        验证码：<input type="text" name="verificationCode"/><img src="VerificationCode.ashx" id="imgVerificationCode"/><br />
        <input type="submit" value="登录"/>
    </form>
</body>
</html>
