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
    public delegate void DelSend(string str);
    public partial class Form2 : Form
    {
        public DelSend Del { get; set; }
        public Form2(DelSend del)
        {
            this.Del = del;
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Del(textBox1.Text.Trim());
        }


    }
}
