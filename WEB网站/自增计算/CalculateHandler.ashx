<%@ WebHandler Language="C#" Class="CalculateHandler" %>

using System;
using System.Web;
using System.IO;

public class CalculateHandler : IHttpHandler
{

    public void ProcessRequest(HttpContext context)
    {
        context.Response.ContentType = "text/html";
        string strContent = string.Empty;
        using (StreamReader reader = new StreamReader(context.Request.MapPath("TemplatePage.html")))
        {
            strContent = reader.ReadToEnd();
        }

        if (context.Request.HttpMethod.Equals("GET"))
        {
            context.Response.Write(strContent.Replace("$number", "0").Replace("$txtnumber", "0"));
        }
        else
        {
            string strNumber = (Convert.ToInt32(context.Request.Form["txtNumber"]) + 1).ToString();
            context.Response.Write(strContent.Replace("$number", strNumber).Replace("$txtnumber", strNumber));
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