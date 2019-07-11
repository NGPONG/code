using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 文件流实现大文件的传输
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //openFileDialog1.FileName = string.Empty;
            openFileDialog1.Title = "请选择文件";
            openFileDialog1.Filter = "所有文件|*.*";

            saveFileDialog1.Title = "请选择保存路径";
            saveFileDialog1.FileName = string.Empty;
            saveFileDialog1.Filter = "所有文件|*.*";

            Control.CheckForIllegalCrossThreadCalls = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            openFileDialog1.ShowDialog();
        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            txtOpen.Text = openFileDialog1.FileName;
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            saveFileDialog1.ShowDialog();
        }

        private void saveFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            txtSave.Text = saveFileDialog1.FileName;
        }

        private void btnSaveSure_Click(object sender, EventArgs e)
        {
            Thread th = new Thread(SaveFile);
            th.IsBackground = true;
            th.Start();
        }

        private void SaveFile() 
        {
            using (FileStream fsRead = new FileStream(openFileDialog1.FileName, FileMode.Open, FileAccess.Read))
            {
                using (FileStream fsWrite = new FileStream(saveFileDialog1.FileName, FileMode.Create, FileAccess.Write))
                {
                    byte[] buff = new byte[1024 * 1024 * 10];
                    progressBar1.Maximum = (int)fsRead.Length;

                    while (true)
                    {
                        int r = fsRead.Read(buff, 0, buff.Length);
                        if (r == 0)
                        {
                            break;
                        }

                        progressBar1.Value = (int)fsWrite.Length;

                        fsWrite.Write(buff, 0, r);
                    }
                }
            }
            MessageBox.Show("保存成功");
        }
    }
}
