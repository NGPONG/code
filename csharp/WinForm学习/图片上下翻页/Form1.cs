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

namespace 图片上下翻页
{
    public partial class Form1 : Form
    {
        string[] _str;
        int i = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            i++;
            if (i == _str.Length)
            {
                i = 0;
                pictureBox1.Image = Image.FromFile(_str[i]);
            }
            else 
            {
                pictureBox1.Image = Image.FromFile(_str[i]);
            }
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            _str = Directory.GetFiles(@"C:\Users\Administrator\Desktop\New");
            pictureBox1.SizeMode = PictureBoxSizeMode.CenterImage;
            pictureBox1.Image = Image.FromFile(_str[0]);
        }

        private void btnLast_Click(object sender, EventArgs e)
        {
            i--;
            if (i < 0)
            {
                i = _str.Length -1;
                pictureBox1.Image = Image.FromFile(_str[i]);
            }
            else
            {
                pictureBox1.Image = Image.FromFile(_str[i]);
            }
        }
    }
}
