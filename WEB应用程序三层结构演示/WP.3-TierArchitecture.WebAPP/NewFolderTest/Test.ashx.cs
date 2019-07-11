using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace WP._3_TierArchitecture.WebAPP
{
    /// <summary>
    /// Test 的摘要说明
    /// </summary>
    public class Test : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";
            string str = AppDomain.CurrentDomain.BaseDirectory;

            context.Response.Write("Hello World");
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