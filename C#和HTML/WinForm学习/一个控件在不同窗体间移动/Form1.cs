using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 一个控件在不同窗体间移动
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Form2 frm2 = new Form2();
        private void button1_Click(object sender, EventArgs e)
        {
            //判断：button1的父容器是否为this窗体
            if (button1.Parent == this)
            {
                //frm2窗体添加button控件
                //button1.Parent = frm2;
                frm2.Controls.Add(button1);
                button1.Text = "我现在在窗体2中";
                frm2.Show();
            }
            else 
            {
                //this窗体添加button控件
                this.Controls.Add(button1);
                button1.Text = "我现在在窗体一中";
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            button1.Text = "我现在在窗体一中";
        }
    }
}
