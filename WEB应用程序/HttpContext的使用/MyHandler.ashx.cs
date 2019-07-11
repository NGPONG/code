using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.SessionState;

namespace HttpContext的使用
{
    /// <summary>
    /// MyHandler 的摘要说明
    /// </summary>
    public class MyHandler : IHttpHandler, IRequiresSessionState
    {

        public void ProcessRequest(HttpContext context)
        {

        }

        #region Session
        //// 获取或设置Session
        //// 设置Session
        //// 方式一：不推荐，有可能导致Session键的重复问题
        //context.Session.Add("MySession", "Hello,World");
        //// 方式二：推荐，会自动把已经在的键的值覆盖成我们新设置的
        //context.Session["MySession"] = "Hello,World";

        //// 获取Session
        //string sessionValue = context.Session["MySession"].ToString();

        //// Timeout
        //context.Session.Timeout = 10;

        //// IsNewSession
        //if (context.Session.IsNewSession)
        //{

        //}

        //// SessionID
        //string sessionID = context.Session.SessionID;
        #endregion

        #region Server
        //// UrlDecode()
        //string valueDecode = context.Server.UrlDecode("localhost%3a8888%2f%e6%88%91%e6%98%af%e4%b8%80%e8%88%ac%e5%a4%84%e7%90%86%e7%a8%8b%e5%ba%8f.ashx");

        //// UrlEncode()
        //string valueEncode = context.Server.UrlEncode("localhost:8888/我是一般处理程序.ashx");

        //// HtmlDecode()
        //string encodeValue = context.Server.HtmlDecode("&lt;h1&gt;你好啊，我会被解码成HTML标签页噢&lt;/h1&gt;gt;");
        //context.Response.Write(encodeValue);

        //// HtmlEncode()
        //string encodeValue = context.Server.HtmlEncode("<h1>你好啊，我不会被当成是HTML标签页噢</h1>");
        //context.Response.Write(encodeValue);

        //// Execute()
        //context.Server.Execute("WebForm1.aspx");

        //// Transfer()
        //context.Server.Transfer("WebForm1.aspx");

        //// MapPath()
        //string filePath = context.Server.MapPath("/MyFile");
        #endregion

        #region Response
        //// End()
        //context.Response.Write("Hello,World!");
        //context.Response.End();

        //// Clear()
        //context.Response.Write("Hello,World!");
        //context.Response.Clear();

        //// Flush()
        //context.Response.Write("Hello,World!");
        //context.Response.Flush();

        //// Redirect()
        //context.Response.Redirect("/index.html", true);

        //// BinaryWrite()
        //context.Response.ContentType = "text/html";
        //using (MemoryStream stream = new MemoryStream(Encoding.Default.GetBytes("Hello,World")))
        //{
        //    context.Response.BinaryWrite(stream.ToArray());
        //}

        //// Write()
        //context.Response.Write("Hello,World!");

        //// Cookie
        //HttpCookie cookie = new HttpCookie("myCookie", "Hello,World");
        //context.Response.Cookies.Add(cookie);

        //// Buffer、BufferOutput
        //context.Response.BufferOutput = true;
        //context.Response.Buffer = true;

        //// ContentType
        //context.Response.ContentType = "text/html";

        //// ContentEncoding
        //context.Response.ContentEncoding = Encoding.ASCII; 
        #endregion

        #region HttpCookie
        //// Domain
        //HttpCookie cookie = new HttpCookie("MyCookie", "Hello,World");
        //cookie.Domain = "TestDomain.localhost.com";
        //context.Response.Cookies.Add(cookie);

        //// values：获取或设置多值Cookie的两种方式
        //// 方式一：
        //HttpCookie cookie = new HttpCookie("valuesCookie");
        //// 获取多值Cookie
        //string cookieValue1 = cookie.Values["apart1"];
        //// 设置多值Cookie
        //cookie.Values.Add("apart1", "Hello Cookie!");

        //// 方式二：
        //// 获取多值Cookie
        //string cookieValue2 = context.Request.Cookies["valuesCookies"]["apart1"];
        //// 设置多值Cookie
        //context.Response.Cookies["valuesCookies"]["apart2"] = "Hello World!";

        //// Value：获取或设置Cookie值的两种方式
        //// 方式一：
        //HttpCookie cookie = context.Request.Cookies["MyCookie"];
        //// 设置Cookie的值
        //cookie.Value = "Hello World!";
        //// 获取Cookie的值
        //string value = cookie.Value;

        //// 方式二：
        //// 设置Cookie的值
        //context.Response.Cookies["MyCookie"].Value = "Hello World";
        //// 获取Cookie的值
        //string value2 = context.Request.Cookies["MyCookie"].Value;

        //// Name
        //string name = cookie.Name; 
        #endregion

        #region Request
        //// MapPath()
        //string filePath = context.Request.MapPath("MyFile");

        //// Cookies
        //HttpCookie myCookie = context.Request.Cookies["myCookie"];

        //// UserHostAddress
        //string ipAddress = context.Request.UserHostAddress;

        //// UrlReferrer
        //string urlReferrer = context.Request.UrlReferrer.ToString();

        //// URL
        //string url = context.Request.Url.ToString();

        //// Files
        //HttpPostedFile myFile = context.Request.Files["fileUpload"];
        //// HttpPostedFile.InputStream：获取当前文件的流
        //Stream stream = myFile.InputStream;
        //// HttpPostedFile.ContentType：获取当前文件的文件类型
        //string contentType = myFile.ContentType;
        //// HttpPostedFile.FileName：获取当前文件名
        //string fileName = myFile.FileName;
        //// HttpPostedFile.ContentLength：获取文件的字节大小
        //int fileLength = myFile.ContentLength;
        //// HttpPostedFile.SaveAs()：将文件保存至指定位置
        //myFile.SaveAs(context.Request.MapPath($"/MyFile/{fileName}"));

        //// HttpMethod
        //string httpMethod = context.Request.HttpMethod;

        //// QueryString
        //string userName = context.Request.QueryString["txtName"];
        //string userPwd = context.Request.QueryString["txtPwd"];

        //// Form
        //string userName = context.Request.Form["txtName"];
        //string userPwd = context.Request.Form["txtPwd"]; 
        #endregion

        public bool IsReusable
        {
            get
            {
                return false;
            }
        }
    }
}