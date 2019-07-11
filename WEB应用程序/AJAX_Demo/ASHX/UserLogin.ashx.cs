using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.SessionState;

namespace AJAX_Demo.ASHX
{
    /// <summary>
    /// UserLogin 的摘要说明
    /// </summary>
    public class UserLogin : IHttpHandler, IRequiresSessionState
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";
            if (context.Request.Form["userName"] == "pengqi1997428" && context.Request.Form["userPwd"] == "kissyou199")
            {
                // 写入Session
                context.Session.Timeout = 20;
                context.Session["UserName"] = "吴鹏";

                // 指定Session Cookie的过期时间
                HttpCookie cookie = new HttpCookie("ASP.NET_SessionId", context.Session.SessionID);
                cookie.Expires = DateTime.Now.AddMinutes(20);
                context.Response.Cookies.Add(cookie);

                context.Response.Write("{\"status\":\"" + 302 + "\",\"location\":\"/UserInfo.aspx\"}");
            }
            else
            {
                context.Response.Write("{\"status\":\"" + 200 + "\"");
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