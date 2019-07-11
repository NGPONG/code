<%@ Page Title="" Language="C#" MasterPageFile="~/Master/CustomerSite.Master" AutoEventWireup="true" CodeBehind="Register.aspx.cs" Inherits="NGPONG.BookShop.WebApplication.Member.Register" %>

<asp:Content ID="Content1" ContentPlaceHolderID="Cunstomer_Header" runat="server">
    <script type="text/javascript">
        $(document).ready(function () {

            // Variable
            var isUserIdExists = false;
            var isVarCodeError = false;
            var userPwdCheck = "";

            var $txtUserId = $("#txtUserId");
            var $txtUserPwd = $("#txtUserPwd");
            var $txtConfirmPwd = $("#txtConfirmPwd");
            var $txtEmail = $("#txtEmail");
            var $txtPhone = $("#txtPhone");
            var $txtVerificationCode = $("#txtVerificationCode");

            // 检测用户名是否已存在
            $txtUserId.blur(function () {

                // Clear Warning Message
                $txtUserId.next().remove();

                // Check UserName exists
                $.ajax({
                    type: "post",
                    url: "/ashx/Users/CheckUsersInfo.ashx",
                    async: true,
                    dataType: "json",
                    data: "UserId=" + $txtUserId.val(),
                    success: function (data, textStatus, jqXHR) {

                        if (data.isExists == "true") {

                            isUserIdExists = true;
                            // 添加错误信息显示
                            $("<span style=\"color:red;font-family:'Microsoft YaHei';padding-left:9px\">用户名已存在!</span>").insertAfter($txtUserId);
                            return;
                        }

                        isUserIdExists = false;
                    }
                });
            });

            $txtUserPwd.blur(function () {

                userPwdCheck = $txtUserPwd.val();
                if ($txtConfirmPwd.val() != "") {

                    // Clear Warning Message
                    $txtConfirmPwd.next().remove();
                    if (this.value != $txtConfirmPwd.val()) {

                        // 添加错误信息显示
                        $("<span style=\"color:red;font-family:'Microsoft YaHei';padding-left:9px\">两次密码不一致!请检查</span>").insertAfter($txtConfirmPwd);
                    }
                }
            });

            $txtConfirmPwd.blur(function () {

                // Clear Warning Message
                $txtConfirmPwd.next().remove();
                if (this.value != userPwdCheck) {

                    // 添加错误信息显示
                    $("<span style=\"color:red;font-family:'Microsoft YaHei';padding-left:9px\">两次密码不一致!请检查</span>").insertAfter($txtConfirmPwd);
                }
            });

            $txtEmail.blur(function () {

                // clear warning message
                $txtEmail.next().remove();
                var regExp = /^([a-zA-Z0-9_-])+@([a-zA-Z0-9_-])+(.[a-zA-Z0-9_-])+/;
                if (!regExp.test(this.value)) {

                    // 添加错误信息显示
                    $("<span style=\"color:red;font-family:'Microsoft YaHei';padding-left:9px\">邮箱格式错误!请检查</span>").insertAfter($txtEmail);
                }
            });

            $txtPhone.blur(function () {

                $txtPhone.next().remove();
                var regExp = /^1[3456789]\d{9}$/;
                if (!regExp.test(this.value)) {

                    // 添加错误信息显示
                    $("<span style=\"color:red;font-family:'Microsoft YaHei';padding-left:9px\">手机格式有误!请检查</span>").insertAfter($txtPhone);
                }
            });

            $txtVerificationCode.blur(function () {

                // Clear Warning Message
                $txtVerificationCode.next().remove();

                $.ajax({
                    type: "post",
                    url: "/ashx/CheckVerCode.ashx",
                    async: true,
                    dataType: "json",
                    data: "VerCode=" + this.value,
                    success: function (data, textStatus, jqXHR) {

                        if (data.isSuccess == "false") {

                            isVarCodeError = true;
                            // 添加错误信息显示
                            $("<span style=\"color:red;font-family:'Microsoft YaHei';padding-left:9px\">" + data.Message + "</span>").insertAfter($txtVerificationCode);
                            return;
                        }
                        isVarCodeError = false;
                    }
                });
            });

            // 更换验证码
            $("#verCode").click(function () {

                this.src = "/ashx/VerificationCode.ashx?" + (new Date()).getMilliseconds();
            });

            $(".btnSubmit").click(function () {

                if ($txtUserId.val() == '') {

                    $.messager.alert('错误', '请输入账号!', 'error');
                    return false;
                }
                else if ($txtUserPwd.val() == '') {

                    $.messager.alert('错误', '请输入密码!', 'error');
                    return false;
                }
                else if ($txtEmail.val() == '') {

                    $.messager.alert('错误', '请输入邮箱账号!', 'error');
                    return false;
                }
                else if ($txtPhone.val() == '') {

                    $.messager.alert('错误', '请输入手机号!', 'error');
                    return false;
                }

                if (isUserIdExists) {

                    $.messager.alert('错误', '当前用户已经存在!请确认后并重新输入!', 'error');
                    return false;
                }
                else if (userPwdCheck != $txtConfirmPwd.val()) {

                    $.messager.alert('错误', '两次密码不一致，请重新确认!', 'error');
                    return false;
                }
                else if (isVarCodeError)
                {
                    $.messager.alert('错误', '验证码错误!', 'error');
                    return false;
                }

                $("#form")[0].submit();
            });
        });
    </script>
    <style type="text/css">
        .auto-style1 {
            height: 33px;
        }
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="Cunstomer_Body" runat="server">
    <div style="font-size: small">
        <table width="80%" height="22" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
                <td style="width: 10px">
                    <img src="../Images/az-tan-top-left-round-corner.gif" width="10" height="28" /></td>
                <td bgcolor="#DDDDCC"><span class="STYLE1">注册新用户</span></td>
                <td width="10">
                    <img src="../Images/az-tan-top-right-round-corner.gif" width="10" height="28" /></td>
            </tr>
        </table>

        <!--注册表单-->
        <form method="post" action="/ashx/Users/AddUsersInfo.ashx" enctype="application/x-www-form-urlencoded" id="form">

            <table width="80%" height="22" border="0" align="center" cellpadding="0" cellspacing="0">
                <tr>
                    <td width="2" bgcolor="#DDDDCC">&nbsp;</td>
                    <td>
                        <div align="center">
                            <table height="61" cellpadding="0" cellspacing="0" style="height:332px;width:500px">
                                <tr>
                                    <td colspan="6" class="auto-style1">
                                        <p class="STYLE2" style="text-align: center">注册新帐户方便又容易</p>
                                    </td>
                                </tr>
                                <tr>
                                    <td width="24%" align="right" valign="top" style="height: 26px"><span class="iconPrompt">*</span> 用户名：</td>
                                    <td valign="top" width="37%" align="left" style="height: 26px">
                                        <input type="text" name="txtUserId" id="txtUserId" /></td>
                                </tr>
                                <tr>
                                    <td width="24%" height="26" align="right" valign="top"><span class="iconPrompt">*</span> 密码：</td>
                                    <td valign="top" width="37%" align="left">
                                        <input type="text" name="txtUserPwd" id="txtUserPwd" /></td>
                                </tr>
                                <tr>
                                    <td width="24%" height="26" align="right" valign="top"><span class="iconPrompt">*</span> 确认密码：</td>
                                    <td valign="top" width="37%" align="left">
                                        <input type="text" name="txtConfirmPwd" id="txtConfirmPwd" /></td>
                                </tr>
                                <tr>
                                    <td width="24%" height="26" align="right" valign="top"><span class="iconPrompt">*</span> Email：</td>
                                    <td valign="top" width="37%" align="left">
                                        <input type="text" name="txtEmail" id="txtEmail" /></td>
                                </tr>
                                <tr>
                                    <td width="24%" height="26" align="right" valign="top"><span class="iconPrompt">*</span> 手机：</td>
                                    <td valign="top" width="37%" align="left">
                                        <input type="text" name="txtPhone" id="txtPhone" /></td>
                                </tr>
                                <tr>
                                    <td width="24%" height="26" align="right" valign="top">真实姓名：</td>
                                    <td valign="top" width="37%" align="left">
                                        <input type="text" name="txtUserName" id="txtUserName" /></td>
                                </tr>
                                <tr>
                                    <td width="24%" height="26" align="right" valign="top">地址：</td>
                                    <td valign="top" width="37%" align="left">
                                        <input type="text" name="txtAddress" id="txtAddress" /></td>
                                </tr>
                                <tr>
                                    <td width="24%" height="26" align="right" valign="top"><span class="iconPrompt">*</span> 验证码：</td>
                                    <td valign="top" width="37%" align="left">
                                        <input type="text" name="txtVerificationCode" id="txtVerificationCode" /></td>
                                </tr>
                                <tr>
                                    <td colspan="2" align="center"><img id="verCode" style="padding-left:45px;cursor:pointer" src="/ashx/VerificationCode.ashx" /></td>
                                </tr>
                                <tr>
                                    <td colspan="2" align="center">
                                        <input type="button" class="btnSubmit" value="点击注册" /></td>
                                </tr>
                            </table>
                            <div class="STYLE5">---------------------------------------------------------</div>
                        </div>
                    </td>
                    <td width="2" bgcolor="#DDDDCC">&nbsp;</td>
                </tr>
            </table>

        </form>

        <table width="80%" height="3" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
                <td height="3" bgcolor="#DDDDCC">
                    <img src="../Images/touming.gif" width="27" height="9" /></td>
            </tr>
        </table>
    </div>
</asp:Content>
