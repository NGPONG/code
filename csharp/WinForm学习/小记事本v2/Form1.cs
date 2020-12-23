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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }
        /// <summary>
        /// 初始化读取对话框
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //初始化对话框属性
            openFileDialog1.FileName = "";
            openFileDialog1.InitialDirectory = @"C:\Users\Administrator\Desktop";
            openFileDialog1.Title = "请选择文本文件";
            openFileDialog1.Filter = "文本文件|*.txt";
            openFileDialog1.ShowDialog();
        }
        /// <summary>
        /// 初始化保存对话框
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void 另存为ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //初始化对话框属性
            saveFileDialog1.FileName = "*.txt";
            saveFileDialog1.InitialDirectory = @"C:\Users\Administrator\Desktop";
            saveFileDialog1.Title = "保存目录";
            saveFileDialog1.Filter = "文本文件|*.txt|所有文件|*.*";
            saveFileDialog1.ShowDialog();
        }
        /// <summary>
        /// 读取文件内容
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            string str = "";
            using (FileStream fsRead = new FileStream(openFileDialog1.FileName, FileMode.OpenOrCreate, FileAccess.Read))
            {
                byte[] byt = new byte[1024 * 1024 * 5];
                int i = fsRead.Read(byt, 0, byt.Length);
                str = Encoding.Default.GetString(byt, 0, i);
            }
            textBox1.Text = str;
        }
        /// <summary>
        /// 保存文件内容
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void saveFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            //保存文件内容
            using (FileStream fsWrite = new FileStream(saveFileDialog1.FileName, FileMode.Create, FileAccess.Write)) 
            {
                byte[] byt = Encoding.Default.GetBytes(textBox1.Text);
                fsWrite.Write(byt, 0, byt.Length);
            }
        }
        /// <summary>
        /// 自动换行
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void 自动换行ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (textBox1.WordWrap == false) 
            {
                textBox1.WordWrap = true;
                自动换行ToolStripMenuItem.Text = "取消自动换行";
            }
            else
            {
                textBox1.WordWrap = false;
                自动换行ToolStripMenuItem.Text = "自动换行";
            }
        }
        /// <summary>
        /// 字体格式初始化
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void 字体格式ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            fontDialog1.ShowDialog();
            textBox1.Font = fontDialog1.Font;
        }
        /// <summary>
        /// 字体颜色初始化
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void 颜色样式ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            colorDialog1.ShowDialog();
            textBox1.ForeColor = colorDialog1.Color;
        }

        private void 图片查看器ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 frm2 = new Form2();
            frm2.Show();
        }

    }
}
