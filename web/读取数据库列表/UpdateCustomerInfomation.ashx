<%@ WebHandler Language="C#" Class="UpdateCustomerInfomation" %>

using System;
using System.Web;
using System.Data.SqlClient;
using System.Configuration;

public class UpdateCustomerInfomation : IHttpHandler
{

    public void ProcessRequest(HttpContext context)
    {
        context.Response.ContentType = "text/plain";

        string strGender = context.Request.Form["rdGender"];
        string strFirstName = context.Request.Form["txtFirstName"];
        string strMiddleName = context.Request.Form["txtMiddleName"];
        string strLastName = context.Request.Form["txtLastName"];
        string strCompanyName = context.Request.Form["txtCompanyName"];
        string strPhone = context.Request.Form["txtPhone"];
        string strMailAddress = context.Request.Form["txtMailAddress"];
        string ID = context.Request.Form["hidContent"];

        using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["sqlConnectionStr"].ConnectionString))
        {
            conn.Open();
            using (SqlCommand cmd = conn.CreateCommand())
            {
                cmd.CommandText = "update SalesLT.Customer set Title = @strGender,FirstName = @strFirstName,MiddleName = @strMiddleName,LastName = @strLastName,CompanyName = @strCompanyName,EmailAddress = @strMailAddress,Phone = @strPhone where customerid = @ID";

                SqlParameter[] parms = new SqlParameter[] { new SqlParameter("@strGender", strGender),
                                                                       new SqlParameter("@strFirstName",strFirstName),
                                                                       new SqlParameter("@strMiddleName",strMiddleName),
                                                                       new SqlParameter("@strLastName",strLastName),
                                                                       new SqlParameter("@strCompanyName",strCompanyName),
                                                                       new SqlParameter("@strMailAddress",strMailAddress),
                                                                       new SqlParameter("@strPhone",strPhone),
                                                                       new SqlParameter("@ID",ID)};

                cmd.Parameters.AddRange(parms);

                cmd.ExecuteNonQuery();
            }
        }

        context.Response.Redirect("ShowCustomerInfomation.ashx");
    }

    public bool IsReusable
    {
        get
        {
            return false;
        }
    }

}