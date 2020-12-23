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

namespace 小记事本v2
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //初始化选择对话框
            openFileDialog1.FileName = "";
            openFileDialog1.Multiselect = true;
            openFileDialog1.InitialDirectory = @"C:\Users\Administrator\Desktop";
            openFileDialog1.Title = "请选择图片";
            openFileDialog1.Filter = "图片文件|*.jpg|所有文件|*.*";
            openFileDialog1.ShowDialog();
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
        }
        string[] str;
        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            str = openFileDialog1.FileNames;
            for (int i = 0; i < str.Length; i++)
            {
                listBox1.Items.Add(Path.GetFileName(str[i]));
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(str[listBox1.SelectedIndex]);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }
    }
}
