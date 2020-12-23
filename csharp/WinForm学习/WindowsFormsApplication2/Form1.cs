using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            lblTime.Text = DateTime.Now.ToString();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            lblTime.Visible = false;
        }

        private void btnGetTime_Click(object sender, EventArgs e)
        {
            if (lblTime.Visible == false) 
            {
                lblTime.Visible = true;
                btnGetTime.Text = "取消获取当前时间";
                lblTime.Text = DateTime.Now.ToString();
            }
            else 
            {
                lblTime.Visible = false;
                btnGetTime.Text = "获取当前时间";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;
        }
    }
}
