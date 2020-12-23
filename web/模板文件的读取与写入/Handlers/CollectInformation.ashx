<%@ WebHandler Language="C#" Class="CollectInformation" %>

using System;
using System.Web;
using System.IO;
using System.Drawing;

public class CollectInformation : IHttpHandler {
    
    public void ProcessRequest (HttpContext context) {
        context.Response.ContentType = "text/html";
        string filePath = AppDomain.CurrentDomain.BaseDirectory + "Template\\CollectInfoDemo.html";

        using (StreamReader reader = new StreamReader(filePath))
        {
            context.Response.Write(reader.ReadToEnd());
        }
    }
 
    public bool IsReusable {
        get {
            return false;
        }
    }

}