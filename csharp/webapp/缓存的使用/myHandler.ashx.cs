using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Caching;

namespace 缓存的使用
{
    /// <summary>
    /// myHandler 的摘要说明
    /// </summary>
    public class myHandler : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            string strResult = HttpRuntime.Cache["MyCache"] == null ? "缓存的滑动过期时间过期了！" : HttpRuntime.Cache["MyCache"].ToString();

            context.Response.Write(strResult);
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