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

namespace WinForm跨线程访问
{
    public delegate void _InvokeHandler();
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            // 取消跨线程访问检测机制
            Control.CheckForIllegalCrossThreadCalls = false;
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            Thread myThread = new Thread(() =>
            {
                while (true)
                {
                    // 当前控件是否由非UI线程在操作
                    if (this.textBox1.InvokeRequired)
                    {
                        // 找到创建调用Invoke的线程并执行指定的函数
                        this.Invoke(new _InvokeHandler(() =>
                        {
                            Thread.Sleep(100);
                            int count = Convert.ToInt32(textBox1.Text);
                            textBox1.Text = (++count).ToString();
                            Application.DoEvents();
                        }));
                    }
                }
            });
            myThread.Start();
        }
         
        private void Button2_Click(object sender, EventArgs e)
        {
            if (!this.textBox1.InvokeRequired)
            {
                this.textBox1.Text = "321";
            }
        }
    }
}
