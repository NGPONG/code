using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MDI窗体设计
{
    public partial class Form1 : Form
    {
        //创建Form2、3、4的对象
        Form2 frm2 = new Form2();
        Form3 frm3 = new Form3();
        Form4 frm4 = new Form4();

        public Form1()
        {
            InitializeComponent();
            LayoutMdi(MdiLayout.TileVertical);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //把Form2、3、4 声明为 Form1的子窗体 this=Form1
            frm2.MdiParent = this;
            frm3.MdiParent = this;
            frm4.MdiParent = this;
            //展示Form2、3、4窗体
            frm2.Show();
            frm3.Show();
            frm4.Show();
        }

        private void 纵向排列ToolStripMenuItem2_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileVertical);
        }

        private void 横向排列ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileHorizontal);
        }
    }
}
