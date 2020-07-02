using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Configuration;
using System.Linq;
using System.Web;

namespace 我的第一个WEB窗体应用程序
{
    /// <summary>
    /// DeleteDetail 的摘要说明
    /// </summary>
    public class DeleteDetail : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            string addressID = context.Request.QueryString["addressID"].ToString();

            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["sqlStr"].ConnectionString))
            {
                conn.Open();
                using (SqlCommand cmd = conn.CreateCommand())
                {
                    cmd.CommandText = @"delete from Person.[Address] where AddressID =  @addressID";
                    cmd.Parameters.Add(new SqlParameter("@addressID", addressID));
                    try
                    {
                        cmd.ExecuteNonQuery();
                        context.Response.Redirect("/MyWebApplication.aspx", true);
                    }
                    catch (Exception e)
                    {
                        context.Response.Write(e.Message);
                    }
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