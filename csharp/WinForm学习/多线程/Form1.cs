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

namespace 多线程
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            //取消VS对跨线程访问的检测
            Control.CheckForIllegalCrossThreadCalls = false;
        }
        Thread td;
        private void button1_Click(object sender, EventArgs e)
        {
            td = new Thread(Test);
            td.IsBackground = true;
            td.Start();
            
        }
        public void Test() 
        {
            for (int i = 0; i < 100000; i++)
            {
                textBox1.Text = i.ToString();
            }
            //MessageBox.Show("啊速度加速度");
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (td != null)                     //当子线程关闭的时候为nulll
            {                                        //判断子线程是否为null，也就是已是否关闭
                td.Abort();                    //如果 不等于 null，那我们手动关闭线程
            }
        }
    }
}
