<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Additon.aspx.cs" Inherits="加法计算器.Additon" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <input Name="txtNum1" id="txtNum1" type="text" runat ="server"/>
            <h1>+</h1>
            <input Name="txtNum2" id="txtNum2" type="text" /><input id="Submit1" type="submit" value="submit" />
            <h1>=</h1>
            <input Name="txtNum3" id="txtNum3" type="text" value="<%=strResult %>"" />
        </div>
    </form>

    <br />

    <form action="/Additon.aspx" method="post">
<div class="aspNetHidden">
<input type="hidden" name="__VIEWSTATE" id="__VIEWSTATE" value="+hyZ60o0K8myvq8QFsOMf9nswmVr9vAy1iEbKY4366NTcAEBxdJIUtRq49fROElAdOzg4PpomGXBAsOAOVlpOSpb51vE5LWO7+ms6cpe0f4=" />
</div>

<div class="aspNetHidden">

	<input type="hidden" name="__VIEWSTATEGENERATOR" id="__VIEWSTATEGENERATOR" value="13596629" />
	<input type="hidden" name="__EVENTVALIDATION" id="__EVENTVALIDATION" value="F+SPMqQugOdR/+8XShL8ssiiyygbzaGdmDw6CKsru7TzX14OXGhOn0qK9uSQXPWiZCy+qiCQtT0M6xAhhevhcORlvbG/ZkHG5bUhKdAEFidh7Vq+ZCwXUP8jedqQdLXN" />
</div>


        <input type="text" Name="txtNumSpecial1" value="<%=base.txtNumSpecial1Count %>" />+<input type="text" Name="txtNumSpecial2" value="<%=base.txtNumSpecial2Count %>"  /><input type="submit" value="="/><input type="text"/>
    </form>
</body>
</html>
