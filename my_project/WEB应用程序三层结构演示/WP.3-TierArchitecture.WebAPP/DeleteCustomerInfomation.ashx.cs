using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using WP._3_TierArchitecture.BLL;

namespace WP._3_TierArchitecture.WebAPP
{
    /// <summary>
    /// DeleteCustomerInfomation 的摘要说明
    /// </summary>
    public class DeleteCustomerInfomation : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";
            int ID;
            if (int.TryParse(context.Request.QueryString["userID"], out ID))
            {
                CustomerBLL objCustomerBLL = new CustomerBLL();
                int result = objCustomerBLL.DeleteDetail(ID);

                if (result > 0)
                {
                    context.Response.Redirect("ShowCustomerInfomation.ashx");
                }
                else 
                {
                    context.Response.Write("Error 404!");
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