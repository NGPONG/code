using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 学生和老师登陆
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnEnter_Click(object sender, EventArgs e)
        {
            if (rbTeacher.Checked == false && rbStudent.Checked == false)
            {
                MessageBox.Show("请选择您的身份再登陆！");
                txtUserName.Clear();
                txtPassWord.Clear();
                txtUserName.Focus();
            }
            else if (rbStudent.Checked == true)
            {
                if (txtUserName.Text == "pengqi1997428" && txtPassWord.Text == "kissyou199")
                {
                    MessageBox.Show("欢迎吴鹏学生登陆！");
                    this.Close();
                }
                else 
                {
                    MessageBox.Show("用户名或密码错误！");
                    txtUserName.Clear();
                    txtPassWord.Clear();
                    txtUserName.Focus();
                    rbStudent.Checked = false;
                }
            }
            else 
            {
                if (txtUserName.Text == "admin" && txtPassWord.Text == "admin") 
                {
                    MessageBox.Show("欢迎老师登陆！");
                    this.Close();
                }
                else
                {
                    MessageBox.Show("用户名或密码错误！");
                    txtUserName.Clear();
                    txtPassWord.Clear();
                    txtUserName.Focus();
                    rbTeacher.Checked = false;
                }
            }
        }


    }
}
