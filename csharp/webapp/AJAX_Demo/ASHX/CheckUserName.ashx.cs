using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Web;

namespace AJAX_Demo.ASHX
{
    /// <summary>
    /// CheckUserName 的摘要说明
    /// </summary>
    public class CheckUserName : IHttpHandler
    {
        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";
            string isSucess;
            string message;
            if (context.Request.Form["userName"] == "pengqi1997428")
            {
                isSucess = "true";
                message = "用户名正确!";
            }
            else
            {
                isSucess = "false";
                message = "用户名不存在或错误！";
            }

            context.Response.Write("{\"isSuccess\":\"" + isSucess + "\",\"Message\":\"" + message + "\"}");
        }

        public bool IsReusable
        {
            get
            {
                return false;
            }
        }
    }
}