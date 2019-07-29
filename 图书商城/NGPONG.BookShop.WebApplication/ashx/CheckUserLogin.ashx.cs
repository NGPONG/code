using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.SessionState;

namespace NGPONG.BookShop.WebApplication.ashx
{
    /// <summary>
    /// CheckUserLogin 的摘要说明
    /// </summary>
    public class CheckUserLogin : IHttpHandler, IRequiresSessionState
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            if (context.Session["UserInfo"] == null)
            {
                context.Response.Write(JsonConvert.SerializeObject(new
                {
                    IsSuccess = false,
                    Message = "请登录后再继续操作!",
                    Status = "302",
                    RedirectUrl = $"/Member/Login.aspx?RedirectUrl={context.Request.UrlReferrer.ToString()}"
                }));

                context.Response.End();
            }
            else
            {
                context.Response.Write(JsonConvert.SerializeObject(new
                {
                    IsSuccess = true,
                    RedirectUrl = $"/Member/OrderConfirm.aspx"
                }));

                context.Response.End();
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