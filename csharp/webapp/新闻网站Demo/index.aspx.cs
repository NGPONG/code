using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace 新闻网站Demo
{
    public partial class index : System.Web.UI.Page
    {
        /// <summary>
        ///  返回结果集
        /// </summary>
        protected DataTable _dtResult = new DataTable();
        /// <summary>
        ///  当前页数
        /// </summary>
        protected int _currentPage = 0;
        /// <summary>
        ///  页数大小
        /// </summary>
        protected int _pageSize = 0;
        protected void Page_Load(object sender, EventArgs e)
        {
            try
            {
                // 第一次请求
                if (string.IsNullOrEmpty(Context.Request.QueryString["PaginalNumber"]))
                {
                    this._currentPage = 1;
                }
                else
                {
                    if (!int.TryParse(Context.Request.QueryString["PaginalNumber"].ToString(), out this._currentPage))
                    {
                        Response.Redirect("\\Html\\Error.html");
                    }
                }

                using (SqlConnection conn = new SqlConnection("server=.;uid=sa;pwd=kissyou199;database=AdventureWorks2008"))
                {
                    using (SqlDataAdapter adapter = new SqlDataAdapter("select Temp.* from (select cast(count(1) over() / 15.0 as decimal) as PageSize, ROW_NUMBER() over(order by AddressID) as rowNumber,AddressLine1 from Person.Address) as Temp where Temp.rowNumber between ((" + this._currentPage + "-1) * 15 + 1) and (" + this._currentPage + " * 15)", conn))
                    {
                        adapter.Fill(this._dtResult);

                        if (this._dtResult != null && this._dtResult.Rows.Count > 0)
                        {
                            this._pageSize = Convert.ToInt32(this._dtResult.Rows[0]["PageSize"]);
                        }
                        else
                        {
                            Response.End();
                        }
                    }
                }
            }
            catch
            {
                Response.Redirect("\\Html\\Error.html");
            }
        }
    }
}