using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Web;

namespace Session实现验证码校验
{
    /// <summary>
    /// VerificationCode 的摘要说明
    /// </summary>
    public class VerificationCode : IHttpHandler,System.Web.SessionState.IRequiresSessionState
    {

        public void ProcessRequest(HttpContext context)
        {
            // 创建一张图片
            Bitmap map = new Bitmap(80, 25);

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

            string Vchar = "0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f,g,h,i,j,k,l,m,n,p" +
        ",q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,P,P,Q" +
        ",R,S,T,U,V,W,X,Y,Z";

            string[] VcArray = Vchar.Split(new Char[] { ',' });

            string verificationCode = string.Empty;
            // 验证码为4个字符
            for (int i = 0; i < 4; i++)
            {
                string strDraw = VcArray[r.Next(0, VcArray.Length - 1)];

                gra.DrawString(strDraw, new Font(fontFamilyArrary[r.Next(0, fontFamilyArrary.Length - 1)], 14, FontStyle.Bold), new SolidBrush(Color.FromArgb(r.Next(0, 255), r.Next(0, 255), r.Next(0, 255))), new PointF(x_Font, y_Font));

                x_Font += 20;

                verificationCode += strDraw;
            }

            for (int i = 0; i < 200; i++)
            {
                map.SetPixel(r.Next(1, map.Width), r.Next(1, map.Height), Color.FromArgb(r.Next(0, 255), r.Next(0, 255), r.Next(0, 255)));
            }

            using (MemoryStream stream = new MemoryStream())
            {
                map.Save(stream, ImageFormat.Png);

                context.Response.ContentType = "image/png";
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