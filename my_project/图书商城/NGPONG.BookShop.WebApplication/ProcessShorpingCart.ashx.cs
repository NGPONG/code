using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace NGPONG.BookShop.WebApplication
{
    /// <summary>
    /// ProcessShorpingCart 的摘要说明
    /// </summary>
    public class ProcessShorpingCart : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";


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