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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(txtUserName.Text) || string.IsNullOrEmpty(txtPwd.Text)) 
            {
                MessageBox.Show("用户名密码不能为空");
                return;
            }

            string strSql = @"server=.;uid=sa;pwd=kissyou199;database=User";
            using (SqlConnection conn = new SqlConnection(strSql)) 
            {
                conn.Open();
                using (SqlCommand cmd = new SqlCommand()) 
                {
                    //通过 @参数名 在SQL脚本中填写参数，作用类似于占位符
                    string sql = string.Format("select count(1) from dbo.UserInfo where userName = @userName and userPassWord = @userPassWord");
                    //赋予参数的值
                    cmd.Parameters.AddWithValue("@userName", txtUserName.Text);
                    cmd.Parameters.AddWithValue("@userPassWord", txtPwd.Text);
                  
                    cmd.CommandText = sql;
                    cmd.Connection = conn;

                    //执行一个查询语句
                    //返回一个查询结果表中的：第一行第一列的内容
                    object o = cmd.ExecuteScalar(); 

                    if (int.Parse(o.ToString()) >= 1)
                    {
                        txtUserName.Text = string.Empty;
                        txtUserName.Focus();
                        txtPwd.Text = string.Empty;

                        MessageBox.Show("登陆成功！");
                    }
                    else 
                    {
                        txtUserName.Text = string.Empty;
                        txtUserName.Focus();
                        txtPwd.Text = string.Empty;

                        MessageBox.Show("登录失败");
                    }
                }
            }

            
        }

        private void btnRegister_Click(object sender, EventArgs e)
        {
            UserRegister ur = new UserRegister();
            ur.Show();
        }
    }
}
