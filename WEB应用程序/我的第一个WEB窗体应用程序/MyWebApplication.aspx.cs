using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace 我的第一个WEB窗体应用程序
{
    public partial class MyWebApplication : System.Web.UI.Page
    {
        public DataTable dtResult = new DataTable();
        protected void Page_Load(object sender, EventArgs e)
        {
            base.ViewState["MyViewState"] = "我是自定义存储的ViewState，但是我只能存储于当前页面的应用程序域下，并且当浏览器关闭的时候我也不复存在";

            if (!IsPostBack)
            {
                using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["sqlStr"].ConnectionString))
                {
                    conn.Open();
                    using (SqlDataAdapter adapter = new SqlDataAdapter("select top 50 AddressID,AddressLine1,StateProvinceID,StateProvinceID,PostalCode,ModifiedDate from Person.[Address] order by AddressID desc", conn))
                    {
                        adapter.Fill(this.dtResult);
                    }
                }
            }

            //this.GridView1.DataSource = dtResult;
            //this.GridView1.DataBind();
        }

    }
}