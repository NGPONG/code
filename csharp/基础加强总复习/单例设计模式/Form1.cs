using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 单例设计模式
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (SingleObject.GetSingle().Frm2 == null || SingleObject.GetSingle().Frm2.IsDisposed) 
            {
                SingleObject.GetSingle().Frm2 = new Form2();
                SingleObject.GetSingle().Frm2.Show();
            }
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (SingleObject.GetSingle().Frm3 == null || SingleObject.GetSingle().Frm3.IsDisposed) 
            {
                SingleObject.GetSingle().Frm3 = new Form3();
                SingleObject.GetSingle().Frm3.Show();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (SingleObject.GetSingle().Frm4 == null || SingleObject.GetSingle().Frm4.IsDisposed) 
            {
                SingleObject.GetSingle().Frm4 = new Form4();
                SingleObject.GetSingle().Frm4.Show();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (SingleObject.GetSingle().Frm5 == null || SingleObject.GetSingle().Frm5.IsDisposed)
            {
                SingleObject.GetSingle().Frm5 = new Form5();
                SingleObject.GetSingle().Frm5.Show();
            }
        }
    }
}
