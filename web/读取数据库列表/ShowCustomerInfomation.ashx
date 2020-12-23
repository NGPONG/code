<%@ WebHandler Language="C#" Class="ShowCustomerInfomation" %>

using System;
using System.Web;
using System.IO;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;
using System.Text;

public class ShowCustomerInfomation : IHttpHandler
{

    public void ProcessRequest(HttpContext context)
    {
        context.Response.ContentType = "text/html";

        using (StreamReader reader = new StreamReader(context.Request.MapPath("index.html")))
        {
            string strHtmlContent = reader.ReadToEnd();
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["sqlConnectionStr"].ConnectionString)) 
            {
                using (SqlCommand cmd = conn.CreateCommand()) 
                {
                    cmd.CommandText = "SELECT TOP 10 * FROM SalesLT.Customer order by CustomerID desc";
                    using (SqlDataAdapter adapter = new SqlDataAdapter(cmd)) 
                    {
                        DataTable dtInfo = new DataTable();
                        adapter.Fill(dtInfo);

                        StringBuilder sb = new StringBuilder();
                        for (int i = 0; i < dtInfo.Rows.Count; i++)
                        {
                            sb.AppendLine(string.Format("<tr><td><a href=\"ShowCustomerDetailInfomation.ashx?userID={0}\">显示详细</a></td><td><a href=\"DeleteCustomerInfomation.ashx?userID={0}\" class = \"deletes\">删除数据</a></td><td><a href=\"#\" class = \"updates\">修改数据</a></td><td>{0}</td><td>{1}</td><td>{2}</td><td>{3}</td><td>{4}</td><td>{5}</td><td>{6}</td><td>{7}</td><td>{8}</td><td>{9}</td><td>{10}</td><td>{11}</td><td>{12}</td><td>{13}</td><td>{14}</td></tr>", dtInfo.Rows[i][0].ToString(), dtInfo.Rows[i][1].ToString(), dtInfo.Rows[i][2].ToString(), dtInfo.Rows[i][3].ToString(), dtInfo.Rows[i][4].ToString(), dtInfo.Rows[i][5].ToString(), dtInfo.Rows[i][6].ToString(), dtInfo.Rows[i][7].ToString(), dtInfo.Rows[i][8].ToString(), dtInfo.Rows[i][9].ToString(), dtInfo.Rows[i][10].ToString(), dtInfo.Rows[i][11].ToString(), dtInfo.Rows[i][12].ToString(), dtInfo.Rows[i][13].ToString(), dtInfo.Rows[i][14].ToString()));
                        }

                        context.Response.Write(strHtmlContent.Replace("$tbody", sb.ToString()));
                    }
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