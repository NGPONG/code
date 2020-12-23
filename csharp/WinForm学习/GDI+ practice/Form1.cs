using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GDI__practice
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //基本需要：人、笔（刷子-颜色）、画纸
            //特殊需要：两点

            //人、画纸
            Graphics gra = this.CreateGraphics();
            //笔（刷子-颜色）
            Pen pen = new Pen(Brushes.Black);

            //两点
            Point p1 = new Point(50, 50);
            Point p2 = new Point(250, 250);

            //画线
            gra.DrawLine(pen, p1, p2);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ////基本需要：人、笔（刷子-颜色）、画纸
            ////特殊需要：矩形对象
            ////人、画纸
            //Graphics gra = this.CreateGraphics();
            ////笔（刷子-颜色）
            //Pen pen = new Pen(Brushes.Black);
            ////坐标：x、y
            //Point point = new Point(100, 100);
            ////大小：宽、高
            //Size size = new Size(200, 200);
            ////创建矩形对象需要：坐标、大小
            //Rectangle rec = new Rectangle(point, size);

            ////画矩形
            //gra.DrawRectangle(pen, rec);


            //基本需要：人、笔（刷子-颜色）、画纸
            //特殊需要：长、宽、坐标

            //人、画纸
            Graphics gra = this.CreateGraphics();
            //笔（刷子-颜色）
            Pen pen = new Pen(Brushes.Black);

            //画矩形
            gra.DrawRectangle(pen, 100, 100, 200, 200);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            ////基本需要：人、刷子-颜色、画纸
            ////特殊需要：长、宽、坐标

            ////人、画纸
            //Graphics gra = this.CreateGraphics();
            ////刷子-颜色
            //Brush brushes = Brushes.Red;
            ////坐标：x、y
            //Point point = new Point(100,100);
            ////大小：长、宽
            //Size size = new Size(200,200);
            ////创建矩形对象需要：坐标、大小
            //Rectangle rec = new Rectangle(point,size);

            ////填充矩形
            //gra.FillRectangle(brushes, rec);

            //基本需要：人、刷子-颜色、画纸
            //特殊需要：长、宽、坐标

            //人、画纸
            Graphics gra = this.CreateGraphics();
            //刷子-颜色
            Brush brushes = Brushes.Yellow;

            //填充矩形
            gra.FillRectangle(brushes, 100, 100, 200, 200);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //基本需要：人、刷子-颜色、画纸
            //特殊需要：文本内容、字体、坐标

            //人、画纸
            Graphics gra = this.CreateGraphics();
            //刷子-颜色
            Brush brushes = Brushes.Red;
            //文本内容
            string str = "GDI+++++";
            //字体
            Font font = new Font("微软雅黑", 20, FontStyle.Bold);
            //坐标：x、y
            Point point = new Point(250, 250);

            //画文本
            gra.DrawString(str, font, brushes, point);

        }




    }
}
