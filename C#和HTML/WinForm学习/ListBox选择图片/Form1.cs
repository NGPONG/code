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

namespace ListBox选择图片
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        string[] fileArrary;
        private void Form1_Load(object sender, EventArgs e)
        {
            //获取文件路径
            fileArrary = Directory.GetFiles(@"C:\Users\Administrator\Desktop\New");
            //给listbox数组添加元素
            for (int i = 0; i < fileArrary.Length; i++)
            {
                listBox1.Items.Add(Path.GetFileName(fileArrary[i]));
            }
            //初始化界面
            listBox1.SelectedIndex = 0;
            pictureBox1.Image = Image.FromFile(fileArrary[0]);
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            ////通过循环判断字符串
            //for (int i = 0; i <fileArrary.Length ; i++)
            //{
            //    if (fileArrary[i].Contains(listBox1.SelectedItem.ToString())) 
            //    {
            //        pictureBox1.Image = Image.FromFile(fileArrary[i]);
            //    }
            //}

            //通过下标
            pictureBox1.Image = Image.FromFile(fileArrary[listBox1.SelectedIndex]);

        }
    }
}
