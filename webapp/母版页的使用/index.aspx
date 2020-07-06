<%@ Page Title="" Language="C#" MasterPageFile="~/MyMasterPage.Master" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="母版页的使用.index" %>

<asp:Content ID="Content_Body" ContentPlaceHolderID="ContentPlaceHolder_Body" runat="server">
    <asp:Repeater ID="MyRepeater" runat="server">
        <ItemTemplate>
            <tr>
                <td><%# Eval("UserId") %></td>
                <td><%# Eval("UserName") %></td>
                <td><%# Eval("UserAge") %></td>
                <td><%# Eval("UserAddress") %></td>
                <td><%# Eval("UserWork") %></td>
            </tr>
        </ItemTemplate>
    </asp:Repeater>
</asp:Content>


