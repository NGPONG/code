using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace AJAX_Demo.test
{
    /// <summary>
    /// test_ashx 的摘要说明
    /// </summary>
    public class test_ashx : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";
            context.Response.Write("123123");
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