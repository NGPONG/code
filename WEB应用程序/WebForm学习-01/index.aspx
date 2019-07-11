<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="WebForm学习_01.index" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title></title>
    <script>
        window.onload = function () {

            document.getElementById(<%="\""+this.btnShow.ClientID+"\""%>);
        }
    </script>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Button ID="btnShow" runat="server" Text="Button" OnClick="btnShow_Click" />
        </div>
    </form>

    <input type="text" id="MyTextBox" runat="server" />

</body>
</html>
