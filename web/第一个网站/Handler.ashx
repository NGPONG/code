<%@ WebHandler Language="C#" Class="Handler" %>

using System;
using System.Web;
using System.IO;
using System.Text;
using System.Collections.Generic;

public class Handler : IHttpHandler 
{
    
    public void ProcessRequest (HttpContext context) 
    {
        context.Response.ContentType = "text/html";
        context.Response.ContentEncoding = System.Text.Encoding.UTF8;
        string filePath = context.Request.MapPath("index.html");
        
        // 模板文件
        using (StreamReader reader = new StreamReader(filePath, Encoding.UTF8))
        {
            string strHtmlContent = reader.ReadToEnd();
            List<string> listParms = new List<string>();
            List<string> listValues = new List<string>();
            listParms.Add("$name");
            listValues.Add("吴鹏");
            listParms.Add("$age");
            listValues.Add("22");
            listParms.Add("$gender");
            listValues.Add("男");
            listParms.Add("$work");
            listValues.Add("程序员");
            listParms.Add("$userName");
            listValues.Add("pengqi1997428");
            listParms.Add("$passWord");
            listValues.Add("kissyou199");
            strHtmlContent = Handler.Replace(strHtmlContent, listParms, listValues);
            context.Response.Write(strHtmlContent);
        }
    }

    public static string Replace(string content, List<string> listParms, List<string> listValues)
    {
        try
        {
            for (int i = 0; i < listParms.Count; i++)
            {
                content = content.Replace(listParms[i], listValues[i]);
            }
            return content;
        }
        catch (Exception objException)
        {
            throw new Exception(objException.Message);
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