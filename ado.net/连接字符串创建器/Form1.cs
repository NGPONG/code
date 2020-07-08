using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 连接字符串创建器
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            SqlConnectionStringBuilder scsb = new SqlConnectionStringBuilder();
            propSqlConnection.SelectedObject = scsb;
        }

        private void btnGetString_Click(object sender, EventArgs e)
        {
            //当我们在窗体中更改了propSqlConnection对象所指向的对象的属性的时候
            //该对象属性的值也会发生改变
            textBox1.Text = propSqlConnection.SelectedObject.ToString();

            //粘贴板
            Clipboard.Clear();
            Clipboard.SetText(textBox1.Text);

            MessageBox.Show(textBox1.Text);

        }
    }
    public class Test 
    {
        public int Age { get; set; }
        public string Name { get; set; }
        public char Gender { get; set; }
    }
}
