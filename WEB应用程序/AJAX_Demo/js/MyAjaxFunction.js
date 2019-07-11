function ajaxHandler(option) {

    var xhr;
    // 针对浏览器：IE7+, Firefox, Chrome, Opera, Safari
    if (XMLHttpRequest) {

        xhr = new XMLHttpRequest();
    }
    // 针对浏览器：低于IE7的版本
    else {

        xhr = new ActiveXObject("Microsoft.XMLHTTP");
    }

    // 指定超时回调
    if (option.timeOut != undefined) {

        xhr.timeout = option.timeOut;

        xhr.ontimeout = function (eventArgs) {

            window.alert("请求超时!");
            // 终止本次AJAX请求，会触发onabort的回调
            xhr.abort();
            isTimeOut = true;
        }
    }

    // 指定响应类型
    if (option.responseType != undefined) {

        xhr.responseType = option.responseType;
    }

    // 异步回调，获取数据
    if (option.isAsync) {

        xhr.onloadend = option.onLoadEnd;
    }

    xhr.open(option.method, option.url, option.isAsync, option.userName, option.userPassWord);

    xhr.send(option.postData);
}

function ajaxStudy() {

    var xhr;
    // 针对浏览器：IE7+, Firefox, Chrome, Opera, Safari
    if (XMLHttpRequest) {

        xhr = new XMLHttpRequest();
    }
    // 针对浏览器：低于IE7的版本
    else {

        xhr = new ActiveXObject("Microsoft.XMLHTTP");
    }

    // 设置超时时间
    // 该属性仅针对异步AJAX，当使用同步状态的AJAX的时候则会抛出异常
    xhr.timeout = 0;

    // 设置需要返回Response的数据类型
    // ""：字符串类型，AJAX默认的返回类型就这种类型
    // arraybuffer：二进制缓冲数组类型，当使用了这种类型之后，访问XMLHttpRequest.ResponseText/ResponseXML属性则会抛出异常
    // blob：二进制大对象，当使用了这种类型之后，访问XMLHttpRequest.ResponseText/ResponseXML属性则会抛出异常
    // json：JSON对象类型，当使用了这种类型之后，访问XMLHttpRequest.ResponseText/ResponseXML属性则会抛出异常
    // document：XML类型，当使用了这种类型之后，访问XMLHttpRequest.ResponseText属性则会抛出异常
    // text：文本类型，当使用了这种类型之后，访问XMLHttpRequest.ResponseXML属性则会抛出异常
    xhr.responseType = "";

    // 状态改变
    xhr.onreadystatechange = function (event) {

        // UNSENT：初始化状态，还未调用open函数
        if (xhr.readyState == 0) {

            console.log("Date【" + (new Date).toGMTString() + "】 AJAX readyState is UNSENT");
        }
        // OPENED：已经调用了open函数
        else if (xhr.readyState == 1) {

            console.log("Date【" + (new Date).toGMTString() + "】 AJAX readyState is OPENED");
        }
        // HEADERS_RECEIVED：已经调用了send方法，并且能够获取到HTTP Response报文信息
        else if (xhr.readyState == 2) {

            console.log("Date【" + (new Date).toGMTString() + "】 AJAX readyState is HEADERS_RECEIVED");
        }
        // LOADING：正在下载Response数据
        else if (xhr.readyState == 3) {

            console.log("Date【" + (new Date).toGMTString() + "】 AJAX readyState is LOADING");
        }
        // DONE：数据下载完成
        else if (xhr.readyState == 4) {

            console.log("Date【" + (new Date).toGMTString() + "】 AJAX readyState is DONE");
        }
    }

    // Upload：请求超时
    xhr.upload.ontimeout = function (event) {

        console.log("Upload 【OnTimeOut】 Event Handler");
    }
    // Upload：上传数据开始
    xhr.upload.onloadstart = function (event) {

        console.log("Upload 【OnLoadStart】 Event Handler");
    }
    // Upload：上传数据当中，50ms触发一次
    xhr.upload.onprogress = function (event) {

        console.log("Upload 【OnPorgress】 Event Handler");
    }
    // Upload：上传数据错误
    xhr.upload.onerror = function (event) {

        console.log("Upload 【OnError】 Event Handler");
    }
    // Upload：终止AJAX
    xhr.upload.onabort = function (event) {

        console.log("Upload 【OnAbort】 Event Handler");
    }
    // Upload：上传数据成功
    xhr.upload.onload = function (event) {

        console.log("Upload 【OnLoad】 Event Handler");
    }
    // Upload：上传数据完成
    xhr.upload.onloadend = function (event) {

        console.log("Upload 【OnLoadEnd】 Event Handler");
    }

    // AJAX：请求超时
    xhr.ontimeout = function (event) {

        console.log("AJAX 【OnTimeOut】 Event Handler");
    }
    // AJAX：下载数据开始
    xhr.onloadstart = function (event) {

        console.log("AJAX 【OnLoadStart】 Event Handler");
    }
    // AJAX：下载数据当中，50ms触发一次
    xhr.onprogress = function (event) {

        console.log("AJAX 【OnProgress】 Event Handler");
    }
    // AJAX：下载数据错误
    xhr.onerror = function (event) {

        console.log("AJAX 【OnError】 Event Handler");
    }
    // AJAX：终止AJAX
    xhr.onabort = function (event) {

        console.log("AJAX 【OnAbort】 Event Handler");
    }
    // AJAX：下载数据成功
    xhr.onload = function (event) {

        console.log("AJAX 【OnLoad】 Event Handler");
    }
    // AJAX：下载数据完成
    xhr.onloadend = function (event) {

        console.log("AJAX 【OnLoadEnd】 Event Handler");

        // 获取HTTP响应状态码
        if (xhr.status == "200" || xhr.statusText == "OK") {

            // 或者指定键的HTTP Reponse头数据
            xhr.getResponseHeader("X-Powered-By");
            // 获取所有Http Response头数据
            xhr.getAllResponseHeaders();

            if (xhr.responseType == "") {

                // var defaultValue = xhr.response;
                // var defaultValue = xhr.responseText;
                // var defaultValue = xhr.ResponseXML;
            }
            else if (xhr.responseType == "text") {

                // var text = xhr.responseText;
                // var text = xhr.response;
            }
            else if (xhr.responseType == "document") {

                // var xml = xhr.ResponseXML;
                // var xml = xhr.response;
            }
            else if (xhr.responseType == "arraybuffer" || xhr.responseType == "blob") {

                // var buffer = xhr.response;
            }
            else if (xhr.responseType == "json") {

                // var json = xhr.response;
            }
        }
    }

    // Start AJAX Egine
    // Method：请求方式
    // URL：请求的URL地址
    // IsAsync：是否为异步请求，如果为异步请求，则需求注册监听事件进行Response的捕获
    // UserName：服务器账号
    // UserPassWord：服务器密码
    xhr.open("POST", "/ashx/ShowDateTime.ashx", true, null, null);

    // 设置Http请求头
    // 该函数必须要在open之后send之前去调用，否则会抛异常
    xhr.setRequestHeader("myRequestHeader", "NGPONG");

    // 发送请求
    // 当为Post请求时，请求体的数据通过该函数去声明
    xhr.send("Hello,World!!!!");
}