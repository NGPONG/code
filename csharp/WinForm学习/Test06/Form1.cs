using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test06
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //Thread td = new Thread(Test);
        private void Form1_Load(object sender, EventArgs e)
        {

            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Graphics gra = this.CreateGraphics();
            gra.DrawRectangle(new Pen(Brushes.Black), new Rectangle(new Point(80, 90), new Size(70, 70)));
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics gra = e.Graphics;
            gra.DrawRectangle(new Pen(Brushes.Black), new Rectangle(new Point(80, 90), new Size(70, 70)));
            gra.FillRectangle(Brushes.Yellow, new Rectangle(new Point(80, 90), new Size(70, 70)));
        }

        public void Test() 
        {
        
        }
    }
}
