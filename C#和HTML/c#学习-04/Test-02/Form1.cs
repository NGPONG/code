using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test_02
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            Thread myThread = new Thread(() =>
            {
                int i = 1;
                Thread myThread2 = new Thread(()=> 
                {
                    Thread.Sleep(5000);
                    string value = "123123";
                });
                myThread2.Start();
                myThread2.Join(4000);
                string str = "123";
            });
            myThread.Start();


            while (true)
            {
                string value = "1";
                continue;
            }
        }
    }
}
