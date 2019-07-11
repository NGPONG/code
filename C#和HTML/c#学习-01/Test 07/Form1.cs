using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test_07
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            this.Text = string.Format("X：{0}\tY：{1}", e.X, e.Y);
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show(comboBox1.SelectedIndex.ToString());

            //获取或赋值用户选择菜单栏内容的Items集合里元素的下标
            //什么都没选为：-1
            comboBox1.SelectedIndex = 0;

            //获取或赋值用户选择选择列表栏内容的Items集合里元素的下标
            //什么都没选为：-1
            listBox1.SelectedIndex = 0;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string str = "";
            //通过Parse把字符串转换成IP类型
            IPAddress ip = IPAddress.Parse(str);

            IPEndPoint port = new IPEndPoint(ip, 55000);

            Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);


        }

        
    }
}
