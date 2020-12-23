using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace 母版页的使用
{
    public partial class index : System.Web.UI.Page
    {
        protected void Page_LoadComplete(object sender, EventArgs e)
        {
            // DataSource：指定Repeater的数据源
            this.MyRepeater.DataSource = this.GetDataTable();
            // DataBind()：绑定Repeater所指定的数据源
            this.MyRepeater.DataBind();
        }

        protected DataTable GetDataTable()
        {
            ;
            DataTable dtResult = new DataTable();

            using (SqlConnection conn = new SqlConnection("server=.;uid=sa;pwd=kissyou199;database=MyTestDB"))
            {
                conn.Open();
                using (SqlCommand cmd = new SqlCommand("select * from userinfo", conn))
                {
                    using (SqlDataAdapter adapter = new SqlDataAdapter(cmd))
                    {
                        adapter.Fill(dtResult);
                    }
                }
            }

            return dtResult;
        }
    }
}