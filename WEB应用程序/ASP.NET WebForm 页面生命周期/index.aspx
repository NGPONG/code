<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="ASP.NET_WebForm_页面生命周期.index" %>
<%@ Import Namespace="System.Reflection" %>
<%@ Register Src="~/MyControl.ascx" TagPrefix="NGPONG" TagName="MyControl" %>


<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title></title>
    <%string str = "321312313"; %>
    <%=str %>
</head>
<body>
    <%string str = "d12dawdqwdqwd"; %>
    <form id="form1" runat="server" >
        <div>
            <%string str = "11111111111111111"; %>
            <%=str %>
            <NGPONG:MyControl runat="server" ID="MyControl" ViewStateMode="Enabled" />
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <input id="Submit1" type="submit" value="submit" />
        </div>
    </form>
    <%=Assembly.GetExecutingAssembly().Location %>
</body>

</html>
