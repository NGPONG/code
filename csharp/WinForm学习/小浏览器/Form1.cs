using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 小浏览器
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnEnter_Click(object sender, EventArgs e)
        {
            if (textWeb.Text.Contains("http://"))
            {
                webBrowser1.Url = new Uri(textWeb.Text);
            }
            else 
            {
                //改变网页地址
                //简写
                webBrowser1.Url = new Uri("http://" + textWeb.Text);
            }
        }
    }
}
