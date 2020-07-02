using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace TEST_10
{
    /// <summary>
    /// NormalHandler 的摘要说明
    /// </summary>
    public class NormalHandler : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/html";
            MyModule.objMyModuleEventStr.Add("HttpHandler【ProcessRequest】<br/>");
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