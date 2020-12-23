using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TreeView控件
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            treeView1.Nodes.Add("我被添加进去了哟");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            TreeNode tn = new TreeNode("123");
            treeView1.SelectedNode = tn;

            //获取当前选中的节点，再获取当前选中节点的集合，然后添加新的子节点
            treeView1.SelectedNode.Nodes.Add("哈哈哈");

        }
    }
}
