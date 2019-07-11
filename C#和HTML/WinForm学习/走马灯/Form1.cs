using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 走马灯
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            lblLight.Text = lblLight.Text.Substring(lblLight.Text.Length - 1) + lblLight.Text.Substring(0, lblLight.Text.Length - 1);
        }
    }
}
