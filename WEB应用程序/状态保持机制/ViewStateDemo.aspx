<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ViewStateDemo.aspx.cs" Inherits="状态保持机制.ViewStateDemo" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
        </div>

        <h1><%=base.ValueAdd %></h1><input type="submit" value="加"/>
    </form>
</body>
</html>
