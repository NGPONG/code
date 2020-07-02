using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebForm学习_02
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

        protected void MyRepeater_ItemCommand(object source, RepeaterCommandEventArgs e)
        {
            // 如果是删除类别控件所触发的ItemCommand事件则进行下面的逻辑
            // 因为一个Regepter下可能有很多类别CommandName的控件
            if (e.CommandName?.ToString() == "btnDeletesbtnDeletes")
            {
                string activeControlID = e.CommandArgument.ToString();

                // activeControlID Do Something.....
            }
            else
            {
                string str = "我是其他类别的。。。";
            }
        }

        protected void Unnamed_Click(object sender, EventArgs e)
        {
            Response.Write("会先触发我的事件噢");
        }
    }
}