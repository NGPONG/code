using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 委托实现窗体间的传值
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 frm2 = new Form2(GetLable);
            frm2.Show();
        }

        public void GetLable(string str) 
        {
            this.label1.Text = str;
        }
    }
}
