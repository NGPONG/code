<%@ WebHandler Language="C#" Class="Handler4" %>

using System;
using System.Web;

public class Handler4 : IHttpHandler
{

    public void ProcessRequest(HttpContext context)
    {
        context.Response.ContentType = "text/html";
        context.Response.Write(System.Reflection.Assembly.GetExecutingAssembly().Location);
    }

    public bool IsReusable
    {
        get
        {
            return false;
        }
    }

}