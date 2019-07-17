<%@ Page Title="" Language="C#" MasterPageFile="~/Master/CustomerSite.Master" AutoEventWireup="true" CodeBehind="BookList.aspx.cs" Inherits="NGPONG.BookShop.WebApplication.Member.BookList" %>

<asp:Content ID="Content1" ContentPlaceHolderID="Cunstomer_Header" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="Cunstomer_Body" runat="server">
    <asp:Repeater ID="BookListRepeater" runat="server">
        <ItemTemplate>
            <table>
                <tbody>
                    <tr>
                        <td rowspan="2">
                            <a href="<%#Eval("Id","/BookDetail.aspx?BookId={0}") %>">
                                <img id="ctl00_cphContent_dl_Books_ctl01_imgBook" style="cursor: hand" height="121" alt="<%#Eval("Title") %>" hspace="4" src="<%#Eval("ISBN","/Images/BookCovers/{0}.jpg") %>" width="95">
                            </a>
                        </td>
                        <td style="font-size: small; color: red" width="650">
                            <a class="booktitle" id="link_prd_name" href="<%#Eval("Id","/BookDetail.aspx?BookId={0}") %>" target="_blank" name="link_prd_name"><%#Eval("Title") %>
                            </a>
                        </td>
                    </tr>
                    <tr>
                        <td align="left">
                            <span style="font-size: 12px; line-height: 20px"><%#Eval("Author") %></span>
                            <br />
                            <span style="font-size: 12px; line-height: 20px"><%#Eval("ContentDescription").ToString() %></span>
                        </td>
                    </tr>
                    <tr>
                        <td align="right" colspan="2"><span style="font-weight: bold; font-size: 13px; line-height: 20px"><%#Eval("UnitPrice","{0:0.00}") %></span> 
                        </td>
                    </tr>
                </tbody>
            </table>
        </ItemTemplate>
        <SeparatorTemplate>
            <hr />
        </SeparatorTemplate>
    </asp:Repeater>
</asp:Content>
