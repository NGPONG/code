using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GDI__practice_02
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Graphics gra = this.CreateGraphics();
            gra.DrawLine(new Pen(Brushes.Black), new Point(40, 40), new Point(300, 300));
        }
        private void button2_Click(object sender, EventArgs e)
        {
            Graphics gra = this.CreateGraphics();
            gra.DrawRectangle(new Pen(Brushes.Black), new Rectangle(new Point(40, 40), new Size(260, 260)));
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Graphics gra = this.CreateGraphics();
            gra.FillRectangle(Brushes.Yellow, new Rectangle(new Point(40, 40), new Size(260, 260)));
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Graphics gra = this.CreateGraphics();
            gra.DrawString("大家好！！",new Font("微软雅黑",30,FontStyle.Bold),Brushes.Red,new Point(400,400));
        }

        private void button5_Click(object sender, EventArgs e)
        {
            //基本需要：人、笔（刷子-颜色）、画纸
            //特殊需要：在自己定义的矩形大小内绘制圆形
            //人、画纸
            Graphics gra = this.CreateGraphics();
            //笔（刷子-颜色）
            Pen pe = new Pen(Brushes.Red);
            //定义矩形的坐标、大小
            Point pt = new Point(20,20);
            Size sz = new Size(200,200);
            //定义一个矩形对象
            Rectangle rec = new Rectangle(pt, sz);
            //在定义的矩形大小内绘制一个圆形
            gra.DrawEllipse(pe, rec);

            gra.DrawRectangle(pe, rec);
            

        }
    }
}
