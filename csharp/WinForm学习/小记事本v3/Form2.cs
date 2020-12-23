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

namespace 小记事本v3
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            openFileDialog1.FileName = "";
            openFileDialog1.Multiselect = true;
            openFileDialog1.Title = "打开";
            openFileDialog1.Filter = "图片|*.jpg|所有文件|*.*";
            openFileDialog1.InitialDirectory = @"C:\Users\Administrator\Desktop";

            openFileDialog1.ShowDialog();
        }
        List<string> list = new List<string>();
        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            list.AddRange(openFileDialog1.FileNames);
            for (int i = 0; i < openFileDialog1.FileNames.Length; i++)
            {
                listBox1.Items.Add(Path.GetFileName(openFileDialog1.FileNames[i]));
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            pictureBox1.Image = Image.FromFile(list[listBox1.SelectedIndex]);
        }
    }
}
