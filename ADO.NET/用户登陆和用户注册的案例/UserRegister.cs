using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 用户登陆和用户注册的案例
{
    public partial class UserRegister : Form
    {
        public UserRegister()
        {
            InitializeComponent();
        }

        private void btnRegist_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(txtUserName.Text) || string.IsNullOrEmpty(txtPwd.Text) || string.IsNullOrEmpty(txtAge.Text)) 
            {
                return;
            }

            if (txtPwd.Text != txtPwdResult.Text)
            {
                MessageBox.Show("请再次输入密码");
                txtPwdResult.Text = string.Empty;
                txtPwdResult.Focus();
                return;
            }

            string sqlStr = @"server=.;uid=sa;pwd=kissyou199;database=User";

            using (SqlConnection sco = new SqlConnection(sqlStr)) 
            {
                sco.Open();
                using (SqlCommand cmd = new SqlCommand()) 
                {
                    string sql = string.Format("insert into dbo.UserInfo(userName,userPassWord,UserAge) values('{0}','{1}',{2})", txtUserName.Text, txtPwd.Text, int.Parse(txtAge.Text));
                    cmd.Connection = sco;
                    cmd.CommandText = sql;
                    //执行非查询的SQL脚本，返回受影响的行数
                    cmd.ExecuteNonQuery();

                    MessageBox.Show("注册成功！");
                }
            }



        }
    }
}
