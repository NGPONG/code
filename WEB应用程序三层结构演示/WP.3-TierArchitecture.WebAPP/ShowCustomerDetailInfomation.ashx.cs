using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace WP._3_TierArchitecture.WebAPP
{
    /// <summary>
    /// ShowCustomerDetailInfomation 的摘要说明
    /// </summary>
    public class ShowCustomerDetailInfomation : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";

            // 做一次尝试转换，因为这是一个GET请求，用户可以在浏览器的地址栏上随意改造发送过来的参数数据
            int ID;
            if (int.TryParse(context.Request.QueryString["userID"], out ID))
            {
                context.Response.Write(string.Format("你所点击的用户ID为{0}", ID));
            }
            else
            {
                context.Response.Write("输入的数据有误！！");
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