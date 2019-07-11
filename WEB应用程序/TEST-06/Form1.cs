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

namespace TEST_06
{
    public partial class Form1 : Form
    {
        public int Index { get; set; }

        public Form1()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            ThreadPool.SetMaxThreads(6, 6);
            
            for (int i = 0; i < 10; i++)
            {
                ThreadPool.QueueUserWorkItem(DoSomething);
                Thread.Sleep(1000);
            }
        }

        private void DoSomething(object state)
        {
            try
            {
                if (Index == 0)
                {
                    Index++;
                    throw new Exception("哈哈哈");
                }
                else
                {
                    MessageBox.Show("我是线程：" + Thread.CurrentThread.ManagedThreadId.ToString());
                }
            }
            catch (Exception objException)
            {
                MessageBox.Show("我是线程：" + Thread.CurrentThread.ManagedThreadId.ToString() + "，我抛异常了");
                throw new Exception(objException.Message);
            }
        }
    }
}
