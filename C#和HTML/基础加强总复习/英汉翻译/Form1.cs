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

namespace 英汉翻译
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        string[] strTranslate;
        Dictionary<string, string> dic = new Dictionary<string, string>();
        private void Form1_Load(object sender, EventArgs e)
        {
            strTranslate = File.ReadAllLines(@"english.txt",Encoding.Default);

            for (int i = 0; i < strTranslate.Length; i++)
            {
                string[] strTemp = strTranslate[i].Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                if (dic.ContainsKey(strTemp[0]))
                {
                    string temp = dic[strTemp[0]];
                    temp = temp + "\t" + strTemp[1];
                    dic[strTemp[0]] = temp;
                }
                else 
                {
                    dic.Add(strTemp[0], strTemp[1]);
                }
            }
        }

        private void btnTranslate_Click(object sender, EventArgs e)
        {
            if (!dic.ContainsKey(textBox1.Text))
            {
                textBox2.Text = textBox1.Text;
            }
            else 
            {
                textBox2.Text = dic[textBox1.Text];
            }
        }
    }
}
