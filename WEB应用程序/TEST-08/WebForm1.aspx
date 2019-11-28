<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="TEST_08.WebForm1" %>
<%@ Import Namespace="System.Reflection" %>


<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <h1>哈哈哈哈哈哈，我是页面1的代码</h1>
    <%=base.Context.Server.UrlEncode("你好啊") %> 
    <!--111111111111111111-->
    <%=Assembly.GetExecutingAssembly().Location %>
</body>
</html>
