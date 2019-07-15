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

namespace 多线程_Task2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            CancellationTokenSource cts = new CancellationTokenSource();

            // 构建GUI同步上下文线程调度器
            TaskScheduler scheduler = TaskScheduler.FromCurrentSynchronizationContext();

            // 通过该方式可以实现控件的跨线程访问
            Task.Factory.StartNew(() =>
            {
                for (int i = 0; i < 1000; i++)
                {
                    this.textBox1.Text = i.ToString();
                    Thread.Sleep(100);
                    Application.DoEvents();
                }
            }, cts.Token, TaskCreationOptions.None, scheduler);
        }
    }
}
