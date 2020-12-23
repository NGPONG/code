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
    public partial class ObserverFrm1 : Form
    {
        public ObserverFrm1()
        {
            InitializeComponent();
        }

        public void GetMsgFrm1(string str) 
        {
            this.textBox1.Text = str;
        }
    }
}
