using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.SessionState;

namespace AJAX_Demo.ASHX
{
    /// <summary>
    /// CheckUserLogin 的摘要说明
    /// </summary>
    public class CheckUserLogin : IHttpHandler, IRequiresSessionState
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            if (context.Session["UserName"] != null)
            {
                context.Response.Write("{\"isLogin\":\"true\",\"location\":\"/UserInfo.aspx\"}");
            }
            else
            {
                context.Response.Write("{\"isLogin\":\"false\",\"location\":\"\"}");
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