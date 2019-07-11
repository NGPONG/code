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
using ProFactory;
using ProOperation;

namespace ProCalculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] strs = File.ReadAllLines("Config.txt");
            int x = 65;
            int y = 157;
            for (int i = 0; i < strs.Length; i++)
            {
                //65, 157   75,23
                Button btn = new Button();
                btn.Location = new Point(x, y);
                btn.Size = new Size(75, 23);
                btn.Text = strs[i];
                btn.Click += btn_Click;
                this.Controls.Add(btn);
                x += 80;
            }
        }

        /// <summary>
        /// 点击控件后，输出结果至 lable1
        /// </summary>
        /// <param name="sender">当前触发事件的对象</param>
        /// <param name="e"></param>
        void btn_Click(object sender, EventArgs e)
        {
            Button btn = sender as Button;
            int numberone = int.Parse(textBox1.Text);
            int numbertwo = int.Parse(textBox2.Text);

            Operation oper = Factory.GetOper(btn.Text, numberone, numbertwo);
            label1.Text = oper.GetResult().ToString();
        }
    }
}
