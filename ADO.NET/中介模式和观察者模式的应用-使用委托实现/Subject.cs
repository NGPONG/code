using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 中介模式和观察者模式的应用_使用委托实现
{
    public delegate void DelGetMsg(string str);
    public partial class Subject : Form
    {
        public DelGetMsg del;
        public Subject()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            del(this.textBox1.Text);
        }
    }
}
