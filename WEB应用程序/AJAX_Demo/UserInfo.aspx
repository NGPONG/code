<%@ Page Theme="TableTheme" Language="C#" AutoEventWireup="true" CodeBehind="UserInfo.aspx.cs" Inherits="AJAX_Demo.UserInfo" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title></title>
    <link href="CSS/BackgroundDic.css" rel="stylesheet" />
    <link href="themes/default/easyui.css" rel="stylesheet" />
    <link href="themes/icon.css" rel="stylesheet" />
    <script src="js/TableHelper.js"></script>
    <script src="js/jquery/jquery-1.7.1.min.js"></script>
    <script src="js/jquery.easyui.min.js"></script>
    <script src="js/BackgroundHelper.js"></script>
</head>
<body>
    <%-- HTML_TableElement --%>
    <table id="userInfoTable">
        <tr>
            <th>用户ID</th>
            <th>用户名称</th>
            <th>用户年龄</th>
            <th>用户地址</th>
            <th>用户工作</th>
            <th>修改数据</th>
            <th>删除操作</th>
        </tr>
        <tr>
            <td>
                <img style="height: 30px; cursor: pointer" src="Resource/img/timg.jpg" id="imgAddInfo" />
            </td>
        </tr>
    </table>

    <!--背景层-->
    <div id="backgroundDiv" style="display: none">
    </div>
    <!--前景层-->
    <div id="foregroundDiv" style="display: none">
        <h3 id="hAddOrUpdateInfoTitle"></h3>
        <form id="frmUserInfo">
            用户名称：<input type="text" name="txtUserName" id="txtUserName" value="" /><br />
            用户年龄：<input type="text" name="txtUserAge" id="txtUserAge" value="" /><br />
            用户地址：<input type="text" name="txtUserAddress" id="txtUserAddress" value="" /><br />
            用户工作：<input type="text" name="txtUserWork" id="txtUserWork" value="" /><br />
            <br />
            <input type="hidden" name="hidContent" id="hidContent" value="" />
            <input type="button" value="确定" id="btnSubmit" />
            <input type="button" id="btnReturn" value="返回" />
        </form>
    </div>
    <script>
        $(this).ready(function () {

            initBackground();

            // 欢迎用语
            window.alert("欢迎回来！" +<%="\"" + base.Session["UserName"]?.ToString() + "\"" %>);

            // 加载的时候通过AJAX加载Table数据
            LoadTable();

            // 添加数据
            $("#imgAddInfo").click(function () {

                fadeIn();
                $("#hAddOrUpdateInfoTitle").text("添加数据");
            });

            // 确认&返回
            $("#btnSubmit").click(function () {

                var $txtUserName = $("#txtUserName");
                var $txtUserAge = $("#txtUserAge");
                var $txtUserWork = $("#txtUserWork");
                var $txtUserAddress = $("#txtUserAddress");
                var $hidContent = $("#hidContent");

                $.ajax({
                    type: "post",
                    url: $("#hAddOrUpdateInfoTitle").text() == "添加数据" ? "/ASHX/AddUserInfo.ashx" : "/ASHX/UpdateUserInfo.ashx",
                    async: true,
                    contentType: "application/x-www-form-urlencoded",
                    data: $("#frmUserInfo").serializeArray(),
                    success: function (data, textStatus, jqXHR) {

                        if (data == "true") {

                            $.messager.show({
                                title: '提示信息',
                                msg: $("#hAddOrUpdateInfoTitle").text() == "添加数据" ? "添加成功！" : "修改成功！",
                                showType: 'show'
                            });

                            $("#backgroundDiv").fadeOut(1000).next().fadeOut(1000, function () {

                                // 清空数据
                                $("#foregroundDiv input[type=text]").val("").prev("h3").text("").next("#hidContent").val("");
                                $(".rowItem").remove();

                                // 重新加载数据
                                LoadTable();
                            });
                        }
                    }
                });
            }).next().click(function () {

                $("#backgroundDiv").fadeOut(1000).next().fadeOut(1000, function () {

                    // 清空数据
                    $("#foregroundDiv input[type=text]").val("").prev("h3").text("").nextAll("#hidContent").val("");
                });
            });
        });
    </script>
</body>
</html>
