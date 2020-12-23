using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Web;

namespace AJAX.ashx
{
    /// <summary>
    /// ShowDateTime 的摘要说明
    /// </summary>
    public class ShowDateTime : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            //byte[] buffer = new byte[1024 * 1024 * 5];
            //context.Response.ContentType = "application/octet-stream";
            //MemoryStream stream = new MemoryStream();
            //FileStream fileRead = new FileStream(@"C:\Users\NGPONG\Desktop\证件照.jpg", FileMode.OpenOrCreate, FileAccess.Read);
            //while (true)
            //{
            //    int i = fileRead.Read(buffer, 0, buffer.Length);
            //    if (i == 0)
            //    {
            //        break;
            //    }
            //    stream.Write(buffer, 0, i);
            //}

            //context.Response.BinaryWrite(stream.ToArray());

            context.Response.ContentType = "text/plain";
            context.Response.Write($"你好，{context.Request.Form["userName"]}！当前时间为【{DateTime.Now.ToString()}】");

            //context.Response.ContentType = "application/octet-stream";
            //context.Response.BinaryWrite(Encoding.Default.GetBytes("你好，吴鹏！"));
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