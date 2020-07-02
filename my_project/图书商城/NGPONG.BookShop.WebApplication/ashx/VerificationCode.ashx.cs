using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.SessionState;

namespace NGPONG.BookShop.WebApplication.ashx
{
    /// <summary>
    /// VerificationCode 的摘要说明
    /// </summary>
    public class VerificationCode : IHttpHandler, IRequiresSessionState
    {

        public void ProcessRequest(HttpContext context)
        {
            // 创建一张图片
            Bitmap map = new Bitmap(150, 25);

            // 创建画人
            Graphics gra = Graphics.FromImage(map);

            // 清楚当前颜色并设置新的前景色
            gra.Clear(Color.FromArgb(240, 240, 240));

            //设置高质量插值法
            gra.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.High;

            //设置高质量,低速度呈现平滑程度
            gra.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.HighQuality;

            // 获取系统中的所有字体
            FontFamily[] fontFamilyArrary = FontFamily.Families;

            Random r = new Random();

            int x_Font = 0;
            int y_Font = 2;

            string Vchar = "a,b,c,d,e,f,g,h,i,j,k,l,m,n,p" +
                           ",q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,P,P,Q" +
                           ",R,S,T,U,V,W,X,Y,Z";

            string[] VcArray = Vchar.Split(new Char[] { ',' });

            string strVerCode = string.Empty;

            // 验证码为4个字符
            for (int i = 0; i < 7; i++)
            {
                string strDraw = VcArray[r.Next(0, VcArray.Length - 1)];

                gra.DrawString(strDraw, new Font(fontFamilyArrary[r.Next(0, fontFamilyArrary.Length - 1)], 14, FontStyle.Bold), new SolidBrush(Color.FromArgb(r.Next(0, 255), r.Next(0, 255), r.Next(0, 255))), new PointF(x_Font, y_Font));

                x_Font += 20;
                strVerCode += strDraw;
            }

            for (int i = 0; i < 200; i++)
            {
                map.SetPixel(r.Next(1, map.Width), r.Next(1, map.Height), Color.FromArgb(r.Next(0, 255), r.Next(0, 255), r.Next(0, 255)));
            }

            using (MemoryStream stream = new MemoryStream())
            {
                map.Save(stream, ImageFormat.Png);

                if (stream.Length > 0)
                {
                    context.Session["RegisterVerCode"] = strVerCode.ToLower();
                    context.Response.ContentType = "image/png";
                    context.Response.BinaryWrite(stream.ToArray());
                }
                else
                {
                    context.Response.ContentType = "text/plain";

                    context.Response.Write("图片信息错误");
                }
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