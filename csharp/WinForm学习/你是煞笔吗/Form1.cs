using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 你是煞笔吗
{
    public partial class Form1 : Form
    {
        Random r = new Random();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("知道啦知道啦");
            this.Close();
        }

        private void btnNo_MouseEnter(object sender, EventArgs e)
        {
            //获取小窗口能活动的范围，就是大窗口的横向、纵向的高度和宽度 减去窗口的高度和宽度，+1是为了获取最大随机数
            int maxWidth = this.ClientSize.Width - btnNo.Width - 12 + 1;
            int maxHeight = this.ClientSize.Height - btnNo.Height - 12 + 1;

            //给窗口重新赋值一个坐标
            Point poi = new Point(r.Next(12, maxWidth), r.Next(12, maxHeight));
            btnNo.Location = poi;
        }

        private void btnNo_Click(object sender, EventArgs e)
        {
            MessageBox.Show("哇，竟然给你点到了！");
            this.Close();
        }
    }
}
