using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GDI__practice_03
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            string str = "";
            Random r = new Random();
            for (int i = 0; i < 6; i++)
            {
                str += r.Next(0,10);
            }
            
            Bitmap bmp = new Bitmap(200,30);
            Graphics gra = Graphics.FromImage(bmp);

            string[] fonts = { "微软雅黑", "宋体", "仿宋", "黑体", "楷体" };
            Brush[] brushes = { Brushes.Black, Brushes.Blue, Brushes.Red, Brushes.Green, Brushes.Yellow, Brushes.Pink, Brushes.Ivory };

            for (int i = 0; i < str.Length; i++)
            {
                gra.DrawString(str[i].ToString(),new Font(fonts[r.Next(0,fonts.Length)],25,FontStyle.Bold),brushes[r.Next(0,brushes.Length)],new Point(i*35,0));
            }

            for (int i = 0; i < 25; i++)
            {
                gra.DrawLine(new Pen(brushes[r.Next(0, brushes.Length)]), new Point(r.Next(0, bmp.Width), r.Next(0, bmp.Height)), new Point(r.Next(0, bmp.Width), r.Next(0, bmp.Height)));
            }
            for (int i = 0; i < 300; i++)
            {
                bmp.SetPixel(r.Next(0, bmp.Width), r.Next(0, bmp.Height), Color.Black);
            }
            pictureBox1.Image = bmp;
        }
    }
}
