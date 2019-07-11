<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="TEST_09.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
        <script type="text/javascript">
        window.onload = function () {

            var element = document.getElementById("imgVerificationCode");
            element.onclick = function () {

                window.alert("123123");
            }
        }
    </script>
</head>
<body>
    <form id="form1" runat="server">
        <img src="VerificationCode.ashx" id="imgVerificationCode"/><br />
        <input type="submit" value="登录"/>
    </form>
</body>
</html>
