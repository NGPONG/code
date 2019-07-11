using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace TEST_09
{
    /// <summary>
    /// Handler2 的摘要说明
    /// </summary>
    public class Handler2 : IHttpHandler, System.Web.SessionState.IRequiresSessionState
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";
            string id = context.Session.SessionID;

            HttpCookieCollection cookieResponse = context.Response.Cookies;
            HttpCookieCollection cookieRequest = context.Request.Cookies;
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