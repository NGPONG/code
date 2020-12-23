<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="TEST_14.index" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form method="post" action="index.aspx" id="MyForm">
        <select id="dropDownList" name="dropDownList">
            <option selected="selected">shenzhen</option>
            <option>beijing</option>
            <option>guangzhou</option>
        </select>
        <input type="text" name="txtName" id="txtName" value="123"/>
        <input type="submit" value="提交"/>
    </form>
</body>
</html>
