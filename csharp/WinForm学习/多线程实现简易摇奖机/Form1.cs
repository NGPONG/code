using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 多线程实现简易摇奖机
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Control.CheckForIllegalCrossThreadCalls = false;
            label1.Text = "0";
            label2.Text = "0";
            label3.Text = "0";
            label4.Text = "0";
        }

        bool flag = true;
        private void button1_Click(object sender, EventArgs e)
        {
            Thread td = new Thread(GetNumber);
            td.IsBackground = true;
            td.Start();
        }
        public void GetNumber() 
        {
            Random r = new Random();

            if (button1.Text == "Start")
            {
                button1.Text = "Stop";
                flag = false;
            }
            else
            {
                button1.Text = "Start";
                flag = true;
            }

            while (flag != true)
            {
                label1.Text = r.Next(0, 10).ToString();
                label2.Text = r.Next(0, 10).ToString();
                label3.Text = r.Next(0, 10).ToString();
                label4.Text = r.Next(0, 10).ToString();
            }
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            this.Text = string.Format("x:{0}  y:{1}", e.X, e.Y);
        }
    }
}
