using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        Random r = new Random();
        public int i
        {
            get;
            set;
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            i = r.Next(1000, 9999);
            btnCaptcha.Text = i.ToString();
            btnNewLine.Visible = false;
            btnAbout.Visible = false;
            btnSave.Visible = false;
            textBox1.Visible = false;
        }

        private void btnEnter_Click(object sender, EventArgs e)
        {
            if ((textUserName.Text == "admin" && textPassWord.Text == "admin") && textCaptcha.Text == i.ToString())
            {
                MessageBox.Show("登陆成功！欢迎使用~ ");
                label1.Visible = false;
                label2.Visible = false;
                label3.Visible = false;
                textUserName.Visible = false;
                textPassWord.Visible = false;
                textCaptcha.Visible = false;
                btnCaptcha.Visible = false;
                btnEnter.Visible = false;
                btnNewLine.Visible = true;
                btnAbout.Visible = true;
                btnSave.Visible = true;
                textBox1.Visible = true;
            }
            else if (textUserName.Text != "admin" && textPassWord.Text != "admin")
            {
                MessageBox.Show("用户名或密码错误！请重新输入！");
                textUserName.Clear();
                textPassWord.Clear();
                textCaptcha.Clear();
                btnCaptcha.Text = "";
                i = r.Next(1000, 9999);
                btnCaptcha.Text = i.ToString();
                textUserName.Focus();
            }
            else if (textCaptcha.Text != i.ToString())
            {
                MessageBox.Show("验证码错误！请重新输入！\a");
                textCaptcha.Clear();
                i = r.Next(1000, 9999);
                btnCaptcha.Text = i.ToString();
                textCaptcha.Focus();
            }

        }

        private void btnCaptcha_Click(object sender, EventArgs e)
        {
            i = r.Next(1000, 9999);
            btnCaptcha.Text = i.ToString();
            textUserName.Focus();
        }

        private void btnAbout_Click(object sender, EventArgs e)
        {
            MessageBox.Show("记事本程序 v1.0\n版权：吴鹏");
        }

        private void btnNewLine_Click(object sender, EventArgs e)
        {
            if (textBox1.WordWrap == false)
            {
                textBox1.WordWrap = true;
                btnNewLine.Text = "取消自动换行";
            }
            else 
            {
                textBox1.WordWrap = false;
                btnNewLine.Text = "自动换行";
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            MessageBox.Show("保存成功！目录为桌面的new.txt");
            using (FileStream fsWrite = new FileStream(@"C:\Users\Administrator\Desktop\new.txt", FileMode.Create, FileAccess.Write)) 
            {
                byte[] byt = Encoding.Default.GetBytes(textBox1.Text);
                fsWrite.Write(byt, 0, byt.Length);
            }
        }







    }
}
