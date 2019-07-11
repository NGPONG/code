using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace 自定义HttpHandler
{
    public class MyImageHandler : IHttpHandler
    {
        public bool IsReusable
        {
            get;
        }

        public void ProcessRequest(HttpContext context)
        {
            // 当前是一个图片请求，但是我不想输出图片了！
            context.Response.Write("Hello!Is Nothing Here");
            context.Response.End();
        }
    }
}