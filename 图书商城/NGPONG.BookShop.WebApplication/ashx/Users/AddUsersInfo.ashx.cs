using NGPONG.BookShop.BLL;
using NGPONG.BookShop.Common.Unitis;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace NGPONG.BookShop.WebApplication.ashx
{
    /// <summary>
    /// AddUsersInfo 的摘要说明
    /// </summary>
    public class AddUsersInfo : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            Model.Users usersModel = new Model.Users() { LoginId = context.Request.Form["txtUserId"], LoginPwd = WebCommon.GetMd5String(context.Request.Form["txtUserPwd"]), Mail = context.Request.Form["txtEmail"], Phone = context.Request.Form["txtPhone"], Name = context.Request.Form["txtUserName"], Address = context.Request.Form["txtAddress"] };

            UsersService service = new UsersService();
            service.AddkUserInfo(usersModel);
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