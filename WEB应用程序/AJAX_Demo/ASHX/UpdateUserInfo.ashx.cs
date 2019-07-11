using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using WP._3_TierArchitecture.Common;

namespace AJAX_Demo.ASHX
{
    /// <summary>
    /// UpdateUserInfo 的摘要说明
    /// </summary>
    public class UpdateUserInfo : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            string userName = context.Request.Form["txtUserName"];
            int userAge;
            if (!int.TryParse(context.Request.Form["txtUserAge"], out userAge))
            {
                userAge = 0; 
            }
            string userAddress = context.Request.Form["txtUserAddress"];
            string userWork = context.Request.Form["txtUserWork"];
            string hidContent = context.Request.Form["hidContent"];

            SqlParameter[] parms =
            {
                new SqlParameter("@userName",userName),
                new SqlParameter("@userAge",userAge),
                new SqlParameter("@userAddress",userAddress),
                new SqlParameter("@userWork",userWork),
                new SqlParameter("@hidContent",hidContent)
            };

            SqlHelper.ExecuteNonQuery("update userinfo set username = @userName,userage = @userAge,useraddress = @userAddress,userwork = @userWork where userid = @hidContent",parms);

            context.Response.Write("true");
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