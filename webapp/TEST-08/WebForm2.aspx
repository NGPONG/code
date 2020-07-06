<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs" Inherits="TEST_08.WebForm2" %>
<%@ Import Namespace="System.Reflection" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <h1>哈哈哈哈哈，我是页面2中的代码</h1>
    <!--222222222222-->
    <%=Assembly.GetExecutingAssembly().Location %>
</body>
</html>
