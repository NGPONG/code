using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GDI__验证码
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            Random r = new Random();
            string str = "";
            //产生验证码的随机数
            for (int i = 0; i < 5; i++)
            {
                str += r.Next(0, 10);
            }
            //创建bmp图像对象==>画纸
            //设置bmp图像的长、宽
            Bitmap bmp = new Bitmap(200,30);
            //创建GDI对象==>人
            Graphics gdi = Graphics.FromImage(bmp);

            //产生随机字体，和颜色的数组
            string[] fonts = { "微软雅黑", "宋体", "仿宋", "黑体", "楷体" };
            Brush[] brushes = { Brushes.Black, Brushes.Blue, Brushes.Yellow, Brushes.Red, Brushes.Pink };

            for (int i = 0; i < 5; i++)
            {
                Point poi = new Point(i*35,0);
                gdi.DrawString(str[i].ToString(), new Font(fonts[r.Next(0,5)], 25, FontStyle.Bold), brushes[r.Next(0, 5)], poi);
            }

            Brush brushesPen = brushes[r.Next(0, 5)];
            for (int i = 0; i <25; i++)
            {
                //画线的两点不能超过bmp画纸的长、宽（x、y）
                Point p1 = new Point(r.Next(0,bmp.Width),r.Next(0,bmp.Height));
                Point p2 = new Point(r.Next(0,bmp.Width),r.Next(0,bmp.Height));
                gdi.DrawLine(new Pen(brushesPen),p1,p2);
            }

            for (int i = 0; i < 600; i++)
            {
                //bmp图像画像素点的方法
                bmp.SetPixel(r.Next(0, bmp.Width), r.Next(0, bmp.Height), Color.Black);
            }

            pictureBox1.Image = bmp;
        }
    }
}
