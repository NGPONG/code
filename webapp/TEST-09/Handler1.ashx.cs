using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace TEST_09
{
    /// <summary>
    /// Handler1 的摘要说明
    /// </summary>
    public class Handler1 : IHttpHandler, System.Web.SessionState.IRequiresSessionState
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";
            context.Session.Timeout = 1;
            context.Session.Add("SessionTest", "哈哈哈哈哈哈");
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