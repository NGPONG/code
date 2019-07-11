using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using TEST_13;

namespace TEST_14
{
    /// <summary>
    /// MyHandler 的摘要说明
    /// </summary>
    public class MyHandler : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            System.Web.Caching.Cache cache = HttpContext.Current.Cache;
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