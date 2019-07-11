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

namespace 用户输错密码3次_账号锁定一分钟
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString)) 
            {
                conn.Open();

                using (SqlCommand cmd = conn.CreateCommand()) 
                {
                    //查询用户输入的用户名密码在数据库中是否存在
                    string sql = string.Format(@"select ID, UserName, UserPassWord, ErrorTime, ErrorEndDateTime from dbo.UserInfo where UserName='{0}' and UserPassword = '{1}'", txtName.Text, txtPwd.Text);

                    cmd.CommandText = sql;

                    UserInfo user = null;
                    using (SqlDataReader reader = cmd.ExecuteReader()) 
                    {
                        //如果成功查询到用户输入的Name和Pwd在数据库中存在，则创建UserInfo对象
                        if (reader.HasRows)
                        {
                            reader.Read();
                            user = new UserInfo();
                            user.ID = int.Parse(reader["ID"].ToString());
                            user.UserName = reader["UserName"].ToString();
                            user.UserPassWord = reader["UserPassWord"].ToString();
                            user.ErrrorTime = int.Parse(reader["ErrorTime"].ToString());
                            user.ErrorEndDateTime = DateTime.Parse(reader["ErrorEndDateTime"].ToString());
                        }
                        //SqlDataReader对象资源释放前还在占用SqlConnection通道进行数据的读取，此时不允许其它的SqlCommand对象使用SqlConnection通道进行操作
                    }//End of SqlDateReader1

                    if (user == null)//用户输入的用户名或密码错误
                    {
                        bool flag = true;
                        //让该用户名的错误次数和错误时间进行调整
                        string sqlNew = string.Format(@"update dbo.UserInfo set ErrorTime=ErrorTime+1, ErrorEndDateTime=getdate() where UserName='{0}'", txtName.Text);
                        cmd.CommandText = sqlNew;
                        int i = cmd.ExecuteNonQuery();//当SQL脚本成功执行，返回受影响函行数
                        MessageBox.Show("用户名或密码错误");
                        if (i >= 1) //证明用户名没有错误
                        {
                            sqlNew = string.Format(@"select ID, UserName, UserPassWord, ErrorTime, ErrorEndDateTime from dbo.UserInfo where UserName='{0}'", txtName.Text);
                            cmd.CommandText = sqlNew;
                            using (SqlDataReader reader = cmd.ExecuteReader())
                            {
                                reader.Read();
                                //int id = int.Parse(reader["ID"].ToString());
                                //string userName = reader["UserName"].ToString();
                                //string userPassWord = reader["UserPassWord"].ToString();
                                int errorTime = int.Parse(reader["ErrorTime"].ToString());
                                DateTime dt = DateTime.Parse(reader["ErrorEndDateTime"].ToString());

                                if (errorTime > 3 || DateTime.Now.Subtract(dt).TotalSeconds < 0)
                                {
                                    flag = false;
                                    MessageBox.Show("您的账号已被锁定1分钟");
                                }
                            }//End of SqlDataReader2

                            if (!flag) 
                            {
                                sqlNew = string.Format(@"update dbo.UserInfo set ErrorEndDateTime=dateadd(minute,1,ErrorEndDateTime) where UserName='{0}'", txtName.Text);
                                cmd.CommandText = sqlNew;
                                cmd.ExecuteNonQuery();
                            }
                        }
                    }//End of if(user == null)
                    else if(user != null)//当用户名密码正确的时候，判断错误次数和错误时间
                    {
                        //如果在用户名密码输入正确，但是错误次数和错误时间符合要求的情况下
                        if (user.ErrrorTime < 3 || DateTime.Now.Subtract(user.ErrorEndDateTime).TotalSeconds > 0)
                        {
                             string sqlNew = string.Format(@"update dbo.UserInfo set ErrorTime=0, ErrorEndDateTime=getdate() where UserName='{0}'", txtName.Text);
                            cmd.CommandText = sqlNew;
                            cmd.ExecuteNonQuery();
                            MessageBox.Show("登陆成功！");
                        }
                        else 
                        {
                            MessageBox.Show("您的账号已被锁定1分钟");
                        }
                    }

                }//End of SqlCommand
            }//End of SqlConnection

        }
    }
}
