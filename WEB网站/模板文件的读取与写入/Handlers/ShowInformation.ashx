<%@ WebHandler Language="C#" Class="ShowInformation" %>

using System;
using System.Web;

public class ShowInformation : IHttpHandler
{

    public void ProcessRequest(HttpContext context)
    {
        context.Response.ContentType = "text/html";
        string strUserName = string.Empty;
        string strUserPwd = string.Empty;
        
        if (context.Request.HttpMethod.Equals("POST"))
        {
            strUserName = context.Request.Form["userName"];
            strUserPwd = context.Request.Form["userPwd"];
        }
        else if (context.Request.HttpMethod.Equals("GET")) 
        {
            strUserName = context.Request.QueryString["userName"];
            strUserPwd = context.Request.QueryString["userPwd"];
        }

        using (System.IO.StreamReader reader = new System.IO.StreamReader(System.IO.Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Template\\TableDemo.html"))) 
        {
            string strHtmlContent = reader.ReadToEnd();
            context.Response.Write(strHtmlContent.Replace("$placeholderUserName", strUserName).Replace("$placeholderUserPwd", strUserPwd));
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