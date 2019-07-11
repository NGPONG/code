using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.SessionState;

namespace AJAX_Demo
{
    public class CheckUserLoginSession : IHttpModule
    {
        public void Dispose()
        {
            
        }

        public void Init(HttpApplication context)
        {
            context.PostAcquireRequestState += this.Context_PostAcquireRequestState;
        }

        private void Context_PostAcquireRequestState(object sender, EventArgs e)
        {
            HttpApplication application = sender as HttpApplication;

            // ASPX页检验Session
            if (application.Request.CurrentExecutionFilePathExtension == ".aspx")
            {
                if (application.Session["userName"] == null)
                {
                    application.Response.Redirect("/index.html");
                    return;
                }
                else
                {
                    // 设置Session Cookie的滑动过期时间
                    HttpCookie cookie = new HttpCookie("ASP.NET_SessionId", application.Request.Cookies["ASP.NET_SessionId"].Value);
                    cookie.Expires = DateTime.Now.AddMinutes(20);
                    application.Response.Cookies.Add(cookie);
                } 
            }
        }
    }
}