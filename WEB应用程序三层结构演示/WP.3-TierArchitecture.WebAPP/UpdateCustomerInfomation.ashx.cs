using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using WP._3_TierArchitecture.BLL;

namespace WP._3_TierArchitecture.WebAPP
{
    /// <summary>
    /// UpdateCustomerInfomation 的摘要说明
    /// </summary>
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

            Dictionary<string, string> dicCustomerInfo = new Dictionary<string, string>();
            dicCustomerInfo.Add("Gender", strGender);
            dicCustomerInfo.Add("FirstName", strFirstName);
            dicCustomerInfo.Add("MiddleName", strMiddleName);
            dicCustomerInfo.Add("LastName", strLastName);
            dicCustomerInfo.Add("CompanyName", strCompanyName);
            dicCustomerInfo.Add("Phone", strPhone);
            dicCustomerInfo.Add("MailAddress", strMailAddress);
            dicCustomerInfo.Add("ID", ID);

            CustomerBLL objCustomerBLL = new CustomerBLL();
            int result = objCustomerBLL.UpdateDetail(dicCustomerInfo);

            if (result > 0)
            {
                context.Response.Redirect("ShowCustomerInfomation.ashx");
            }
            else
            {
                context.Response.Write("Error 404!");
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