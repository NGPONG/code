using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 单例模式_只能创建一次对象
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private Form2[] _frm2Single = { null };
        private void button1_Click(object sender, EventArgs e)
        {
            if (_frm2Single[0] == null || _frm2Single[0].IsDisposed) 
            {
                _frm2Single[0] = new Form2();
                _frm2Single[0].Show();
            }
        }
    }
}
