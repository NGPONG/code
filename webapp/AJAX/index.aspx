<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="AJAX.index" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title></title>
    <script src="js/jquery/jquery-1.7.1.min.js"></script>
    <script src="js/MyAjaxFunction.js"></script>
    <script>
        var isTimeOut = false;

        $(document).ready(function () {

            $("#btnShowTime").click(function () {

                ajaxHandler({
                    timeOut: 3000,
                    responseType: "",
                    isAsync: true,
                    onLoadEnd: function (eventArgs) {

                        var xhr = eventArgs.currentTarget;
                        if (xhr.status == "200" || xhr.statusText == "OK") {

                            window.alert(xhr.response);
                        }
                        else {

                            if (!isTimeOut) {

                                window.alert("未知错误！");
                                xhr.abort();
                            }
                            else {

                                isTimeOut = false;
                            }
                        }
                    },
                    method: "post",
                    url: "/ashx/ShowDateTime.ashx",
                    userName: null,
                    userPassWord: null,
                    postData: "Hello,World"
                });
            });
        });
    </script>
</head>
<body>
    <input id="btnShowTime" value="显示服务器时间" type="button" />
</body>
</html>
