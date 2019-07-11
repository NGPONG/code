<%@ WebHandler Language="C#" Class="AddCustomerInfomation" %>

using System;
using System.Web;
using System.Data.SqlClient;
using System.Configuration;

public class AddCustomerInfomation : IHttpHandler
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

        using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["sqlConnectionStr"].ConnectionString))
        {
            conn.Open();
            using (SqlCommand cmd = conn.CreateCommand()) 
            {
                cmd.CommandText = "  insert into SalesLT.Customer(Title,FirstName,MiddleName,LastName,CompanyName,EmailAddress,Phone,PasswordHash,ModifiedDate,PasswordSalt) values(@strGender,@strFirstName,@strMiddleName,@strLastName,@strCompanyName,@strMailAddress,@strPhone,'test',GETDATE(),'test')";

                SqlParameter[] parms = new SqlParameter[] { new SqlParameter("@strGender", strGender),
                                                                       new SqlParameter("@strFirstName",strFirstName),
                                                                       new SqlParameter("@strMiddleName",strMiddleName),
                                                                       new SqlParameter("@strLastName",strLastName),
                                                                       new SqlParameter("@strCompanyName",strCompanyName),
                                                                       new SqlParameter("@strMailAddress",strMailAddress),
                                                                       new SqlParameter("@strPhone",strPhone)};

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