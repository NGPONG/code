using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Cookie验证页
{
    /// <summary>
    /// CookieCheck 的摘要说明
    /// </summary>
    public class CookieCheck : IHttpHandler
    {
        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            string redirectUrl = context.Request.QueryString["redirect"];
            if (context.Request.Cookies["CookieTest"] == null)
            {
                context.Response.Redirect(redirectUrl + "?AcceptCookie=false");
            }
            else
            {
                // 删除刚刚创建的cookie
                HttpCookie cookie = new HttpCookie("CookieTest");
                cookie.Expires = DateTime.Now.AddDays(-1);
                context.Response.Cookies.Add(cookie);

                context.Response.Redirect(redirectUrl + "?AcceptCookie=true");
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