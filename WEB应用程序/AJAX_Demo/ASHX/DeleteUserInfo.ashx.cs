using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using WP._3_TierArchitecture.Common;

namespace AJAX_Demo.ASHX
{
    /// <summary>
    /// DeleteUserInfo 的摘要说明
    /// </summary>
    public class DeleteUserInfo : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            string userId = context.Request.QueryString["userId"];
            SqlParameter[] parms =
            {
                new SqlParameter("@userId",userId)
            };
            SqlHelper.ExecuteNonQuery("delete from userinfo where userid = @userId", parms);

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