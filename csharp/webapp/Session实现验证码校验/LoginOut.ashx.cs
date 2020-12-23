using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.SessionState;

namespace Session实现验证码校验
{
    /// <summary>
    /// LoginOut 的摘要说明
    /// </summary>
    public class LoginOut : IHttpHandler,IRequiresSessionState
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.Cookies["ASP.NET_SessionId"].Value = context.Request.Cookies["ASP.NET_SessionId"].Value;
            context.Response.Cookies["ASP.NET_SessionId"].Expires = DateTime.Now.AddDays(-1);
            context.Session.Remove("userName");
            context.Response.Redirect("/UserLogin.aspx");
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