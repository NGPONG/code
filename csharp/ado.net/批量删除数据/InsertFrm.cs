using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 批量删除数据
{
    public partial class InsertFrm : Form
    {
        public InsertFrm()
        {
            InitializeComponent();
        }

        private void btnSaveData_Click(object sender, EventArgs e)
        {
            if (txtPwd.Text == null || txtUserName == null) 
            {
                MessageBox.Show("请输入用户名和密码");
                return;
            }

            if (MessageBox.Show("确定保存？", "提示信息", MessageBoxButtons.YesNo, MessageBoxIcon.Warning) != DialogResult.Yes) 
            {
                return;
            }

            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString)) 
            {
                conn.Open();
                string sql =@"insert into dbo.UserInfo( UserName, UserPassWord) values(@userName,@userPassWord)";
                using (SqlCommand cmd = new SqlCommand(sql,conn))
                {

                    #region 参数赋值
                    SqlParameter parameter1 = new SqlParameter("@userName", SqlDbType.NVarChar);
                    parameter1.Value = txtUserName.Text;

                    SqlParameter parameter2 = new SqlParameter("@userPassWord", SqlDbType.NVarChar);
                    parameter2.Value = txtPwd.Text;

                    cmd.Parameters.AddRange(new SqlParameter[] { parameter1, parameter2 });
                    #endregion

                    int i = cmd.ExecuteNonQuery();
                    if (i >= 0)
                    {
                        MessageBox.Show("保存成功！");
                        this.Close();
                    }
                    else 
                    {
                        MessageBox.Show("未知错误");
                    }
                }
            }
        }
    }
}
