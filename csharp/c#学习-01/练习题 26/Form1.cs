using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 练习题_26
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.Items.AddRange(new string[] { "请选择", "+", "-", "*", "/" });
            comboBox1.SelectedIndex = 0;
            button1.Text = "=";
            label1.Visible = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label1.Visible = true;
            try
            {
                double i = double.Parse(textBox1.Text);
                double n = double.Parse(textBox2.Text);
                double sum = 0;
                string str = (string)comboBox1.SelectedItem;
                switch (str)
                {
                    case "+":
                        sum = i + n;
                        label1.Text = sum.ToString();
                        break;
                    case "-":
                        sum = i - n;
                        label1.Text = sum.ToString();
                        break;
                    case "*":
                        sum = i * n;
                        label1.Text = sum.ToString();
                        break;
                    case "/":
                        sum = i / n;
                        label1.Text = sum.ToString();
                        break;
                    default:
                        MessageBox.Show("请选择计算类型");
                        break;
                }
            }
            catch 
            {
                MessageBox.Show("请输入正确的数字");
            }
        }
    }
}
