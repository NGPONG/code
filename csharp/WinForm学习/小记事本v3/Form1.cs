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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            panel1.Visible = false;
        }
        private void 打开纪录ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            panel1.Visible = true;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            panel1.Visible = false;
        }
        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //初始化打开对话框
            openFileDialog1.FileName = "";
            openFileDialog1.InitialDirectory = @"C:\Users\Administrator\Desktop";
            openFileDialog1.Title = "打开";
            openFileDialog1.Filter = "文本文件|*.txt|所有文件|*.*";
            //打开对话框
            openFileDialog1.ShowDialog();
        }
        List<string> list = new List<string>();
        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            listBox1.Items.Add(Path.GetFileName(openFileDialog1.FileName));
            list.Add(openFileDialog1.FileName);
            using (FileStream fsRead = new FileStream(openFileDialog1.FileName, FileMode.OpenOrCreate, FileAccess.Read)) 
            {
                byte[] byt = new byte[1024 * 1024 * 5];
                int i = fsRead.Read(byt, 0, byt.Length);
                textBox1.Text =  Encoding.Default.GetString(byt, 0, i);
            }
        }
        //清空
        private void button2_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            textBox1.Text = "";
        }
        //保存对话框初始化
        private void 另存为ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveFileDialog1.FileName = "";
            saveFileDialog1.InitialDirectory = @"C:\Users\Administrator\Desktop";
            saveFileDialog1.Title = "保存路径";
            saveFileDialog1.Filter = "文本文件|*.txt|所有文件|*.*";

            saveFileDialog1.ShowDialog();
        }
        //保存文件
        private void saveFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            using (FileStream fsWrite = new FileStream(saveFileDialog1.FileName, FileMode.Create, FileAccess.Write)) 
            {
                fsWrite.Write(Encoding.Default.GetBytes(textBox1.Text),0, Encoding.Default.GetBytes(textBox1.Text).Length);
            }
        }
        //打开文件
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex != -1)
            {
                using (FileStream fsRead = new FileStream(list[listBox1.SelectedIndex], FileMode.OpenOrCreate, FileAccess.Read))
                {
                    byte[] byt = new byte[1024 * 1024 * 5];
                    int i = fsRead.Read(byt, 0, byt.Length);
                    string str = Encoding.Default.GetString(byt, 0, i);
                    textBox1.Text = str;
                }
            }
            else
            {
                MessageBox.Show("未知错误");
            }
        }

        private void 字体格式ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            fontDialog1.ShowDialog();
            textBox1.Font = fontDialog1.Font;
        }

        private void 字体颜色ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            colorDialog1.ShowDialog();
            textBox1.ForeColor = colorDialog1.Color;
        }

        private void 自动换行ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (textBox1.WordWrap == false)
            {
                自动换行ToolStripMenuItem.Text = "取消自动换行";
                textBox1.WordWrap = true;
            }
            else 
            {
                自动换行ToolStripMenuItem.Text = "自动换行";
                textBox1.WordWrap = false;
            }
        }

        private void 图片查看器ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 frm2 = new Form2();
            frm2.Show();
        }

    }
}
