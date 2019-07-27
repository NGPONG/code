<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="test-03.aspx.cs" Inherits="NGPONG.BookShop.WebApplication.test.test_03" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title></title>
</head>
<body>
    <table>
        <tr>
            <td>bookid</td>
            <td>Msg</td>
        </tr>
        <asp:Repeater ID="Repeater1" runat="server">
            <ItemTemplate>
                <tr>
                    <td><%#Eval("bookid") %></td>
                    <td><%#Eval("Msg") %></td>
                </tr>
            </ItemTemplate>
        </asp:Repeater>
    </table>
</body>
</html>
