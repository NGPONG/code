using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 委托案例_实现窗体之间的传值
{
    
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            //创建Form2对象的时候调用构造函数
            //通过构造函数把方法传给Form2
            Form2 frm2 = new Form2(GetLable);
            frm2.Show();
        }
        private void GetLable(string str) 
        {
            this.label1.Text = str;
        }
    }
}
