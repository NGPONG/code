using NGPONG.BookShop.BLL;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.Caching;
using System.Web.Script.Serialization;

namespace NGPONG.BookShop.WebApplication.ashx
{
    /// <summary>
    /// FindPwd 的摘要说明
    /// </summary>
    public class FindPwd : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            string userName = context.Request.Form["name"];
            string userEmail = context.Request.Form["mail"];

            // 校验邮箱和用户名
            if (new BLL.UsersService().CheckUserInfoEmail(new Model.Users { LoginId = userName, Mail = userEmail }))
            {
                // 如果是正确的，则生成一段Guid码，并发送给客户端，同时Server的Cache中根据UserName存储这段Guid码

                string guid = Guid.NewGuid().ToString();

                // 存储在缓存当中，设置一个过期时间，如果过期则直接删除掉，如果用户成功访问修改密码的链接也删除掉
                HttpRuntime.Cache.Insert($"{userName}EmailInfo", new { userName = userName, userGuid = guid }, null, DateTime.Now.AddMinutes(3), Cache.NoSlidingExpiration);

                // 加入Cookie
                HttpCookie cookie = new HttpCookie("emailInfo", "{\"userName\":\"" + userName + "\",\"userGuid\":\"" + guid + "\"}");
                cookie.Expires = DateTime.Now.AddMinutes(3);
                context.Response.Cookies.Add(cookie);

                StringBuilder emailContent = new StringBuilder();
                emailContent.AppendLine("<!DOCTYPE html PUBLIC \" -//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">");
                emailContent.AppendLine("<html xmlns=\"http://www.w3.org/1999/xhtml\" > ");
                emailContent.AppendLine("<head>");
                emailContent.AppendLine("<title>HTML Report</title> ");
                emailContent.AppendLine("</head> ");
                emailContent.AppendLine("<body>");
                emailContent.AppendLine($"<p>{userName}:</p> ");
                emailContent.AppendLine($"<p>请在3分钟之内点击<a href = \"\\Member\\ChangeUserPwd.aspx\">这里</a>完成新密码的修改!</p><br />");
                emailContent.AppendLine("</body>");
                emailContent.AppendLine("</html>");

                UsersService.SendEmail(userEmail, emailContent.ToString(), "密码修改");

                context.Response.Write((new JavaScriptSerializer()).Serialize(new
                {
                    isSuccess = "true"
                }));
            }
            else
            {
                context.Response.Write((new JavaScriptSerializer()).Serialize(new
                {
                    isSuccess = "false",
                    Message = "用户名或邮箱错误!"
                }));
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