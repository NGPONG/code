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

namespace 对话框选择图片
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // 设置对话框的初始值
            openFileDialog1.ShowHelp = true;
            openFileDialog1.Title = "请选择文件";
            openFileDialog1.Multiselect = true;
            openFileDialog1.InitialDirectory = @"C:\Users\Administrator\Desktop";
            openFileDialog1.Filter = "所有文件|*.*";
            openFileDialog1.FileName = null;
            //显示对话框
            openFileDialog1.ShowDialog();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //隐藏列表
            listBox1.Visible = false;
        }

        private void openFileDialog1_HelpRequest(object sender, EventArgs e)
        {
            MessageBox.Show("太偷懒了，帮助还没做。。。");
        }
        string[] str;
        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            //获取打开文件的全路径
            str = openFileDialog1.FileNames;
            //显示列表
            listBox1.Visible = true;
            //为列表添加元素
            for (int i = 0; i < str.Length; i++)
            {
                listBox1.Items.Add(Path.GetFileName(str[i]));
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(str[listBox1.SelectedIndex]);
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
        }

    }
}
