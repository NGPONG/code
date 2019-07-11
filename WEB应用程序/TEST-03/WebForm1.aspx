<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="TEST_03.WebForm1" %>
<%@ Import  Namespace="System.Reflection"%>
<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title></title>
</head>
<body>
    <form id="form1" runat="server" method="get">
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
        <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox> 
        <input id="Submit1" type="submit" value="submit" />
    </form>
    <%for (int i = 0; i < 10; i++) {%>

        <h1>哈哈哈</h1>
        <% string str = Assembly.GetExecutingAssembly().Location.ToString(); %>
        <h1><%=str %></h1>
    <%}%>
<div class="numPages"><table border="1" cellspacing="10px" cellpadding="5px"><tr><td style="background-color: azure">1</td><td><a href = "index.aspx?PaginalNumber=2">2</a></td><td><a href = "index.aspx?PaginalNumber=3">3</a></td><td><a href = "index.aspx?PaginalNumber=4">4</a></td><td><a href = "index.aspx?PaginalNumber=5">5</a></td><td><a href = "index.aspx?PaginalNumber=6">6</a></td></tr></table></div>
</body>
</html>
