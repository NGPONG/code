<%@ WebHandler Language="C#" Class="DeleteCustomerInfomation" %>

using System;
using System.Web;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;

public class DeleteCustomerInfomation : IHttpHandler
{

    public void ProcessRequest(HttpContext context)
    {
        context.Response.ContentType = "text/plain";
        
        int ID;
        if (int.TryParse(context.Request.QueryString["userID"], out ID))
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["sqlConnectionStr"].ConnectionString)) 
            {
                conn.Open();
                
                using (SqlCommand cmd = conn.CreateCommand()) 
                {
                    cmd.CommandText = @"delete from SalesLT.Customer where customerid = @ID";
                    cmd.Parameters.Add(new SqlParameter("@ID", ID));
                    try 
                    {
                        cmd.ExecuteNonQuery();
                        context.Response.Redirect("ShowCustomerInfomation.ashx");
                    }
                    catch(Exception e)
                    {
                        context.Response.Write(e.Message);
                    }
                }
            }
        }
        else 
        {
            context.Response.Write("数据有误！");
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