using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 四则运算器
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.Items.AddRange(new string[] { "+", "-", "*", "/" });
            comboBox1.SelectedIndex = 0;
        }
        private void btnResult_Click(object sender, EventArgs e)
        {
            double number1 = 0;
            double number2 = 0;
            double sum = 0;
            if (double.TryParse(textNumber1.Text.Trim(), out number1) == false) 
            {
                MessageBox.Show("您的输入有误！");
                textNumber1.Clear();
                textNumber2.Clear();
                textNumber1.Focus();
            }
            else if (double.TryParse(textNumber2.Text.Trim(), out number2)==false)
            {
                MessageBox.Show("您的输入有误！");
                textNumber1.Clear();
                textNumber2.Clear();
                textNumber1.Focus();
            }
            else 
            {
                switch (comboBox1.SelectedItem.ToString()) 
                {
                    case "+":
                        sum = number1 + number2;
                        break;
                    case "-":
                        sum = number1 - number2;
                        break;
                    case "*":
                        sum = number1 * number2;
                        break;
                    case "/":
                        sum = number1 / number2;
                        break;
                }
                textResult.Text = sum.ToString();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textNumber1.Clear();
            textNumber2.Clear();
            textResult.Clear();
            textNumber1.Focus();
        }
    }
}
