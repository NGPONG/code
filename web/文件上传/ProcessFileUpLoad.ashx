<%@ WebHandler Language="C#" Class="ProcessFileUpLoad" %>

using System;
using System.Web;
using System.IO;

public class ProcessFileUpLoad : IHttpHandler
{

    public void ProcessRequest(HttpContext context)
    {
        context.Response.ContentType = "text/plain";

        string strName = context.Request.Form["txtName"];
        HttpPostedFile file = context.Request.Files["fileUpLoad"]; ;
        if (file != null && file.ContentLength != 0)
        {
            using (Stream stream = file.InputStream)
            {
                System.Drawing.Bitmap map = new System.Drawing.Bitmap(stream);
                
                byte[] buffer = new byte[stream.Length];
                stream.Seek(0, SeekOrigin.Begin);
                stream.Read(buffer, 0, buffer.Length);

                using (FileStream fileWriter = new FileStream(AppDomain.CurrentDomain.BaseDirectory + "img\\" + Guid.NewGuid().ToString() + "-" + file.FileName, FileMode.Create, FileAccess.Write))
                {
                    fileWriter.Write(buffer, 0, buffer.Length);
                }

                context.Response.Write("上传成功！");
            }
        }
        else
        {
            context.Response.Write("上传失败");
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