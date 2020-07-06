using NGPONG.BookShop.BLL;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using NGPONG.BookShop.Model;

namespace NGPONG.BookShop.WebApplication.ashx.Users
{
    /// <summary>
    /// CheckUsersInfo 的摘要说明
    /// </summary>
    public class CheckUsersInfo : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            string userId = context.Request.Form["UserId"];
            Model.Users usersModel = new Model.Users() { LoginId = userId };

            if ((new UsersService()).CheckUserInfoExists(usersModel))
            {
                context.Response.Write("{\"isExists\":\"true\"}");
            }
            else 
            {
                context.Response.Write("{\"isExists\":\"false\"}");
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