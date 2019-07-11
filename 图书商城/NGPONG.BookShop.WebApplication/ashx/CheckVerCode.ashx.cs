using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.SessionState;

namespace NGPONG.BookShop.WebApplication.ashx
{
    /// <summary>
    /// CheckVerCode 的摘要说明
    /// </summary>
    public class CheckVerCode : IHttpHandler, IRequiresSessionState
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";
            string verCode = context.Request.Form["VerCode"];

            // Session已过期
            if (context.Session["RegisterVerCode"] == null)
            {
                context.Response.Write("{\"isSuccess\":\"false\",\"Message\":\"验证码已过期!请重新刷新\"}");
            }
            else
            {
                if (verCode != context.Session["RegisterVerCode"].ToString())
                {
                    context.Response.Write("{\"isSuccess\":\"false\",\"Message\":\"验证码错误!\"}");
                }
                else
                {
                    context.Response.Write("{\"isSuccess\":\"true\",\"Message\":\"Success!\"}");
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