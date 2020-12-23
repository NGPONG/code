using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 图片时间上下翻页
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        string[] str;
        Random r = new Random();
        private void Form1_Load(object sender, EventArgs e)
        {
            str = Directory.GetFiles(@"C:\Users\Administrator\Desktop\new");
            //设置图片规格为居中
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox2.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox3.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox4.SizeMode = PictureBoxSizeMode.StretchImage;
            //设置4哥图片控件的初始图片
            pictureBox1.Image = Image.FromFile(str[r.Next(0, str.Length)]);
            pictureBox2.Image = Image.FromFile(str[r.Next(0, str.Length)]);
            pictureBox3.Image = Image.FromFile(str[r.Next(0, str.Length)]);
            pictureBox4.Image = Image.FromFile(str[r.Next(0, str.Length)]);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(str[r.Next(0, str.Length)]);
            pictureBox2.Image = Image.FromFile(str[r.Next(0, str.Length)]);
            pictureBox3.Image = Image.FromFile(str[r.Next(0, str.Length)]);
            pictureBox4.Image = Image.FromFile(str[r.Next(0, str.Length)]);
        }
    }
}
