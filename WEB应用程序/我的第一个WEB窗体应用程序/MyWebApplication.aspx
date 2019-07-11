<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="MyWebApplication.aspx.cs" Inherits="我的第一个WEB窗体应用程序.MyWebApplication" Debug="true" %>

<%@ Import Namespace="System.Data.SqlClient" %>
<%@ Import Namespace="System.Data" %>
<%@ Import Namespace="System.Reflection" %>

<!DOCTYPE html>
<link href="CSS/tableStyle.css" rel="stylesheet" />
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title></title>
</head>
<body>
    <%-- HTML_TableElement --%>
    <table>
        <tr>
            <th>AddressID</th>
            <th>AddressLine1</th>
            <th>StateProvinceID</th>
            <th>StateProvinceID</th>
            <th>PostalCode</th>
            <th>ModifiedDate</th>
            <th>删除操作</th>
        </tr>
        <%
            StringBuilder sbResult = new StringBuilder();
            for (int i = 0; i < base.dtResult.Rows.Count; i++)
            {
                DataRow drItem = base.dtResult.Rows[i];
                sbResult.AppendLine(string.Format("<tr><td>{0}</td><td>{1}</td><td>{2}</td><td>{3}</td><td>{4}</td><td>{5}</td><td><a href=\"/DeleteDetail.ashx?addressID={0}\">点击删除</a></td></tr>", drItem["AddressID"].ToString(), drItem["AddressLine1"].ToString(), drItem["StateProvinceID"].ToString(), drItem["StateProvinceID"].ToString(), drItem["PostalCode"].ToString(), drItem["ModifiedDate"].ToString()));
            }

            base.Context.Response.Write(sbResult.ToString());

            base.Context.Response.Write(Assembly.GetExecutingAssembly().Location);
        %>

        <%  for (int i = 0; i < 5; i++) %>
        <%  { %>
                <h1>通过这种方式可以循环创建<1>标签</h1>
        <%  } %>

        <!--注意：使用显示表达式只是输出一段内容，不可以在后面加上;号-->
        <!--因为其内部使用的就是 Response.Write(Text)，当加上;号后就变成Response.Write(Text;)，这时候在编译时就会报错-->
        <%="Text" %>

    </table>

    <!--当在 ASP.NET Form 标签中指定了 enableviewstate，则当前WebForm下的所有服务端控件都不会进行状态保持-->
    <form id="form1" runat="server" enableviewstate="false">

        <!--指定某个控件不进行状态保持机制-->
        <asp:GridView ID="GridView1" runat="server" EnableViewState="false"></asp:GridView>
    </form>

</body>
</html>
