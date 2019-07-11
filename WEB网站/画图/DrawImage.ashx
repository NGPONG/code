<%@ WebHandler Language="C#" Class="DrawImage" %>

using System;
using System.Web;
using System.Drawing;
using System.Drawing.Imaging;

public class DrawImage : IHttpHandler
{

    public void ProcessRequest(HttpContext context)
    {
        context.Response.ContentType = "text/html";

        Bitmap map = new Bitmap(@"C:\Users\Administrator\Desktop\我的身份证\正面.jpg");
        Graphics gra = Graphics.FromImage(map);
        gra.DrawString("吴鹏水印", new Font("微软雅黑", 50, FontStyle.Bold), Brushes.Red, new PointF(map.Width - 300, map.Height - 100));

        map.Save(context.Request.MapPath("\\img\\1.jpg"), System.Drawing.Imaging.ImageFormat.Jpeg);

        
        System.Text.StringBuilder sb = new System.Text.StringBuilder();
        sb.AppendLine("<!DOCTYPE html>");
        sb.AppendLine("<html xmlns=\"http://www.w3.org/1999/xhtml\">");
        sb.AppendLine("<head>");
        sb.AppendLine("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>");
        sb.AppendLine("    <title></title>");
        sb.AppendLine("</head>");
        sb.AppendLine("<body>");
        sb.AppendLine("     <img src=\"img/1.jpg\" />");
        sb.AppendLine("</body>");
        sb.AppendLine("<!DOCTYPE html>");
        sb.AppendLine("</html>");
        context.Response.Write(sb.ToString());
    }

    public bool IsReusable
    {
        get
        {
            return false;
        }
    }

}