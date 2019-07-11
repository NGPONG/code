using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GDI__绘制坐标图
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            this.Text = string.Format("X轴：{0}  Y轴{1}",e.Location.X,e.Location.Y);
            //x = 137,y= 475
        }
        Point zero_Point = new Point(145, 475);
        private void button1_Click(object sender, EventArgs e)
        {
            Graphics gra = this.CreateGraphics();
            Pen pe = new Pen(Brushes.Black);

            //定义 笔 画的直线的结束样式
            pe.EndCap =  System.Drawing.Drawing2D.LineCap.DiamondAnchor;

            gra.DrawLine(pe, zero_Point, new Point(730, zero_Point.Y));

            //循环12次画刻度，画文本
            for (int i = 1; i < 13; i++)
            {
                gra.DrawLine(new Pen(Brushes.Black), new Point(zero_Point.X + i * 43, zero_Point.Y), new Point(zero_Point.X + i * 43, zero_Point.Y - 5));
                gra.DrawString(i + "月", this.Font, Brushes.Black, new Point(zero_Point.X + i * 43 -7, zero_Point.Y + 10));
            }

            gra.DrawString("月份", this.Font, Brushes.Black, new Point(720, zero_Point.Y + 10));

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Graphics gra = this.CreateGraphics();

            Pen pe = new Pen(Brushes.Black);
            pe.EndCap = System.Drawing.Drawing2D.LineCap.DiamondAnchor;

            gra.DrawLine(pe, zero_Point, new Point(zero_Point.X, 40));

            for (int i =1; i < 11; i++)
            {
                gra.DrawLine(new Pen(Brushes.Black), new Point(zero_Point.X, zero_Point.Y - i * 40), new Point(zero_Point.X + 5, zero_Point.Y - i * 40));
                gra.DrawString(i + "0", this.Font, Brushes.Black, new Point(zero_Point.X - 20, zero_Point.Y - i * 40 -7));
            }

            gra.DrawString("销售额：单位(万元)", this.Font, Brushes.Black, new Point(15,35));
        }

        List<PointF> list = new List<PointF>();
        private void button3_Click(object sender, EventArgs e)
        {
            float[] floats = { 66.3f, 43.3f, 77.8f, 88.1f, 29.8f, 55.7f, 48.5f, 56.3f, 38.6f, 12.4f, 68.4f, 55.1f };
            Graphics gra = this.CreateGraphics();
            for (int i = 0; i < floats.Length; i++)
            {
                Point p = (new Point(zero_Point.X + (i + 1) * 43-2, zero_Point.Y - (int)floats[i]*4));
                Size sz = new Size(2, 2);
                gra.DrawEllipse(new Pen(Brushes.Black),new Rectangle(p,sz));
                list.Add(p);
            }
            for (int i = 0; i < list.Count; i++)
            {
                if (i == 11) 
                {
                    break;
                }
                gra.DrawLine(new Pen(Brushes.Black), list[i], list[i + 1]);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Graphics gra = this.CreateGraphics();
            Font ft = new Font("微软雅黑",20,FontStyle.Bold);
            gra.DrawString("某工厂某产品年度销售额图表",ft,Brushes.Red,new Point(zero_Point.X+100,25));
        }


    }
}
