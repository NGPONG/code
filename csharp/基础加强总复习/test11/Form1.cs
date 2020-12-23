using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace test11
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            MessageBox.Show("hello world" + this.timer1.Enabled);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.timer1.Start();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.timer1.Stop();
            MessageBox.Show(this.timer1.Enabled.ToString());
        }
    }
}
