function LoadTable() {

    $.ajax({
        type: "get",
        url: "/ASHX/GetUserInfo.ashx",
        async: true,
        dataType: "json",
        success: function (data, textStatus, jqXHR) {

            for (var item in data) {

                var userId = data[item].UserId;
                var userName = data[item].UserName;
                var userAddress = data[item].UserAddress;
                var userAge = data[item].UserAge;
                var userWork = data[item].UserWork;

                $("#userInfoTable tr:eq(0)").after($("<tr class=\"rowItem\"><td>" + userId + "</td><td>" + userName + "</td><td>" + userAge + "</td><td>" + userAddress + "</td><td>" + userWork + "</td><td><a href=\"#\" class = \"updates\">修改数据</a></td><td><a href=\"#\" class = \"deletes\">删除数据</a></td></tr>"));
            }

            // 每次动态获取完元素后需要重新对元素进行绑定

            // 修改
            $(".updates").click(function () {

                // 获取该行的数据集
                var $tdUserInfo = $(this).parent().prevAll();

                var txtUserName = $tdUserInfo[3].innerText;
                var txtUserAge = $tdUserInfo[2].innerText;
                var txtUserAddress = $tdUserInfo[1].innerText;
                var txtUserWork = $tdUserInfo[0].innerText;
                var txtUserID = $tdUserInfo[4].innerText;

                // 赋值更新文本框
                $("#txtUserName").val(txtUserName);
                $("#txtUserAge").val(txtUserAge);
                $("#txtUserAddress").val(txtUserAddress);
                $("#txtUserWork").val(txtUserWork);
                $("#hidContent").val(txtUserID);

                fadeIn();
                $("#hAddOrUpdateInfoTitle").text("修改数据");

                return false;
            });

            // 删除
            $(".deletes").click(function () {

                var $delete = $(this);
                $.messager.confirm("提示", "是否要删除？", function (isClick) {

                    if (isClick) {

                        $.ajax({
                            type: "get",
                            url: "/ASHX/DeleteUserInfo.ashx?userId=" + $delete.parent().prevAll()[5].innerText,
                            async: true,
                            success: function (data, textStatus, jqXHR) {

                                if (data == "true") {

                                    $.messager.show({
                                        title: '提示信息',
                                        msg: '删除成功！',
                                        showType: 'show'
                                    });

                                    // 清空数据
                                    $(".rowItem").remove();
                                    // 重新加载数据
                                    LoadTable();
                                }
                            }
                        });
                    }
                });
                return false;
            });
        }
    });
}

function clearUserInfoEdit() {


}