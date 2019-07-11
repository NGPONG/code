function fadeOut() {

    $("#backgroundDiv").fadeOut(1000).next().fadeOut(1000);
}

function fadeIn() {

    $("#backgroundDiv").css({ "height": window.innerHeight, "width": window.innerWidth }).fadeIn(1000).next().fadeIn(1000);
}

function initBackground() {

    // 设置背景层的宽度和高度和点击效果
    $("#backgroundDiv").css({ "height": window.innerHeight, "width": window.innerWidth });

    // 甚至前景层位置、内容位置和点击效果
    $("#foregroundDiv").css({ "left": window.innerWidth / 2.6 + "px", "top": window.innerHeight / 4 + "px" }).children("#hAddOrUpdateInfoTitle").css("padding-left", $("#foregroundDiv").width() / 2.6 + "px");
}