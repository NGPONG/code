<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="CookieDemo.aspx.cs" Inherits="状态保持机制.CookieDemo" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form method="post" action="CookieDemo.aspx">
        用户名：<input type="text" name="txtUserName" value="<%=base.UserName %>" /><br />
        密码：<input type="password" name="txtPassWord"/><br /><br />
        <input type="submit" value="登录"/>
    </form>
</body>
</html>
