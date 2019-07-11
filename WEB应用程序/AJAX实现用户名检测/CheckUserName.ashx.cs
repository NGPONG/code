using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace AJAX实现用户名检测
{
    /// <summary>
    /// CheckUserName 的摘要说明
    /// </summary>
    public class CheckUserName : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";
            string userName = context.Request.Form["userName"];
            if (userName != "pengqi1997428")
            {
                context.Response.Write("用户名不存在！");
            }
            else
            {
                context.Response.Write("用户名正确！");
            }
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