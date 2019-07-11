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
    //申明一个没有返回值参数为string的委托
    //与需要接收Form1中的方法的签名相同
    public delegate void DelTest(string str);
    public partial class Form2 : Form
    {
        //申明一个委托类型的自动属性 Del
        public DelTest Del
        {
            get;
            set;
        }
        //通过在Form1窗体创建Form2对象的时候调用构造函数
        //给Form2的委托对象的属性进行赋值
        //通过这样的思路可以把Form1中的Private的方法传到Form2窗体中
        public Form2(DelTest del)
        {
            this.Del = del;
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Del(textBox1.Text);
        }
    }
}
