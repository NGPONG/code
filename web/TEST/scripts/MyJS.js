$(document).ready(function () {

    window.alert("123");

    $("#btnShowTime").click(function () {

        var date = new Date();
        window.alert(date.toLocaleString());
;    });
});