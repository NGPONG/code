using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 输入事件的使用
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            lblWrite.Text = textWrite.Text;
        }

        private void textWrite_TextChanged(object sender, EventArgs e)
        {
            lblWrite.Text = textWrite.Text;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            lblWrite.Text = textWrite.Text;
        }


    }
}
