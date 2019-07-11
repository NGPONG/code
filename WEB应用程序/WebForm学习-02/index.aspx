<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="WebForm学习_02.index" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <table>
            <tr>
                <th class="auto-style2">用户ID</th>
                <th class="auto-style2">用户名称</th>
                <th class="auto-style2">用户年龄</th>
                <th class="auto-style3">用户地址</th>
                <th class="auto-style2">用户工作</th>
            </tr>
            <asp:Repeater ID="MyRepeater" runat="server" OnItemCommand="MyRepeater_ItemCommand">
                <ItemTemplate>
                    <tr>
                        <td><%# Eval("UserId") %></td>
                        <td><%# Eval("UserName") %></td>
                        <td><%# Eval("UserAge") %></td>
                        <td><%# Eval("UserAddress") %></td>
                        <td><%# Eval("UserWork") %></td>
                        <td><asp:Button CommandName="btnDeletes" CommandArgument='<%#Eval("UserId") %>' runat="server" Text="Button" OnClick="Unnamed_Click" /></td>
                    </tr>
                </ItemTemplate>
            </asp:Repeater>
        </table>
    </form>


</body>
</html>
