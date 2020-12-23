<%@ WebHandler Language="C#" Class="Handler7" %>

using System;
using System.Web;

public class Handler7 : IHttpHandler
{

    public void ProcessRequest(HttpContext context)
    {
        context.Response.ContentType = "text/plain";
        context.Response.Redirect("http://baidu.com");
    }

    public bool IsReusable
    {
        get
        {
            return false;
        }
    }

}