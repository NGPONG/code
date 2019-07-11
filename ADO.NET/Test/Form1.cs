using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("哈哈", "些许", MessageBoxButtons.YesNo) == DialogResult.Yes) 
            {
                //当对话框单击了Yes，则执行以下代码
                MessageBox.Show("哈哈");
            }

        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            MessageBox.Show("哈哈");
        }
    }
}
