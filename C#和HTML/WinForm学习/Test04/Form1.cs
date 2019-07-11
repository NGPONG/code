using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test04
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            openFileDialog1.Multiselect = true;
            openFileDialog1.ShowDialog();

            MessageBox.Show(openFileDialog1.FileName);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Graphics gra = this.CreateGraphics();
            gra.DrawLine(new Pen(Brushes.Blue), new Point(50, 50), new Point(150, 150));

        }
        int i = 1;
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            i++;
            label1.Text = i.ToString();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }
    }
}
