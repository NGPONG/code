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

namespace 递归实现资源管理器
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string path = @"C:\Users\Administrator\Desktop\test";
            GetDirectoryOrFileName(path, treeView1.Nodes);

        }

        private void GetDirectoryOrFileName(string path, TreeNodeCollection tnc) 
        {
            string[] directoryNames = Directory.GetDirectories(path);
            string[] fileNames = Directory.GetFiles(path);

            for (int i = 0; i < directoryNames.Length; i++)
            {
                string dName = Path.GetFileNameWithoutExtension(directoryNames[i]);
                //把文件夹名字添加根节点
                //并返回添加进根节点的子节点
                TreeNode tnDirectory = tnc.Add(dName);


                //通过递归的算法
                //再次查找该文件夹目录下的文件夹
                GetDirectoryOrFileName(directoryNames[i],tnDirectory.Nodes);
            }

            for (int i = 0; i < fileNames.Length; i++)
            {
                string fName = Path.GetFileNameWithoutExtension(fileNames[i]);
                TreeNode tnFile = tnc.Add(fName);
                tnFile.Tag = fileNames[i];
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string filePath = treeView1.SelectedNode.Tag.ToString();
                textBox1.Text = File.ReadAllText(filePath, Encoding.Default);
            }
            catch 
            {
            
            }
        }
    }
}
