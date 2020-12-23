using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Web;

namespace TEST_17
{
    /// <summary>
    /// Handler1 的摘要说明
    /// </summary>
    public class Handler1 : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "image/png";
            Image img = Image.FromFile(@"C:\Users\NGPONG\Desktop\源码\WEB应用程序\TEST-17\我的身份证\微信截图_20190710214844.png");
            Bitmap map = new Bitmap(100, 100);

            Graphics graphics = Graphics.FromImage(map);
            //设置高质量插值法
            graphics.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.High;
            //设置高质量,低速度呈现平滑程度
            graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.HighQuality;

            graphics.DrawImage(img, new Rectangle(new Point(0, 0), new Size(100,100)),new Rectangle(new Point(50,50),new Size(100,100)),GraphicsUnit.Pixel);

            using (MemoryStream stream = new MemoryStream())
            {
                map.Save(stream, ImageFormat.Jpeg);
                context.Response.BinaryWrite(stream.ToArray());
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
}