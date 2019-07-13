using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.SessionState;

namespace NGPONG.BookShop.WebApplication.ashx
{
    /// <summary>
    /// CheckLogin 的摘要说明
    /// </summary>
    public class CheckLogin : IHttpHandler, IRequiresSessionState
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            CheckUserLogin(context);
        }

        public void CheckUserLogin(HttpContext context)
        {
            string userName = context.Request.Form["txtName"];
            string userPwd = BookShop.Common.Unitis.WebCommon.GetMd5String(context.Request.Form["txtPwd"]);

            // Model
            Model.Users usersModel = new Model.Users() { LoginId = userName, LoginPwd = userPwd };

            BLL.UsersService usersService = new BLL.UsersService();
            List<Model.Users> userInfo = usersService.GetUserInfo(usersModel);
            // 用户名和密码正确
            if (userInfo.Count > 0)
            {
                // 写入Session
                context.Session["UserInfo"] = usersModel;

                // 写入Cookie
                if ((context.Request.Form["cbAutoLogin"] == "on" ? true : false))
                {
                    // UserName
                    context.Response.Cookies["cp1"].Value = userName;
                    context.Response.Cookies["cp1"].Expires = DateTime.Now.AddDays(2);
                    // UserPwd
                    context.Response.Cookies["cp2"].Value = userPwd;
                    context.Response.Cookies["cp2"].Expires = DateTime.Now.AddDays(2);
                }
            }
            else
            {
                context.Response.Write("用户名或密码错误！");
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