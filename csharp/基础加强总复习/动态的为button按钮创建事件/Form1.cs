using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 动态的为button按钮创建事件
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Button btn = new Button();
            btn.Size = new Size(75, 23);
            btn.Location = new Point(222, 98);

            btn.Click += btn_Click;

            this.Controls.Add(btn);


        }

        void btn_Click(object sender, EventArgs e)
        {
            MessageBox.Show("哈哈哈");
        }
    }

    public class Test 
    {
        public void test() 
        {
            Button btn = new Button();
            btn.Click += btn_Click;
        }

        void btn_Click(object sender, EventArgs e)
        {
            throw new NotImplementedException();
        } 
    }
}
