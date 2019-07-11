using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.IO;
using System.Linq;
using System.Text;
using System.Web;
using WP._3_TierArchitecture.BLL;
using WP._3_TierArchitecture.Common;

namespace WP._3_TierArchitecture.WebAPP
{
    /// <summary>
    /// ShowCustomerInfomation 的摘要说明
    /// </summary>
    public class ShowCustomerInfomation : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/html";

            using (StreamReader reader = new StreamReader(context.Request.MapPath("index.html")))
            {
                string strHtmlContent = reader.ReadToEnd();
                CustomerBLL objCustomerBLL = new CustomerBLL();
                DataTable dtInfo = objCustomerBLL.GetData();

                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < dtInfo.Rows.Count; i++)
                {
                    sb.AppendLine(string.Format("<tr><td><a href=\"ShowCustomerDetailInfomation.ashx?userID={0}\">显示详细</a></td><td><a href=\"DeleteCustomerInfomation.ashx?userID={0}\" class = \"deletes\">删除数据</a></td><td><a href=\"#\" class = \"updates\">修改数据</a></td><td>{0}</td><td>{1}</td><td>{2}</td><td>{3}</td><td>{4}</td><td>{5}</td><td>{6}</td><td>{7}</td><td>{8}</td><td>{9}</td><td>{10}</td><td>{11}</td><td>{12}</td><td>{13}</td><td>{14}</td></tr>", dtInfo.Rows[i][0].ToString(), dtInfo.Rows[i][1].ToString(), dtInfo.Rows[i][2].ToString(), dtInfo.Rows[i][3].ToString(), dtInfo.Rows[i][4].ToString(), dtInfo.Rows[i][5].ToString(), dtInfo.Rows[i][6].ToString(), dtInfo.Rows[i][7].ToString(), dtInfo.Rows[i][8].ToString(), dtInfo.Rows[i][9].ToString(), dtInfo.Rows[i][10].ToString(), dtInfo.Rows[i][11].ToString(), dtInfo.Rows[i][12].ToString(), dtInfo.Rows[i][13].ToString(), dtInfo.Rows[i][14].ToString()));
                }

                context.Response.Write(strHtmlContent.Replace("$tbody", sb.ToString()).Replace("$Test", Test111.MyName));
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